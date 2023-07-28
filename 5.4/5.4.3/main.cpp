#include <iostream>

int main(){
	int naggetsQuantity;
	std::cout << "Введите кол-во наггетсов: " << std::endl;
	std::cin >> naggetsQuantity;
	if (((naggetsQuantity % 9) % 6) == 0 || ((naggetsQuantity % 6) % 9) == 0){
		std::cout << "Такое количество можно купить" << std::endl;
	} else {
		std::cout << "Такое количество нельзя купить" << std::endl;
	}
	return 0;
}

