
#include "Interconnect.h"
#include "Database.h"

int main()
{
	Database database;
	
	
	u64 n = database.AddNode("Hello World");
	database.Print(n);
	return 0;
}
