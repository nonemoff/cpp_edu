#include <iostream>
int route(int n, int k = 3, int start_pos = 0){
	if (start_pos == n) return 1;
	if (start_pos > n) return 0;
	int sum = 0;
	for (int i = 1; i <= k; i++){
		sum += route(n, k, start_pos + i);
	}
	return sum;
}

int main(){
	std::cout << route(4, 2) << std::endl;
	return 0;
}
