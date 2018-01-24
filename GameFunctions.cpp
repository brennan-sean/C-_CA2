#include <iostream>
#include <string>
#include <fstream>
#include <sstream>   
#include "GameFunctions.h"

void GameFunctions::savePlayer(ActorOb& player)
{
    ofstream playerWriter;
    string playerData;

    string roomPos = to_string(player.getRoom()); 
    int itemCount = player.getItemCount(); //Checking does the player have any items

    if (itemCount > 0)   
    {
        playerWriter.open(PLAYER_FILE);
        for (int idx = 0; idx < itemCount; idx++) 
        {
            ThingOb tmpThing = player.getThingAtIndex(idx); //Get the thins position in the list for the index passed in
            playerData = roomPos + "," + tmpThing.getName() + "," + tmpThing.getDescription();
            playerWriter << playerData << endl;
        }
    }
    playerWriter.close();

}

void GameFunctions::saveRooms(MapOb& aMap)
{
    ofstream roomWriter; //Writes the rooms
    ofstream roomItemsWriter; //Writes the room items
    string roomData;
    string roomItemData;

    int roomCount = aMap.roomCount();
    roomWriter.open(ROOM_FILE);
    roomItemsWriter.open(ROOMITEMS_FILE);

    for (int idx = 0; idx < roomCount; idx++ ) 
    {
        RoomOb tmpRoom = aMap.getRoomAtIndex(idx); 
        roomData = to_string(idx) + "," + tmpRoom.getName() + "," + tmpRoom.getDescription();
        roomWriter << roomData << endl;

        // cout << roomData << endl;

        int itemCount = tmpRoom.getItemCount();
        for (int idx2 = 0; idx2 < itemCount; idx2++ ) 
        {
            ThingOb tmpThing = tmpRoom.getThingAtIndex(idx2); //Get the thins position in the list for the index passed in
            roomData = to_string(idx) + "," + tmpThing.getName() + "," + tmpThing.getDescription();
            roomItemsWriter << roomData << endl;
            // cout << "     " << roomData << endl;
        }
    }
    roomWriter.close();
    roomItemsWriter.close();
}


void GameFunctions::loadPlayer(ActorOb& player) //Loads the players details in
{
    try
    {

        string line;
        ifstream infile;
        infile.open(PLAYER_FILE);

        while(getline(infile,line))
        {
            istringstream ss(line);

            string pos;
            getline(ss, pos, ',');

            player.setRoom(stoi(pos));

            string thingName;
            getline(ss, thingName, ',');

            string thingDescription;
            getline(ss, thingDescription, ','); 

            if(thingName != "")
            {
                  ThingOb tmpThing(thingName, thingDescription);
                  player.addThing(tmpThing);
            }
        }
    }
    catch(const exception& e ) {
        std::cerr << "exception occured" << endl;
    }
}

void GameFunctions::loadRoom(MapOb& aMap) //Loads the room details in
{
    try
    {
        string line;
        ifstream infile;
        infile.open(ROOMITEMS_FILE);

        while(getline(infile, line))
        {
            istringstream ss(line);

            string roomPos;
            getline(ss, roomPos, ',');

            string thingName;
            getline(ss, thingName, ',');

            string thingDescription;
            getline(ss, thingDescription, ','); 

            int pos = stoi(roomPos);

            if(thingName != "")
            {
                ThingOb tmpThing(thingName, thingDescription);
                aMap.addThingToRoom(pos, tmpThing);
            }
        }
    } 
    catch(const exception& e ) {
        std::cerr << "exception occured" << endl;
    }

}

void GameFunctions::takeThing(ActorOb& player, MapOb& aMap, string thingName)
{
	int pos = player.getRoom();
	RoomOb currentRoom = aMap.getRoomAtIndex(pos); 

	if (currentRoom.thingExists(thingName))
  	{	        
    	ThingOb tmpThing = currentRoom.getThingObj(thingName);
    	player.addThing(tmpThing);
        //Thing now has to be dropped from room
    	int thingIndex = currentRoom.getListIndex(thingName);
    	aMap.removeThingFromRoom(pos, thingIndex);

    	cout << "OK, " << thingName << " taken." << endl;
  	}
  	else
   	{
    	 cout << "Sorry, don't see any " << thingName << " in " << currentRoom.getName() << endl;
   	}

}

void GameFunctions::dropThing(ActorOb& player, MapOb& aMap, string thingName) //Player can drop things
{
	int pos = player.getRoom(); //Gets players position
	RoomOb currentRoom = aMap.getRoomAtIndex(pos);

	if(player.thingExists(thingName))
	{
    	//cout << "Found " << thingName << " on " << player.getName() << endl;
    	ThingOb tmpThing = player.getThingObj(thingName); 
    	aMap.addThingToRoom(pos, tmpThing);
        //Thing now has to be dropped from player					
    	int thingIndex = player.getListIndex(thingName);
    	player.removeThingbyIndex(thingIndex);
    	cout << "OK, " << thingName << " dropped." << endl;
  	}
  	else
   	{
    	 cout << "Sorry, don't see any " << thingName << " on " << player.getName() << endl;
   	}
}

