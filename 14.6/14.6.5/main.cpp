#include <iostream>
#include <iomanip>
#include <stdlib.h>

int pop(bool arr[][12], int x1, int x2, int y1, int y2){
	int pop_counter = 0;

	for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++){
		for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++){
			if(arr[x][y]){
				std::cout << "POP!" << std::endl;
				pop_counter++;
				arr[x][y] = false;
			}
		}
	}
	return pop_counter;
}

void display(bool arr[][12]){
	std::cout << std::endl;
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			if (arr[i][j]) std::cout << std::setw(2) << "X";
			else std::cout << std::setw(2) << "O";
		}
		std::cout << std::endl;
	}
}

void fill(bool arr[][12]){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			arr[i][j] = true;
		}
	}
}

bool is_correct(int v){
	return (v >= 0) && (v <= 11);
}

int main(){
	bool arr[12][12];
	while (true){
		std::cout << "Let`s POP!" << std::endl;
		fill(arr);
		int pop_counter = 0;
		while(pop_counter < 144){
			int x1, x2, y1, y2;
			display(arr);
			while(true){
				std::cout << std::endl << "Input the first point coordinates. X, Y must be in range [0,11]" << std::endl;
				std::cout << "X1: ";
				std::cin >> x1;
				std::cout << "Y1: ";
				std::cin >> y1;
				std::cout << "X2: ";
				std::cin >> x2;
				std::cout << "Y2: ";
				std::cin >> y2;
				if (is_correct(x1) && is_correct(x2) && is_correct(y1) && is_correct(y2)){
					break;
				} else {
					std::cout << "Incorrect input. Try again!" << std::endl;
				}
			}
			pop_counter += pop(arr, x1, x2, y1, y2);
		}
		std::cout << "Nothing to POP! FIXING ISSUES." << std::endl << std::endl;
	}

	return 0;
}

