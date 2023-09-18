#include "disk.h"
#include "ram.h"

extern std::vector<int> ram;

void load() {
  std::ifstream file("files/file.txt");
  if (!file.eof()) {
    for (int i = 0; i < ram.size(); i++) {
      file >> ram[i];
    }
    std::cout << "Loaded" << std::endl;
  } else {
    std::cout << "Disk is empty" << std::endl;
  }
}

void save() {
  std::ofstream file("files/file.txt");
  for (int i = 0; i < ram.size(); i++) {
    file << ram[i];
  }
  std::cout << "Saved" << std::endl;
}
