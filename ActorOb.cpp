#include "ThingOb.h"
#include "HolderThingOb.h"
#include "RoomOb.h"
#include "ActorOb.h"
#include "MapOb.h"

ActorOb::ActorOb(string name, string description, int roomPos) : HolderThingOb(name, description)
{
  this -> roomPos = roomPos;
}
