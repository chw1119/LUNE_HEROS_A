#ifndef _ITEM
#define _ITEM

#include "Prefix.h"

#include <iostream>
#include <string>

class Item
{
private:

	int id     = 0;
	int value  = 0;
	int prefix = PREFIX_NORMAL;

	bool isStackable = true;

	std::string itemName        = nullptr;
	std::string itemInstruction = nullptr;

public:

	Item();
	Item(int id, bool stackable);
	Item(int id, bool stackable, std::string name, std::string instruction);

	int GetId() const;
	int GetValue() const;
	int GetPrefix() const;
	bool GetStackable() const;
	std::string GetName() const;
	std::string GetInstruction() const;

	void SetId(int id);
	void SetValue(int value);
	void SetPrefix(int prefix);
	void SetStackable(bool isStack);
	void SetName(std::string name);
	void SetInstruction(std::string instruction);


};

#endif