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

	if (!verifier(xml)) 
	{
		cout << "error\n";
		return -1;

	} else {
		cout << "passou\n";
	}	
	
	size_t from{0};
	while (from < xml.length()) 
	{	
		//extrai TODA a imagem
		const auto img = extract(xml, "<img>", "</img>", from);
		if (from == string::npos) break;
	
		//extrai atributos
		const auto name = xml::subextractor(img, "<name>", "</name>");
		cout << "name : " << name << endl;
		const auto height = stoi(subextractor(img, "<height>", "</height>"), nullptr);
		cout << "height :" << height << endl;
		const auto width = stoi(subextractor(img, "<width>", "</width>"), nullptr);
		cout << "width : " << width << endl;
		if (height <= 0|| width <= 0) return -2;
		//processa matrix 
	}
    return (0);
}
