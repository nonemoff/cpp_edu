#include "disk.h"
#include "ram.h"

extern std::vector<int> ram;

void load() {
  std::ifstream file("file.txt");
  if (!file.eof() && file.is_open()) {
    for (int i = 0; i < ram.size(); i++) {
      file >> ram[i];
    }
    std::cout << "Loaded" << std::endl;
  } else if (file.eof()){
    std::cout << "Disk is empty" << std::endl;
  } else {
		std::cout << "Error with disk" << std::endl;
	}
	file.close();
}

void save() {
  std::ofstream file("file.txt");
  for (int i = 0; i < ram.size(); i++) {
    file << ram[i];
  }
  std::cout << "Saved" << std::endl;
	file.close();
}
