
#include "Interconnect.h"
#include <random>
#include <limits>
#include <iomanip>

std::random_device rd;
std::mt19937_64 eng(rd());
std::uniform_int_distribution<u64> distr;

u64 Rand()
{
	return distr(eng);
}

template< typename T >
std::string IntToHex( T i )
{
	std::stringstream stream;
	stream << "0x" 
			<< std::setfill ('0') << std::setw(sizeof(T)*2) 
			<< std::hex << i;
	return stream.str();
}

std::string IdStr(u64 id)
{
	return "[" + IntToHex((u16)id) + "]";
}


Element::Element() : Element("") {}
Element::Element(std::string content)
{
	Content=content;
	ID = Rand() %0xFFFF;
}
Element::~Element() {}

std::string Element::String()
{
	return IdStr(ID) + " \"" + Content + "\"";
}


Link::Link() : Link("") {}
Link::Link(std::string content, u64 head, u64 tail, bool directional) :
	Element(content)
{
	Type = Element::Link;
	Head = head;
	Tail = tail;
	Directional = directional;
}

std::string Link::String()
{
	return Element::String() + " " + IdStr(Head) + (Directional?"->":"--") + IdStr(Tail);
}



Node::Node() : Node("") {}
Node::Node(std::string content, std::vector<u64> subElements) :
	Element(content)
{
	Type = Element::Node;
	SubElementList = subElements;
}

std::string Node::String()
{
	std::string out = Element::String();
	
	out += " [";
	for (u64 i = 0; i < SubElementList.size(); i++)
	{
		if (i) { out+=","; }
		out += IdStr(SubElementList[i]);
	}
	out += "]";
	return out;
}
