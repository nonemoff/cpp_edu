#include <iostream>

void pswap(int* arr){
	for(int i = 0; i < 5; i++){
		int temp;
		temp = *(arr + i);
		*(arr + i) = *(arr + 9 - i);
		*(arr + 9 - i) = temp;
	}
}

void print(int* arr){
	for (int i = 0; i < 10; i++){
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
}

int main(){
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "Before:" << std::endl;
	print(arr);

	pswap(arr);

	std::cout << "After: " << std::endl;
	print(arr);

	return 0;
}
