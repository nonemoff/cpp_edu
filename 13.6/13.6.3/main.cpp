#include <iostream>
#include <vector>

int main(){
	std::vector<int> arr(20);
	for (int i = 0, temp; ; i++){
		std::cout << "Input number #" << i+1 << ": ";
		std::cin >> temp;
		if (temp == -1){
			std::cout << "arr: ";
			if(i < 20){
				for(int j = 0; j < i; j++){
					std::cout << arr[j] << " ";
				}
			} else {
				for(int j = 0; j < 20; j++){
					std::cout << arr[(i+j)%20] << " ";
				}
			}
			i--;
			std::cout << std::endl;
		} else {
			arr[i%20] = temp;	
		}
	}
	return 0;
}
