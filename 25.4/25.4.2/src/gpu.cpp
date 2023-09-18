#include "gpu.h"
#include "ram.h"

extern std::vector<int> ram;

void display(){
	std::cout << "Buffer: ";
	for(int i = 0; i < ram.size(); i++){
		std::cout << ram[i] << " ";
	}
	std::cout << std::endl;
}
