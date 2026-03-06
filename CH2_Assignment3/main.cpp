#include<iostream>

#include"Inventory.h"
#include"Item.h"


int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->Resize(25);
	for (int i = 0; i < 14; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->SortItems();
	itemInventory->PrintAllItems();

	Inventory<Item>* itemInventory2 = new Inventory<Item>(*itemInventory);
	itemInventory2->PrintAllItems();

	delete itemInventory;
	delete itemInventory2;

	return 0;
}

bool compareItemsByPrice(const Item& item1, const Item& item2)
{
	return item1.GetPrice() < item2.GetPrice();
}