#include <iostream>
#include <fstream>
#include <string>

int main(){

	std::ifstream file;
	file.open("words.txt");

	if(!file.is_open()){
		std::cout << "words.txt not found" << std::endl;
	} else {
		std::string temp, target;
		std::cout << "Input word to find: ";
		std::cin >> target;
		int counter = 0;
		while(file >> temp){
			if(temp == target) counter++;
		}
		std::cout << "Word was found: " << counter << " times" << std::endl;
	}

	return 0;
}
