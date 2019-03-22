
#include "Interconnect.h"
#include "Database.h"


#include <sstream>
#include <algorithm>
#include <iterator>
std::vector<std::string> Delimit(std::string text)
{
	std::istringstream iss(text);
	/*std::vector<std::string> tokens;

	std::copy(std::istream_iterator<std::string>(iss),
	std::istream_iterator<std::string>(),
	std::back_inserter(tokens));*/

	return/*std::vector<std::string> tokens*/{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
	//return tokens;
}

int main()
{
	Database database;

	u64 n = database.AddNode("Hello World");
	u64 n2 = database.AddNode("Hello!", {n});
	u64 l = database.AddLink("Hi",n, 1);
	std::cout << "\n";
	database.Print(1);
	database.Print(n);
	database.Print(l);
	database.Print(n2);

	database.RemoveElem(n);
	database.RemoveElem(n2);
	database.RemoveElem(l);

	std::cout << "\n";
	database.Print(1);
	database.Print(l);

	
	return 0;
}
