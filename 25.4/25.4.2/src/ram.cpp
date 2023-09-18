#include "ram.h"

std::vector<int> ram(8,0);

std::vector<int> read(){
	std::vector<int> arr;
	for(int i = 0; i < ram.size(); i++){
		arr.push_back(ram[i]);
	}
	return arr;
}

void write(std::vector<int> arr){
	for (int i = 0; i < arr.size(); i++){
		ram[i] = arr[i];
	}
}
