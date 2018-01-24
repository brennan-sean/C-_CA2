#include <string>
#include "HolderThingOb.h"
#pragma once

using namespace std;

class RoomOb : public HolderThingOb
{
	private:
		int roomNum;
		int n;
		int s;
		int e;
		int w;

		
	public:
		RoomOb (string name, string description, int roomNum, int aNorth, int aSouth, int aEast, int aWest);
		int getRoomNum() const { return roomNum; };
		int getNorth() const { return n; };
		int getSouth() const { return s; };
		int getEast() const { return e; };
		int getWest() const { return w; };
		string getValidExits();
};