#include <iostream>
#include <vector>

#define INPUT for(int i = 1; i <= 10; i++){std::cout << "input the number of people in vagon #" << i << std::endl; std::cin >> arr[i-1];}

#define GET_SUM for (int i = 0; i < 10; i++){sum += arr[i];}

#define OUTPUT_FULL for (int i = 0; i < 10; i++){if(arr[i] > 20){std::cout << "vagon #" << i+1 << " is full" << std::endl;}}

#define OUTPUT_HAVE_SEATS for (int i = 0; i < 10; i++){if(arr[i] < 20){std::cout << "vagon #" << i+1 << " has some seats" << std::endl;}}


int main(){
	std::vector<int> arr(10, 0);
	INPUT;
	int sum = 0;
	GET_SUM;
	OUTPUT_FULL;
	OUTPUT_HAVE_SEATS;
	std::cout << "Total people in vagons: " << sum;
}


