#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>


#include "xml.h"
#include "linked_stack.h"

int main() 
{
    using namespace std;
    using namespace xml;

    char xmlfilename[100];
    cin.getline(xmlfilename, 100);

    ifstream file{xmlfilename};
	if(!file.is_open()) return 1;

	stringstream string;
	string << file.rdbuf();
	file.close();
	auto xml = string.str();

	if (!verifier(xml)) cout << "error\n";

	    				
	
	std::cout << xmlfilename << std::endl;

    return (0);
}
