#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int>& arr){
	for (int i = arr.size()-1; i > 0; i--){
		if (arr[i] < arr[i-1]){
			std::swap(arr[i], arr[i-1]);
		} else {
			break;
		}
	}
}
int main(){
	std::vector<int> arr;

	while(true){
		int temp;
		std::cout << "Input next value: ";
		std::cin >> temp;
		if (temp != -1){
			if (arr.size() < 5){
				arr.push_back(temp);
				sort(arr);
			} else {
				arr[4] = temp;
				sort(arr);
			}
		} else if (temp == -1){
			if(arr.size() >= 5 ){
				for (int i = 0; i < arr.size(); i++){
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
				std::cout << "fifth element is: " << arr[4] << std::endl;
			} else {
				std::cout << "array nas not fifth element!" << std::endl;
			}

		}
	}
	return 0;
}
