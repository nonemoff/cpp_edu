#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string address;
	std::cout << "Input file`s address: ";
	std::cin >> address;

	std::ifstream file;
	file.open(address);

	if(!file.is_open()){
		std::cout << "Wrong address";
	} else {
		while(!file.eof()){
			std::string temp;
			std::getline(file, temp);
			std::cout << temp << std::endl;
		}
	}
}
