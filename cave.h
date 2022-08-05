//---------------------------------------------------
// Purpose:     Header file for the Cave class
// Author:      John Gauch
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "player.h"
#include "room.h"
using namespace std;

const int MAX_ROOMS = 20;
const int MAX_DIRS = 4;

class Cave
{
private:
   Room rooms[MAX_ROOMS];
   int map[MAX_ROOMS][MAX_DIRS];
   int count = 0;

public:
   Cave();
   ~Cave();

   int GetCount();
   bool ReadRooms(const string filename);
   bool WriteRooms(const string filename);
   bool ReadMap(const string filename);
   bool WriteMap(const string filename);
   int VisitRoom(const int room, Player & player);
   int NextRoom(const int room);
};
