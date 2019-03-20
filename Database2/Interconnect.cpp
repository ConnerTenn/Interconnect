
#include "Interconnect.h"
#include <random>
#include <limits>

std::random_device rd;
std::mt19937_64 eng(rd());
std::uniform_int_distribution<u64> distr;

u64 Rand()
{
	return distr(eng);
}

Element::~Element() {}
std::string Element::String()
{
	return "[0x" +std::to_string(ID) + "] " + Content;
}

Link::Link()
{
	Type = Element::Link;
}

std::string Link::String()
{
	return "Link: " + Element::String();
}

Node::Node()
{
	Type = Element::Node;
}

std::string Node::String()
{
	return "Node: " + Element::String();
}

