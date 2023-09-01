#include <iostream>
#include <fstream>
#include <string>



std::string path = "files/transactions";

struct Transaction{
	std::string f_name;
	std::string s_name;
	std::string date;
	int amount;
};

void list(){
	std::ifstream file(path);
	if (!file.is_open()){
		std::cout << "Wrong path to file" << std::endl;
	} else {
		Transaction temp;
		while(true){
			file >> temp.f_name;
			if (file.eof()){
				break;
			} else {
				file >> temp.s_name >> temp.date >> temp.amount;
				std::cout << temp.f_name << " " << temp.s_name << " " << temp.date << " " << temp.amount << std::endl;
			}
		}
	}
	file.close();
}

void add(){
	std::ofstream file(path, std::ios::app);
	if (!file.is_open()){
		std::cout << "Wrong path to file" << std::endl;
	} else {
		Transaction temp;
		while (true){
			std::cout << "Input new transaction:" << std::endl;
			std::cout << "Input your first name: ";
			std::cin >> temp.f_name;
			std::cout << "Input your second name: ";
			std::cin >> temp.s_name;
			std::cout << "Input date in DD:MM:YYYY format: ";
			std::cin >> temp.date;
			if (temp.date[2] == ':' && temp.date[5] == ':'){
				std::cout << "Input the amount: ";
				std::cin >> temp.amount;
				break;
			} else {
				std::cout << "Wrong date input!" << std::endl;
			}
		}
		file << temp.f_name << " " << temp.s_name << " " << temp.date << " " << temp.amount << std::endl;
	}
	file.close();
}

int main(){
	while(true) {
		std::cout << "--- Commands ---" << std::endl;
		std::cout << "add - to add transaction" << std::endl;
		std::cout << "list - to get list of transactions" << std::endl;
		std::cout << "end - to end the program" << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << "Input your command: ";
		std::string command; std::cin >> command;

		if (command == "add"){
			std::cout << "Adding new transaction:" << std::endl;
			add();
		} else if (command == "list"){
			std::cout << "List of transactions:" << std::endl;
			list();
		} else if (command == "end"){
			std::cout << "Exiting..." << std::endl;
			break;
		} else {
			std::cout << "Wrong input. Try again!" << std::endl << std::endl;
		}
	}
	return 0;
}
