
#include "Database.h"

Database::Database()
{
	std::cout << "Starting Database\n";
	srand(time(0));
}

Database::~Database()
{
	std::cout << "Closing Database\n";
	for (u64 i = 0; i < Contents.size(); i++)
	{
		if (Contents[i]) { delete Contents[i]; Contents[i]=0; }
	}
}

//Switch to binary search
Element *Database::FindElem(u64 id)
{
	for (u64 i = 0; i < Contents.size(); i++)
	{
		if (Contents[i]->ID == id) { return Contents[i]; }
	}
	return 0;
}
Element *Database::FindElem(std::string content)
{
	for (u64 i = 0; i < Contents.size(); i++)
	{
		if (Contents[i]->Content == content) { return Contents[i]; }
	}
	return 0;
}
Link *Database::FindLink(u64 id)
{
	Link *link = (Link *)FindElem(id);
	if (link && link->Type==Element::Link) { return link; }
	return 0;
}
Node *Database::FindNode(u64 id)
{
	Node *node = (Node *)FindElem(id);
	if (node && node->Type==Element::Node) { return node; }
	return 0;
}
Link *Database::FindLink(std::string content)
{
	Link *link = (Link *)FindElem(content);
	if (link && link->Type==Element::Link) { return link; }
	return 0;
}
Node *Database::FindNode(std::string content)
{
	Node *node = (Node *)FindElem(content);
	if (node && node->Type==Element::Node) { return node; }
	return 0;
}

u64 Database::AddLink(std::string content, u64 head, u64 tail)
{
	return 0;
}

u64 Database::AddNode(std::string content, std::vector<u64> subElements)
{
	Node *node = new Node();
	
	node->ID = Rand();
	node->Content = content;
	node->SubElementList = subElements;
	
	std::cout << "Added: " << node->String() << "\n";
	Contents.push_back(node);
	return node->ID;
}

void Database::Print(u64 id)
{
	Element *elem = FindElem(id);
	if (elem)
	{	
		std::cout << elem->String() << "\n";
	}
}
