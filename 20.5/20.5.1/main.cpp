#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void add_f_name(std::ofstream& file){
	std::string temp;
	std::cout << "Input your first name: ";
	std::cin >> temp;
	file << temp << " ";
}

void add_s_name (std::ofstream& file){
	std::string temp;
	std::cout << "Input your second name: ";
	std::cin >> temp;
	file << temp << " ";
}

void add_date (std::ofstream& file){
	std::string temp;
	std::cout << "Input current date: ";
	std::cin >> temp;
	file << temp << " ";
}

void add_sum (std::ofstream& file){
	std::string temp;
	std::cout << "Input amount: ";
	std::cin >> temp;
	file << temp << " ";
}
	
int main(){
	
	std::ofstream file("files/log.txt", std::ios::app);

	add_f_name(file);
	add_s_name(file);
	add_date(file);
	add_sum(file);

	file.close();

	return 0;
}
