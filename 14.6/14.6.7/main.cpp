#include <iostream>
#include <iomanip>

int main(){

	int world[5][5][10];

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			while (true){
				std::cout << "Input the heignt of [" << i << ";" << j << "]: ";
				int temp;
				std::cin >> temp;
				if (temp >= 0 && temp < 10){
					for (int k = 0; k < 10; k++){
						world[i][j][k] = (int) k <= temp;
					}
					break;
				} else {
					std::cout << "Height might be in range [0;9]" << std::endl;
				}
			}
		}
	}
	
	int height;
	std::cout << "Input the height of your slice: ";
	while (true){
		std::cin >> height;
		if (height >= 0 && height < 10){
			break;
		} else {
			std::cout << "Height must be in range [0;9]" << std::endl;
		}
	}
	
	std::cout << std::endl << "Your slice: " << std::endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (world[i][j][height]){
				std::cout << std::setw(2) << "1";
			} else {
				std::cout << std::setw(2) << "0";
			}
		}
		std::cout << std::endl;
	}
		

	return 0;
}