void GameFunctions::lookAround(ActorOb& player, MapOb& aMap) //View the room and its contents if any
{

    int pos = player.getRoom();
    RoomOb i = aMap.getRoomAtIndex(pos);
  
    cout << "You are in "   << i.getName()  <<  endl;
    cout << i.getDescription()  <<  endl;
    cout << "This room contains: " << endl;
    if(i.getItemCount() > 0)
    {
        i.printThings();
    }
    else
    {
        cout << "     Notting..." << endl;
    }
}

void GameFunctions::printInventory(ActorOb player) //Prints the players posessions
{
	cout << "You have the following items: " << endl;
	if(player.getItemCount() > 0)
	{
        player.printThings();
    }
	else
	{
 		cout << "     Noting..." << endl;
    }
}

void GameFunctions::printHelp() //Help commands
{
    cout << "COMMANDS:" << endl
         << "     " << "Quit [ to exit game ] " << endl
         << "     " << "Go North / South / East / West" << endl
         << "     " << "Look [ to see current room and items that might exist there ]" << endl
         << "     " << "Take <Item Name> [ from room ]" << endl
         << "     " << "Drop <Item Name> [ to room ]"<< endl
         << "     " << "Inventory [ or just 'Inv' to get list of items on player ]"  << endl;
}

void GameFunctions::showIntro()
{
cout << endl;
cout << "You are in a small field with an old house to the north. You're not sure " << endl
     << "how you got here. Looking around you see a leaflet on the ground that you " << endl
     << "pick up and read..." << endl
     << endl
     << "Welcome to the your quest! You are about to start an adventure that is" << endl
     << "a game of mystery, danger and intrigue. In it you will explore lands not" << endl
     << "seen by mortals since the time of middle-earth. So start right now..." << endl
     << endl
     << "PS. If you do get stuck, you can ask for help and if really lost, then" << endl
     << "ask nicely for help with dir and if I'm in a good mood, I might reply." << endl
     << endl;
}

string GameFunctions::moveTo(ActorOb& player, MapOb& aMap, int aDir) //Changes rooms
{
	int pos = player.getRoom();
	RoomOb currentRoom = aMap.getRoomAtIndex(pos);

	int exitRoomNum;

    switch(aDir)
    {
    	case NORTH:
    	{
    		exitRoomNum = currentRoom.getNorth();
    		break;
    	}

    	case SOUTH:
    	{
    		exitRoomNum = currentRoom.getSouth();
    		break;
    	}

    	case EAST:
    	{
    		exitRoomNum = currentRoom.getEast();
    		break;
    	}

    	case WEST:
    	{
    		exitRoomNum = currentRoom.getWest();
    		break;
    	}

    	default:
    	{
    		exitRoomNum = NO_EXIT;
    		break;
    	}
    }


    if (exitRoomNum == NO_EXIT)
    {
    	cout << "No exit that way...." << endl;
    }
    else
    {
    	player.setRoom(exitRoomNum);

    	lookAround(player, aMap);
    }

}

void GameFunctions::showValidExits(ActorOb& player, MapOb& aMap) //Gets the current exits for the room the player is in
{
    int pos = player.getRoom();
    RoomOb currentRoom = aMap.getRoomAtIndex(pos);
    cout << "Valid exits from here are: " << currentRoom.getValidExits() << endl;
}

void GameFunctions::clearGameItems(ActorOb& player, MapOb& aMap)
{
    aMap.clearRooms();
    player.clearAllItems();
}


COMMANDS GameFunctions::convertCommands(const string& str) //Converting directions to strings
{
http://www.cplusplus.com/forum/beginner/174993/
    if(str == "GO") return GO;
    else if(str == "LOOK") return LOOK;
    else if(str == "TAKE") return TAKE;
    else if(str == "DROP") return DROP;
    else if(str == "INV") return INVENTORY;
    else if(str == "INVENTORY") return INVENTORY;
    else if(str == "HELP") return HELP;
    else if(str == "QUIT") return QUIT;
    else if(str == "SAVE") return SAVE;
    else if(str == "LOAD") return LOAD;
    else return DONTKNOW;
}

int GameFunctions::convertDirections(const string& str) //Converting directions to a string
{
	if(str == "NORTH") return NORTH;
    else if(str == "SOUTH") return SOUTH;
    else if(str == "EAST") return EAST;
    else if(str == "WEST") return WEST;
    else NO_EXIT;
}

string GameFunctions::getUserInput() //Validating the user entered a string 
{
    string userInput = "";

    cout << "> ";
    getline(cin, userInput);
    return userInput;
}

void GameFunctions::parseInputString(string inStr, string& word1, string& word2) 
{
https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string
    
    vector<string> words;          // Create vector to hold words
    string buf;                     // Have a buffer string
    stringstream ss(inStr);         // Insert the string into a stream

    while (ss >> buf)
        words.push_back(buf); //adding the words to a vector

    switch (words.size())
    {
        case 0:
            // cout << "Nothing entered!" << endl;
            break;
        case 1:
            word1 = stringToUpper(words.at(0)); //For single words
            break;
        case 2:
            word1 = stringToUpper(words.at(0));
            word2 = words.at(1); //word2 = word at index 1
            break;
        default:
            cout << "Command too long. Only 1 or 2 words allowed." << endl;
    }
}


string GameFunctions::stringToUpper(string strToConvert) 
{
	https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    for(unsigned int i=0; i<strToConvert.length(); i++)
    {
       strToConvert[i] = toupper(strToConvert[i]);
    }
    return strToConvert;    //return the upper case string
}



