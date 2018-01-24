#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "ThingOb.h"
#pragma once

using namespace std;

class HolderThingOb : public ThingOb
{
	private:
		void printSingleThing(ThingOb& i);
	protected:
		vector<ThingOb> thingObList;
	public:
		HolderThingOb(string name, string description);
 		ThingOb getThingObj(const string thingName);
 		ThingOb getThingAtIndex(int index);
 		int getItemCount();
 		int getListIndex(const string thingName);
 		bool thingExists(const string thingName);
 		bool checkIfEmpty();
	   	void addThing(ThingOb aThing);
     	void removeThingbyIndex(int index);
		void printThings();
		void clearAllItems();
};