#include "ThingOb.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"

HolderThingOb::HolderThingOb(string name, string description) : ThingOb(name, description)
{

}

ThingOb HolderThingOb::getThingObj(const string thingName) //returns the thing for the thingName passed in
{
  for (vector<ThingOb>::iterator i = thingObList.begin(); i != thingObList.end(); ++i)
  {
    if(i->getName() == thingName)
    {
      return(*i);
    }
  }
}

ThingOb HolderThingOb::getThingAtIndex(int index) //Gets the things within the list for the index passed in
{
  return thingObList[index];
}

int HolderThingOb::getItemCount() //Counts the amount off items withing the list
{
    if (thingObList.empty())
    {
        return 0;
    }
   
    return (thingObList.size());
}

int HolderThingOb::getListIndex(const string thingName) //Gets the index off the iterator
{
https://https://stackoverflow.com/questions/2152986/what-is-the-most-effective-way-to-get-the-index-of-an-iterator-of-an-stdvector
 	for (vector<ThingOb>::iterator i = thingObList.begin(); i != thingObList.end(); ++i)
    {
        if(i->getName() == thingName)
        {
        	return i - thingObList.begin();
        }
    }
}

bool HolderThingOb::thingExists(const string thingName) //Testing to see if a thing exsists
{
    bool found = false;

    for (vector<ThingOb>::iterator i = thingObList.begin(); i != thingObList.end(); ++i)
    {
        if(i->getName() == thingName)
        {
       		return true;
        }
    }

    return found;
}

void HolderThingOb::removeThingbyIndex(int index) //Removes the index you pass in 
{
https://https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
  
    thingObList.erase(thingObList.begin() + index);
}


void HolderThingOb::addThing(ThingOb aThing) //Adds the things to the list
{
  this -> thingObList.push_back(aThing);
}

void HolderThingOb::printSingleThing(ThingOb& i)
{
  cout << "     " <<  i.getName() << "," << i.getDescription() << endl;
}

void HolderThingOb::printThings() //Prints all the things
{
   for (vector<ThingOb>::iterator i = thingObList.begin(); i != thingObList.end(); ++i)
    {
        printSingleThing(*i);
    }

}

void HolderThingOb::clearAllItems() //Clears the items the player has on them already if any
{
    int itemCount = getItemCount();
    if (itemCount > 0)
    {
        for (int idx = 0; idx < itemCount; idx++ ) 
        {
            removeThingbyIndex(idx);
        }
    }
}




