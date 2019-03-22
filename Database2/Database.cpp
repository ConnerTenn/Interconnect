
#include "Database.h"

Database::Database()
{
	std::cout << "Starting Database\n";
	srand(time(0));

	RootNode = new Node("Root");
	RootNode->ID = 1;
	Contents.push_back(RootNode);
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
/*Element *Database::FindElem(std::string content)
{
	for (u64 i = 0; i < Contents.size(); i++)
	{
		if (Contents[i]->Content == content) { return Contents[i]; }
	}
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
}*/

u64 Database::AddElem(Element *elem)
{
	std::cout << "Added: " << elem->String() << "\n";
	Contents.push_back(elem);
	RootNode->SubElementList.push_back(elem->ID);
	return elem->ID;
}

u64 Database::AddLink(std::string content, u64 head, u64 tail)
{
	return AddElem((Element *)new Link(content, head, tail));
}

u64 Database::AddNode(std::string content, std::vector<u64> subElements)
{
	return AddElem((Element *)new Node(content, subElements));
}

void Database::RemoveElem(u64 id)
{
	Element *elem = FindElem(id);

	if (elem)
	{
		for (u64 i = 0; i < Contents.size();)
		{
			if (elem == Contents[i]) { Contents.erase(Contents.begin() + i); }
			else { i++; }
		}

		delete elem;

		for (u64 i = 0; i < RootNode->SubElementList.size();)
		{
			if (id == RootNode->SubElementList[i]) { RootNode->SubElementList.erase(RootNode->SubElementList.begin() + i); }
			else { i++; }
		}
	}
}

void Database::Print(u64 id)
{
	Element *elem = FindElem(id);
	if (elem)
	{	
		std::cout << elem->String() << "\n";
	}
	else
	{
		std::cout << "NO ELEM " << IdStr(id) << "\n";
	}
}
