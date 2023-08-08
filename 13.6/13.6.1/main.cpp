#include <iostream>
#include <vector>

int main() {

	int arr_size = 0;
	std::cout << "Input the array size: ";
	std::cin >> arr_size;

	std::vector<int> arr;
	for(int i = 0; i < arr_size; i++){
		int temp;
		std::cout << "Input your " << i+1 << " number: ";
		std::cin >> temp;
		arr.push_back(temp);
	}

	int removeable;	
	std::cout << "Input wich number to remove: ";
	std::cin >> removeable;

	for(int i = arr.size() - 1; i >= 0; i--){
		if (arr[i] == removeable){
			arr.erase(arr.begin() + i);	
		}
	}

	for(int i = 0; i < arr.size(); i++){
		std::cout << arr[i] << std::endl;	
	}
	std::cout << std::endl;
	return 0;
}
