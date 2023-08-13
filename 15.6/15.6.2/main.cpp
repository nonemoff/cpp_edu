#include <iostream>
#include <vector>

int main(){
	std::vector<int> arr = {2, 7, 11, 15};
	int goal = 9;

	for (int i = 0; i < arr.size(); i++){
		if (arr[i] < goal){
			for (int j = i+1; j < arr.size(); j++){
				if(arr[j] < goal){
					if (arr[i] + arr[j] == goal) {
						std::cout << arr[i] << " " << arr[j] << std::endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
