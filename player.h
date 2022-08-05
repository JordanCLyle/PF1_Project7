//---------------------------------------------------
// Purpose:     Header file for the Player class
// Author:      John Gauch
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

// Debug flag
const int MAX_GOLD = 100;
const int MAX_HEALTH = 100;

class Player
{
private:
   string Name;
   int Gold;
   int Health;
   string Items;

public:
   Player();
   ~Player();

   void setName(const string name);
   void setGold(const int gold);
   void setHealth(const int health);
   void setItems(const string items);

   string getName() const;
   int getGold() const;
   int getHealth() const;
   string getItems() const;

   void Print() const;
   void addItem(const string item);
};
