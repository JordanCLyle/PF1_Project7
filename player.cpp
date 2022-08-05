//---------------------------------------------------
// Purpose:     Implementation for the Player class
// Author:      John Gauch
//---------------------------------------------------
#include "player.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Player::Player()
{
   Name = "none";
   Gold = 0;
   Health = 0;
   Items = "none";
}

//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Player::~Player()
{
}

//------------------------------------------------------------
// Purpose: Set Name value
//------------------------------------------------------------
void Player::setName(const string name)
{
   Name = name;
}

//------------------------------------------------------------
// Purpose: Set Gold value
//------------------------------------------------------------
void Player::setGold(const int gold)
{
   Gold = gold;
   if (Gold > MAX_GOLD) Gold = MAX_GOLD;
   if (Gold < 0) Gold = 0;
}

//------------------------------------------------------------
// Purpose: Set Health value
//------------------------------------------------------------
void Player::setHealth(const int health)
{
   Health = health;
   if (Health > MAX_HEALTH) Health = MAX_HEALTH;
   if (Health < 0) Health = 0;
}

//------------------------------------------------------------
// Purpose: Set Items value
//------------------------------------------------------------
void Player::setItems(const string items)
{
   Items = items;
}

//------------------------------------------------------------
// Purpose: Get Name value
//------------------------------------------------------------
string Player::getName() const
{
   return Name;
}

//------------------------------------------------------------
// Purpose: Get Gold value
//------------------------------------------------------------
int Player::getGold() const
{
   return Gold;
}

//------------------------------------------------------------
// Purpose: Get Health value
//------------------------------------------------------------
int Player::getHealth() const
{
   return Health;
}

//------------------------------------------------------------
// Purpose: Get Items value
//------------------------------------------------------------
string Player::getItems() const
{
   return Items;
}

//------------------------------------------------------------
// Purpose: Print all Player data
//------------------------------------------------------------
void Player::Print() const
{
   cout << "\nPlayer Information" << endl;
   cout << "Name:   " << Name << endl;
   cout << "Gold:   " << Gold << endl;
   cout << "Health: " << Health << endl;
   cout << "Items:  " << Items << endl;
}

//------------------------------------------------------------
// Purpose: Add item to Items string
//------------------------------------------------------------
void Player::addItem(const string item)
{
   if (Items == "")
      Items = item;
   else if (item != "")
      Items = Items + "," + item;
}
