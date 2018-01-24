#include "ThingOb.h"
#include "Gamefunctions.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"

RoomOb::RoomOb (string name, string description, int roomNum, int aNorth, int aSouth, int aEast, int aWest) : HolderThingOb(name, description) 
{
     this->roomNum = roomNum;
     this->n = aNorth;
     this->s = aSouth;
     this->e = aEast;
     this->w = aWest;
}

string RoomOb::getValidExits() //Returning the exits to the rooms
{
    string retStr;
                
    int nextRoom = getNorth();
    if (nextRoom != NO_EXIT)
    { 
    	retStr = "North"; 
    }
    nextRoom = getSouth();
    if (nextRoom != NO_EXIT)
    { 
    	retStr = retStr + " South"; 
    }
    nextRoom = getEast();
    if (nextRoom != NO_EXIT)
    { 
  	 	retStr = retStr + " East"; 
    }
    nextRoom = getWest();
    if (nextRoom != NO_EXIT)
    { 
      	retStr = retStr + " West"; 
    }
               
    return retStr;
}
