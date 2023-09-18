#include "cpu.h"
#include "ram.h"

extern std::vector<int> ram;

void compute(){
	std::cout << "Computing..." << std::endl;

	int sum = 0;
	for(int i = 0; i < ram.size(); i++){
		sum+=ram[i];
	}

	std::cout << "Total: " << sum << std::endl << std::endl;
}
