#include <iostream>
#include <vector>
#include <cmath>
int main(){
	
	std::vector<int> arr = {5, 10, -15, 20, -30, 5, 10, 15, 15, -20, 80, -100, 90};


	int current_sum = 0;
	int current_index_start = 0;
	int current_index_end = -1;
	int maximum_sum = 0;
	int maximum_index_start = 0;
	int maximum_index_end = 0;

	for (int num : arr){
		current_sum += num;
		current_index_end+=1;
		if (maximum_sum < current_sum){
			maximum_index_start = current_index_start;
			maximum_index_end = current_index_end;
			maximum_sum = current_sum;
		} else if (current_sum <= 0){
			current_index_start = current_index_end + 1;
			current_sum = 0;
		}
	}

	std::cout << "maximum sum: " << maximum_sum << std::endl;
	std::cout << "start position: " << maximum_index_start << std::endl;
	std::cout << "end position: " << maximum_index_end << std::endl;
	return 0;
}
