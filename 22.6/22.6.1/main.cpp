#include <iostream>
#include <string>
#include <map>

int main(){
	std::map<std::string, std::string> dict;
	std::cout << "Input option " << std::endl;
	std::cout << "0 - add new contact" << std::endl;
	std::cout << "1 - find name by phone" << std::endl;
	std::cout << "2 - find phones by name" << std::endl;
	while(true){
		std::cout << "Input option: ";
		int opt; std::cin >> opt;
		switch (opt){
		case 0:
			{
			std::cout << "Input new contact: ";
			std::string phone, name; std::cin >> phone >> name;
			dict[phone] = name;
			break;
			}
		case 1:
			{
			std::cout << "Input phone: ";
			std::string phone; std::cin >> phone;
			std::cout << phone << " " << dict[phone] << std::endl;
			break;
			}
		case 2:
			{
			std::cout << "Input the name: ";
			std::string name; std::cin >> name;
			for (std::map<std::string, std::string>::iterator it = dict.begin();\
					it != dict.end(); it++){
				if (it->second == name){
					std::cout << it->first << " " << it->second << std::endl;
				}
			}
			break;
			}
		default:
			{
			std::cout << "Wrong input!" << std::endl;
			break;
			}
		}
	}
	return 0;
}
