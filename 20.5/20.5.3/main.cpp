#include <iostream>
#include <fstream>
#include <string>

void fishing(std::ifstream& fish, std::ofstream& basket){
	
	std::string kind;

	std::cout << "Input the kind of fish: ";
	std::cin >> kind;

	int counter = 0;
	while (!fish.eof()){
		std::string temp;
		fish >> temp;
		if (temp == kind){
			basket << temp << std::endl;
			counter++;
		}
	}
	std::cout << "Total: " << counter << " fishes" << std::endl;
}



int main(){

	std::ifstream fish("files/fish.txt");
	std::ofstream basket("files/basket.txt", std::ios::app);
	
	fishing(fish, basket);
	
	return 0;
}
