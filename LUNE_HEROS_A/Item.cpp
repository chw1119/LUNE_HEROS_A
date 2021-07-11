#include "Item.h"

Item::Item()
{

}

Item::Item(int id, bool stackable)
{
	this->id = id;
	this->isStackable = stackable;
}

Item::Item(int id, bool stackable, std::string name, std::string instruction)
{

	this->id = id;
	this->isStackable = stackable;

	this->itemName = name;
	this->itemInstruction = instruction;

}

int Item::GetId() const
{
	return id;
}

int Item::GetValue() const
{
	return value;
}

int Item::GetPrefix() const
{
	return prefix;
}

bool Item::GetStackable() const
{
	return isStackable;
}

void Item::SetId(int id)
{
	this->id = id;
}

void Item::SetValue(int value)
{
	this->value = value;
}

void Item::SetPrefix(int prefix)
{
	this->prefix = prefix;
}

void Item::SetStackable(bool isStack)
{
	this->isStackable = isStack;
}

void Item::SetName(std::string name)
{
	this->itemName = name;
}

void Item::SetInstruction(std::string instruction)
{
	this->itemInstruction = instruction;
}

std::string Item::GetName() const
{
	return itemName;
}

std::string Item::GetInstruction() const
{
	return itemInstruction;
}
