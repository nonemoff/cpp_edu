#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(){

	std::ifstream file;
	file.open("file.txt");

	if(!file.is_open()){
		std::cout << "Wrong file path" << std::endl;
	} else {
		std::vector<std::string> people;
		std::vector<int> money;

		int total = 0;
		while(!file.eof()){
			std::string temp, name, s_name, date, full_name;
			int amount;
			std::getline(file, temp);
			std::stringstream ss(temp);
			ss >> name >> s_name >> amount >> date;
			full_name = name + ' ' + s_name;

			int index = -1;
			for (int i = 0; i < people.size(); i++){
				if (people[i] == full_name){
					index = i;
				}
			}
			if (index == -1){
				people.push_back(full_name);
				money.push_back(amount);
			} else {
				money[index] += amount;
			}
			file >> std::ws;
		}
		int index = 0; 
		int max = 0;
		for (int i = 0; i < people.size(); i++){
			if (money[i] > max){
				max = money[i];
				index = i;
			}
		}
		std::cout << people[index] << ": " << money[index] << std::endl;
	}
	return 0;
}
