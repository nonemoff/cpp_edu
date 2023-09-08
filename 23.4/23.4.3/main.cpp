#include <iostream>
#include <vector>

#define FOR for (int i = 0; i < 10; i++)
#define IF(OP) if(arr[i] OP 20)
#define OUTPUT(TEXT) std::cout << "vagon #" << i + 1 << " " << TEXT << std::endl;


int main(){
	std::vector<int> arr(10, 0);
	FOR{
		std::cout << "input the number of people in vagon #" << i+1 << std::endl; 
		std::cin >> arr[i];
	}
	int sum = 0;
	FOR{
		sum += arr[i];
	}
	FOR{
		IF(>=){
			OUTPUT("is full");
		}
	}
	FOR{
		IF(<){
			OUTPUT("has some seats");
		}
	}
	std::cout << "Total people in vagons: " << sum << std::endl;
}
