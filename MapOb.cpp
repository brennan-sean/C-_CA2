
#include "ThingOb.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"

MapOb::MapOb()
{
}

void MapOb::addRoom(RoomOb aRoom) //Adding rooms to the vector
{
  this -> roomList.push_back(aRoom); 
}

int MapOb::roomCount() //Counting the rooms in the vector
{
  return roomList.size();
}

RoomOb MapOb::getRoomAtIndex(int index) //Getting the rooms within the list for the index that is passed in
{
   return roomList[index]; 
}

void MapOb::removeThingFromRoom(int roomIndex, int thingIndex) //Removing things from a certain room
{
  roomList[roomIndex].removeThingbyIndex(thingIndex);
}

void MapOb::addThingToRoom(int roomIndex, ThingOb aThing) //Adding a thing to a certain room
{
  roomList[roomIndex].addThing(aThing);
}

void MapOb::createDefaultRooms() //Creating the rooms for the map
{
    int roomNum = 0;
    addRoom(RoomOb("Room0", "a Small Field with a old house to the north", roomNum, 1, 2, 3, -1));

    roomNum = 1;
    addRoom(RoomOb("Room1", "a old House, abandoned now with the wind coming in through the holes in the wall", roomNum, -1, 0, -1, -1));
    roomList[1].addThing(ThingOb("Pot", "a big fat shiny pot"));
    roomList[1].addThing(ThingOb("Kettle", "a very small kettle with a whistle"));
    roomList[1].addThing(ThingOb("Lamp", "a great lamp showing a lot of light"));

    roomNum = 2;
    addRoom(RoomOb("Room2", "a Stinky Swamp, with black sticky mud. Maybe you should get out of here..", roomNum, 0, -1, -1, -1));

    roomNum = 3;
    addRoom(RoomOb("Room3", "a Lovely Meadow, with the grass waving in the breeze", roomNum, -1, 4, -1, 0));
    roomList[3].addThing(ThingOb("Coin", "a silver coin worth not much"));

    roomNum = 4;
    addRoom(RoomOb("Room4", "a Dark Wood, with small trees and bushes scattered about", roomNum, 3,-1,5,-1));
    roomList[4].addThing(ThingOb("Dagger", "a small sword glowing slightly"));

    roomNum = 5;
    addRoom(RoomOb("Room5", "a Deep Forest , with small bushes and large leafy trees hiding the sunlight", roomNum, -1,6,-1,4));

   roomNum = 6;
   addRoom(RoomOb("Room6", "a Deep Forest, with small bushes and leafy large trees hiding the sunlight", roomNum, 5, -1, 7, 8));

   roomNum = 7;
   addRoom(RoomOb("Room7", "a Deep Forest, with small bushes and leafy leafy trees hiding the sunlight", roomNum, -1,-1,-1,6));
   roomList[7].addThing(ThingOb("Key", "a golden key sure to be useful somewhere..."));

   roomNum = 8;
   addRoom(RoomOb("Room8", "a Mountain Pass, with snow covered peaks now to be seen", roomNum, -1,9,6,-1));
   roomList[8].addThing(ThingOb("Axe", "a small axe probably made by the dwarfs..."));

   roomNum = 9;
   addRoom(RoomOb("Room9", "a Deep Canyon, with high smooth walls and only a narrow view of the sky above ", roomNum, 8,-1,10,-1));

   roomNum = 10;
   addRoom(RoomOb("Room10", "a Dark Cavern, with glistening walls of gemstones that might be mined ", roomNum, -1,11,-1,9));

   roomNum = 11;
   addRoom(RoomOb("Room11", "a Kings Throne room, with a golden chair now covered in dust ", roomNum, 10,-1,-1,-1));
   roomList[11].addThing(ThingOb("Vase", "a precious ming vase worthy of winning any game"));
}

void MapOb::clearRooms() //Clears the rooms items so when ou read in from fil it doesn't make duplicates
{
    int itemCount;
    for (vector<RoomOb>::iterator i = roomList.begin(); i != roomList.end(); ++i)
    {
       // cout << "Room - " << i->getName() << " Item Count: " << i->getItemCount() << endl;
        itemCount = i->getItemCount();
        if (itemCount > 0)
        {
            i->clearAllItems();
        }
    }
}

