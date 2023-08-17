#include <iostream>
#include <string>
#include <cstring>

enum Note 
{ 
    DO = 1, 
    RE = 2, 
    MI = 4, 
    FA = 8, 
    SOL = 16, 
    LA = 32, 
    SI = 64 
};

void add_notes(int arr[12], std::string str, int index){
	for (int i = 0; i < str.length(); i++){
		arr[index] |= 1 << (int) (str[i] - '0') - 1;
	}
}
void print_notes(int notes){
	for (int i = 0; i < 7; i++){
		int temp = 1 << i;
		switch (notes & temp){
			case Note::DO: std::cout << "DO "; break;
			case Note::RE: std::cout << "RE "; break;
			case Note::MI: std::cout << "MI "; break;
			case Note::FA: std::cout << "FA "; break;
			case Note::SOL: std::cout << "SOL "; break;
			case Note::LA: std::cout << "LA "; break;
			case Note::SI: std::cout << "SI "; break;
			default: break;
		}
	}
	std::cout << std::endl;
}


int main(){
	int array[12];
	std::memset(array, 0, sizeof(int)*12);
	std::string temp_string;
	for (int i = 0; i < 12; i++){
		std::cout << "Input notes #" << i+1 << ": ";
		std::cin >> temp_string;
		add_notes(array, temp_string, i);
	}
	std::cout << "Your melody: " << std::endl;
	for(int i = 0; i < 12; i++){
		std::cout << "#" << i+1 << std::endl;
		print_notes(array[i]);
	}
	return 0;
}

