#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

void fill(){
	std::ofstream currency("files/currency.txt");
	std::ofstream states("files/states.txt");
	std::srand(std::time(nullptr));
	int money[] = {100, 200, 500, 1000, 2000, 5000};
	for (int i = 0; i < 1000; i++){
		currency << money[rand()%6] << std::endl;
		states << 1 << std::endl;
	}
	
	currency.close();
	states.close();
}

void set_states(std::vector<int>& states_temp){
	std::cout << "*** start" << std::endl;
	std::ofstream states("files/states.txt");
	for (int i = 0; i < 1000; i++){
		states << states_temp[i] << std::endl;
	}
	states.close();
	std::cout << "** end" << std::endl;
}

void get_states(std::vector<int>& states_temp){
	std::ifstream states("files/states.txt");
	for (int i = 0; i < 1000; i++){
		int temp; states >> temp;
		states_temp.push_back(temp);
	}
	states.close();
}

void currency_counter(std::vector<int>& money){
	std::ifstream currency("files/currency.txt");
	std::ifstream states("files/states.txt");

	for (int i = 0; i < 1000; i++){
		int current_currency;
		currency >> current_currency;
		int current_state;
		states >> current_state;
		if (current_state == 1){
			switch (current_currency){
			case 100:
				money[0] += 1;
				break;
			case 200:
				money[1] += 1;
				break;
			case 500:
				money[2] += 1;
				break;
			case 1000:
				money[3] += 1;
				break;
			case 2000:
				money[4] += 1;
				break;
			case 5000:
				money[5] += 1;
				break;
			}
		}		
	}
	for (int i = 0; i < 6; i++){
		std::cout << money[i] << " ";
	}
	std::cout << std::endl;
}
	

int main(){
	while (true){
		std::cout << "--- INPUT MODE ---" << std::endl;
		std::cout << "Input + to fill ATF" << std::endl;
		std::cout << "Input - to take money" << std::endl;
		char mode; std::cin >> mode;
		if (mode == '+'){
			fill();
		} else {
			std::cout << "------------------" << std::endl;
			std::cout << "Input the amount: ";
			int amount; std::cin >> amount;
			if (amount <= 0 || (amount % 100 != 0)){
				std::cout << "Wrong input! Amount must be more than 0 and ends on 00" << std::endl;
			} else {
				if (amount <= 0 || amount % 100 != 0){
					std::cout << "Wrong input. Your amount must be more than 0 and ends on 00" << std::endl;
				} else {
					std::vector<int> money(6,0);
					currency_counter(money);
					while (amount / 5000 != 0 && money[5] != 0){
						amount-=5000;
						money[5] -= 1;
					} 
					while (amount / 2000 != 0 && money[4] != 0){
						amount-=2000;
						money[4] -= 1;
					} 
					while (amount / 1000 != 0 && money[3] != 0){
						amount-=1000;
						money[3] -= 1;
					} 
					while (amount / 500 != 0 && money[2] != 0){
						amount-=500;
						money[2] -= 1;
					} 
					while (amount / 200 != 0 && money[1] != 0){
						amount-=200;
						money[1] -= 1;
					} 
					while (amount / 100 != 0 && money[0] != 0){
						amount-=100;
						money[0] -= 1;
					} 
					if (amount != 0){
						std::cout << "ERROR! Not enough currency!" << std::endl;
					} else {
						std::vector<int> states_temp;
						get_states(states_temp);
						std::ifstream currency("files/currency.txt");
						for (int i = 0; i < 1000; i++){
							int temp; currency >> temp;
							switch (temp){
								case 5000:
									if(money[5] != 0){
										money[5] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
								case 2000:
									if(money[4] != 0){
										money[4] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
								case 1000:
									if(money[3] != 0){
										money[3] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
								case 500:
									if(money[2] != 0){
										money[2] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
								case 200:
									if(money[1] != 0){
										money[1] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
								case 100:
									if(money[0] != 0){
										money[0] -= 1;
									} else {
										states_temp[i] = 0;
									}
									break;
							}
						}
						set_states(states_temp);
						std::cout << "Transaction completed!" << std::endl;
					}
				}
			}
		}
	}
	return 0;
}
