
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

struct Element
{
	u64 ID;
	std::string Content;
	enum { Link=1,Node } Type;
	virtual ~Element();
	
	//Element();
	virtual std::string String();
};

struct Link : public Element
{
	u64 Head, Tail;
	
	Link();
	
	std::string String();
};

struct Node : public Element
{
	std::vector<u64> SubElementList;
	
	Node();
	
	std::string String();
};

#endif
