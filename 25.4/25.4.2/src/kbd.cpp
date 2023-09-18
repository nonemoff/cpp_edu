#include "kbd.h"
#include "ram.h"

extern std::vector<int> ram;

void input(){
	std::cout << "Input numbers: " << std::endl;
	for (int i = 0; i < ram.size(); i++){
		std::cout << "Buffer[" << i << "]: ";
		std::cin >> ram[i];
	}
	std::cout << "Saved in ram" << std::endl;
}
