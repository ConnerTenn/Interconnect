
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "Interconnect.h"

class Database
{
public:
	std::vector<Element *> Contents;
	
	Database();
	~Database();
	
	Element *FindElem(u64 id);
	Element *FindElem(std::string content);
	Link *FindLink(u64 id);
	Node *FindNode(u64 id);
	Link *FindLink(std::string content);
	Node *FindNode(std::string content);
	
	u64 AddLink(std::string content, u64 head, u64 tail);
	u64 AddNode(std::string content, std::vector<u64> subElements = {});
	void Print(u64 id);
};

#endif
