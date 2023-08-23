#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
	std::string address;
	std::cout << "Input file`s address: ";
	std::cin >> address;

	std::ifstream file;
	file.open(address);

	if(!file.is_open()){
		std::cout << "Wrong address";
	} else {
		char temp[40];
		temp[0] = '\0';
		while (!file.eof()){
			file.read(temp, 40);
			for (int i = 0; i < file.gcount(); i++){
				std::cout << temp[i];
			}
		}
	}
}
