#include <iostream>
#include <vector>
#include <iomanip>

int main(){

	std::vector<int> arr;
	
	while(true){
		std::cout << "Input the number: ";
		int temp; std::cin >> temp;

		if (temp != -2){
			arr.push_back(temp);
		} else {
			int index_negative, index_positive;
			if (arr[0] < 0 && arr.size() > 1){
				for (int i = 0; i < arr.size() - 1; i++){
					if (arr[i] < 0 && arr[i+1] >= 0){
						index_negative = i; 
						index_positive = i + 1;
						break;
					}
				}
				while(index_negative != -1 || index_positive != arr.size()){
					if (index_negative != -1 && index_positive != arr.size()){
						if (std::abs(arr[index_negative]) < arr[index_positive]){
							std::cout << std::setw(3) << arr[index_negative];
							index_negative--;
						} else {
							std::cout << std::setw(3) << arr[index_positive];
							index_positive++;
						}
					} else if (index_negative == -1) {
						std::cout << std::setw(3) << arr[index_positive];
						index_positive++;
					} else {
						std::cout << std::setw(3) << arr[index_negative];
						index_negative--;
					}
					std::cout << " ";
				}
			} else {
				for (int i = 0; i < arr.size(); i++){
					std::cout << std::setw(3) << arr[i] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
		
	return 0;
}
