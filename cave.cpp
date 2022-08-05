//---------------------------------------------------
// Purpose:     Implementation for the Cave class
// Author:      John Gauch 
// Editor:      Jordan Lyle
//---------------------------------------------------
#include "cave.h"
#include <cstring>

// Remove all white space from start and end of string
string trim(const string str)
{
   unsigned int start = 0;
   unsigned int end = str.length()-1;
   while ((start < str.length()) && (isspace(str[start]))) start++;
   while ((end > start) && (isspace(str[end]))) end--;
   return str.substr(start, (end-start+1));
}

Cave::Cave()
{
   count = 0;
}

Cave::~Cave()
{
}

int Cave::GetCount()
{
   return count;
}
bool Cave::ReadRooms(const string filename)
{
   // Open input file
   ifstream din;
   din.open(filename);
   if (din.fail()) 
     { 
         return false;
     }

{
   // Read room information
    string Name = "Nothing";
    int Treasure = 0;
    string Creature = "Nothing";
    string Food = "Nothing";
    string Item = "Nothing";
    string Description = "Nothing";
    string fullDescription = "";
    string lineClear = "";
    while (din.eof() == false)
    {
        getline(din,Name);
        rooms[count].SetName(Name);
        din >> Treasure;
        rooms[count].SetTreasure(Treasure);
        getline(din, lineClear);
        getline(din, Creature);
        rooms[count].SetCreature(Creature);
        getline(din, Food);
        rooms[count].SetFood(Food);
        getline(din, Item);
        rooms[count].SetItem(Item);
        getline(din, Description);
        char hashtagChecking[Description.length()];
        hashtagChecking[0] = Description[0];
        while (hashtagChecking[0] != '#')
        {
           fullDescription = fullDescription + Description + "\n";
           rooms[count].SetDescription(fullDescription);
           getline(din, Description);
           hashtagChecking[0] = Description[0];
        }
        count++;
        fullDescription = "";
    }
  
}

// Close input file
   din.close();
   return true;
}

bool Cave::WriteRooms(const string filename)
{
   // Open output file
   ofstream dout;
   dout.open("rooms.copy");
   if (dout.fail()) 
      return false;
   for (int i = 0; i < count; i++)
   {
       dout << rooms[i].GetName() << endl;
       dout << rooms[i].GetTreasure() << endl;
       dout << rooms[i].GetCreature() << endl;
       dout << rooms[i].GetFood() << endl;
       dout << rooms[i].GetItem() << endl;
       dout << rooms[i].GetDescription() << "#" << endl;
   }
   // Close output file
   dout.close();
   return true;
}

bool Cave::ReadMap(const string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail()) 
      return false;

   // Read map information
   for (int room = 0; room < count; room++)
      for (int dir = 0; dir < MAX_DIRS; dir++)
         din >> map[room][dir];

   // Close input file
   din.close();
   return true;
}

bool Cave::WriteMap(const string filename)
{
   // Open output file
   ofstream dout;
   dout.open(filename.c_str());
   if (dout.fail()) 
      return false;

   // Write map information
   for (int room = 0; room < count; room++)
   {
      for (int dir = 0; dir < MAX_DIRS; dir++)
         dout << map[room][dir] << " ";
      dout << endl;
   }

   // Close output file
   dout.close();
   return true;
}

int Cave::VisitRoom(const int room, Player & player)
{
    // Gives description of room
    cout << endl;
    cout << rooms[room].GetDescription();
    cout << endl;
    // Modifies player values after visiting room
    player.setGold(player.getGold() + rooms[room].FindTreasure());
    player.setHealth(player.getHealth() - rooms[room].FightCreature());
    player.setHealth(player.getHealth() + rooms[room].EatFood());
    player.setItems(player.getItems() + rooms[room].PickupItem());
   return 0;
}

int Cave::NextRoom(const int room)
{
   // Error checking
   if (room < 0 || room >= count)
      return 0;

   // Prompt the user for direction
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }

   // Return next room number
   int next = room;
   switch (direction)
   {
      case 'N': next = map[room][0]; break;
      case 'S': next = map[room][1]; break;
      case 'E': next = map[room][2]; break;
      case 'W': next = map[room][3]; break;
   }
   return next;
}
