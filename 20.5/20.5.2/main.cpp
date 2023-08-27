#include <iostream>
#include <fstream>
#include <ctime>

void print(int x, int y, std::ofstream& file){
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			file << rand() % 2;
		}
		file << std::endl;
	}
}

int main(){
	std::srand(std::time(nullptr));
	std::ofstream file("files/pic.txt");

	int x, y;
	std::cout << "Input height: ";
	std::cin >> x;
	std::cout << "Input width: ";
	std::cin >> y;
	
	if (x < 0 || y < 0){
		std::cout << "Wrong Input!" << std::endl;
		return 1;
	}
	print(x, y, file);

	return 0;
}
	
