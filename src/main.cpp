/**
 * @file main.cpp
 * @author Hans Buss, André Fernandes
 * @brief Código main do programa de leitura e validação de XML, além do processamento dos mesmos.
 *
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>


#include "xml.h"
#include "linked_stack.h"
#include "counter.h"

/**
 * @brief Executa o programa, realiza a leitura e o processamento do xml.
 * 
 * @return 0 se o programa funcionar;
 * @return 1 se não foi possível abrir o arquivo;
 * @return -1 se o XML é invalido
 */
int main() 
{
    using namespace std;
    using namespace xml;
    using namespace counter;

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
		return (-1);
	} 	
	
	size_t from{0};
	while (from < xml.length()) 
	{	
		//extrai TODA a imagem
		const auto img = extract(xml, "<img>", "</img>", from);
		if (from == string::npos) break;
	
		//extrai atributos
		const auto name = xml::subextractor(img, "<name>", "</name>");
		const auto data = subextractor(img, "<data>", "</data>");
		const auto height = stoi(subextractor(img, "<height>", "</height>"), nullptr);
		const auto width = stoi(subextractor(img, "<width>", "</width>"), nullptr);

		if (height <= 0|| width <= 0) return -2;
	
		//conta as regiões da imagem e printa 
		bool* matrix = create_matrix(data, width, height);
		int regions = connectivity_counter(width, height, matrix);
		delete matrix;

		cout << name << ' ' << regions << endl;
	}
    return (0);
}
