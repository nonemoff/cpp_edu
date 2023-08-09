#include <iostream>
#include <vector>

int main(){
	std::vector<float> prices;
	std::vector<int> items;
	
	int prices_num, items_num;
	std::cout << "Input number of prices: ";
	std::cin >> prices_num;

	{
		float temp;
		for(int i = 0; i < prices_num; i++){
			std::cout << "Input price of item #" << i+1 << ": ";
			std::cin >> temp;
			prices.push_back(temp);
		}

		for(int i = 0; i < prices_num; i++){
			std::cout << "Input the numer of item #" << i+1 << ": ";
			std::cin >> temp;
			items.push_back(temp);
        	}
	}
	float sum = 0;	
	for(int i = 0; i < prices_num; i++){
		sum += prices[i]*items[i];
	}

	std::cout << "Total: " << sum << std::endl;

	return 0;
}
