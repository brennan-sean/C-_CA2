#include <string>
#include <vector>
#include "HolderThingOb.h"
#pragma once

using namespace std;

class ActorOb  : public HolderThingOb	// !! for the player and any other people
{
	private:
		int roomPos;	// the number of the room in which player is
	public:
		ActorOb(string name, string description, int aRoomNum);
		void setRoom(int roomNum) { this->roomPos = roomNum; };
		int getRoom() const { return roomPos; };
};
