#include <string>
#include "ThingOb.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"
#pragma once

using namespace std;

enum COMMANDS {GO, LOOK, TAKE, DROP, INVENTORY, HELP, DONTKNOW, QUIT, SAVE, LOAD};

const int NO_EXIT = -1;
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

const string ROOM_FILE = "Rooms.dat";
const string ROOMITEMS_FILE = "RoomItems.dat";
const string PLAYER_FILE = "Player.dat";



class GameFunctions
{
	private:

	public:
		void savePlayer(ActorOb& player);
		void saveRooms(MapOb& aMap);
		void loadPlayer(ActorOb& player);
		void loadRoom(MapOb& aMap);
		void takeThing(ActorOb& player, MapOb& aMap, string thingName);
		void dropThing(ActorOb& player, MapOb& aMap, string thingName);
		void lookAround(ActorOb& player, MapOb& aMap);
		void printInventory(ActorOb i);
		void printHelp();
		void showIntro();
		string moveTo(ActorOb& player, MapOb& aMap, int aDir);
		void showValidExits(ActorOb& player, MapOb& aMap);
		void clearGameItems(ActorOb& player, MapOb& aMap);
		COMMANDS convertCommands(const string& str);
		int convertDirections(const string& str);
		string getUserInput();
		void parseInputString(string inStr, string& word1, string& word2); 
		string stringToUpper(string strToConvert);
		
};