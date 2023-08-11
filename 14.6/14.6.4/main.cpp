#include <iostream> 
#include <iomanip>


void display (float arr[][4]){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			std::cout << std::setw(4) <<  arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(){
	float a[4][4], b[4], c[4];

	std::cout << "Input the Matrix A:" << std::endl;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			std::cout << "A[" << i << "][" << j << "]: ";
			std::cin >> a[i][j];
		}
	}

	std::cout << "Input the Vector B:" << std::endl;
	for (int i = 0; i < 4; i++){
		std::cout << "B[" << i << "]: ";
		std::cin >> b[i];
	}

	for (int i = 0; i < 4; i++){
		float sum = 0;
		for (int j = 0; j < 4; j++){
			sum += a[i][j] * b[j];
		}
		c[i] = sum;
	}
	
	std::cout << "C: ";
	for (int i = 0; i < 4; i++){
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
