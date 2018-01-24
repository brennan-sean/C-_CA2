#include <vector>
#include <string>
using namespace std;
#pragma once

class MapOb      // Rooms will be added to the map
{
    private:
        vector<RoomOb> roomList;
    public:
		MapOb();
        void addRoom(RoomOb aRoom);
        void createDefaultRooms();
        int roomCount();
        void removeThingFromRoom(int roomIndex, int thingIndex);
		void addThingToRoom(int roomIndex, ThingOb aThing);
        void clearRooms();
        RoomOb getRoomAtIndex(int index);
};