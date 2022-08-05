//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
// Author:  John Gauch 
// Editor:  Jordan Lyle
//------------------------------------------------------------

#include "cave.h"

int main()
{
   // Initialize game
   srandom(time(NULL));

   // Initialize player
   Player player;
   player.setGold(0);
   player.setHealth(100);
   player.setItems("");
   string Name = "none";
   cout << "What is your name?: ";
   getline(cin, Name);
   player.setName(Name);
   // Initialize cave
   Cave cave;
    cave.ReadRooms("room.txt");
    cave.WriteRooms("room.copy");
    cave.ReadMap("map.txt");
    cave.WriteMap("map.copy");
    int room = 0;

   // Explore cave until player wins or dies
   while (player.getHealth() > 0 && player.getGold() < 200)
    {
        player.Print();
        cave.VisitRoom(room, player);
        room = cave.NextRoom(room);
    }
   // Print final message
   player.Print();
   if (player.getHealth() == 0)
      cout << "\nSorry, you died exploring the cave." << endl;
   else
      cout << "\nYou leave the cave with " << player.getGold() << " gold coins!" << endl;
   return 0;
}
