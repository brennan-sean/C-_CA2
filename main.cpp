#include <iostream>
#include "GameFunctions.h"
#include "ThingOb.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"



using namespace std;

int main(int argc, char *argv[])
{
    GameFunctions gameFunctions;
    
    ActorOb player("You", "You are who you are", 0); //Creating a player starts off in room 0

    MapOb map;
    map.createDefaultRooms(); 

    string thingName;
    string userInput;
    string word2;
    string command;
    int dir;

    gameFunctions.showIntro();

    while(command != "QUIT")
    {
        command.clear(); 
        userInput = gameFunctions.getUserInput(); //Testing user input is a string 
        gameFunctions.parseInputString(userInput, command, word2); //Parsing the input the user enters

        // cout << userInput << " ; " << command << " " << word2 << endl;

        COMMANDS cmd = gameFunctions.convertCommands(command); //Converting the commands to strings

        switch (cmd) 
        {
            case GO:
            {
                if (word2 == "")
                {
                    cout << "Direction not specified..." << endl;
                }
                else 
                {
                    dir = gameFunctions.convertDirections(gameFunctions.stringToUpper(word2)); //Changes directions to strings and turns it case insensitive
                    gameFunctions.moveTo(player, map, dir);
                }
                break;
            }
            case LOOK:
            {
                gameFunctions.lookAround(player, map);
                break;
            }

            case TAKE:
            {
                thingName = word2; //Testing that word to is valid
                gameFunctions.takeThing(player, map, thingName);
                break;
            }

            case DROP:
            {
                thingName = word2;
                gameFunctions.dropThing(player, map, thingName);
                break;
            }
            
            case INVENTORY:
            {
                gameFunctions.printInventory(player);
                break;
            }
            
            case HELP:
            {
                if (gameFunctions.stringToUpper(word2) == "DIR")
                {
                    gameFunctions.showValidExits(player, map);
                }
                else 
                {
                    gameFunctions.printHelp();
                }
                break;
            }

            case SAVE:
            {
                gameFunctions.savePlayer(player);
                gameFunctions.saveRooms(map);
                cout <<  "Game Saved" << endl;
                break;
            }

            case LOAD:
            {
                gameFunctions.clearGameItems(player, map);
                gameFunctions.loadPlayer(player);
                gameFunctions.loadRoom(map);
                cout <<  "Game Loaded" << endl;
                break;
            }

            case QUIT:
            {
                break;
            }
            
            case DONTKNOW:
                default:
                    if (command != "")
                    {
                        cout << "I don't understand that.." << endl;
                    }
        }
    }
}
