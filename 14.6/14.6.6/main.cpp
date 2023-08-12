#include <cmath>
#include <iostream>
#include <iomanip>

int f(int x, int y){
	return x * (y % 2 == 0) + (-x + 4) * (y % 2 == 1);
}

void display(int arr[][5]){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			std::cout << std::setw(2) << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(){
	int arr[5][5];
	int var = 0;

	for (int y = 0; y < 5; y++){
		for (int x = 0; x < 5; x++){
			arr[y][f(x, y)] = var;
			var++;
		}
	}

	display(arr);
	return 0;
}
