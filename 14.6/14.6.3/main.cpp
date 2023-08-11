#include <iostream>
#include <iomanip>


void display(int arr[][4]){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			std::cout << std::setw(3) << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


int main(){

	int a[4][4], b[4][4];

	for (int i = 0; i < 2; i++){
		if(i == 0) std::cout << "Input the Matrix A." << std::endl;
		else std::cout << "Input the Matrix B." << std::endl;

		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				std::cout << "[" << j << "][" << k << "]: ";
				if(i == 0) std::cin >> a[j][k];
				else std::cin >> b[j][k];
			}
		}
	}

	
	std::cout << std::endl;
	std::cout << "Matrix A before:" << std::endl;
	display(a);
	std::cout << "Matrix B before:" << std::endl;
	display(b);

	bool equal = true;
	for (int i = 0; i < 4 && equal; i++){
		for (int j = 0; j < 4 && equal; j++){
			if (a[i][j] == b[i][j] && i != j){
				a[i][j] = 0;
			} else if (a[i][j] != b[i][j]){
				equal = false;
			}
		}
	}

	std::cout << std::endl;
	std::cout << "Matirix A after:" << std::endl;
	display(a);
	std::cout << "Matrix B after:" << std::endl;
	display(b);

	return 0;
}
