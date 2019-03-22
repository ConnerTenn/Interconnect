
#ifndef _INTERCONNECT_H_
#define _INTERCONNECT_H_

#include <iostream>
#include <string>
#include <vector>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long i64;

u64 Rand();
std::string IdStr(u64 id);

struct Element
{
	u64 ID;
	std::string Content;
	enum { Link=1,Node } Type;

	Element();
	Element(std::string content);
	virtual ~Element();
	
	//Element();
	virtual std::string String();
};

struct Link : public Element
{
	u64 Head, Tail;
	bool Directional;
	
	Link();
	Link(std::string content, u64 head=0, u64 tail=0, bool directional=true);
	
	std::string String();
};

struct Node : public Element
{
	std::vector<u64> SubElementList;
	
	Node();
	Node(std::string content, std::vector<u64> subElements={});
	
	std::string String();
};

#endif
