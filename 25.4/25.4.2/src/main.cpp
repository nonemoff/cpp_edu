#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

#include <string>

void print() {
  std::cout << "List of commands:" << std::endl;
  std::cout << "help\nsum\nsave\nload\ninput\ndisplay\nexit\n" << std::endl;
}

int main() { 
	extern std::vector<int> ram;
	print();
	while(true){
		std::cout << "Input command: ";
		std::string command;
		std::cin >> command;

		if (command == "help"){
			print();
		} else if (command == "exit"){
			break;
		} else if (command == "sum"){
			compute();
		}else if (command == "save"){
			save();
		} else if (command == "load"){
			load();
		} else if (command == "input"){
			input();
		} else if (command == "display"){
			display();
		} else {
			std::cout << "Wrong input" << std::endl;
		}
	}
	return 0; }
