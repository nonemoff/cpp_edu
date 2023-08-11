#include <iostream>

int main(){
	int startSupply;
	int decreaseSpeed;
	int currentSupply;

	std::cout << "Input the start supply size" << std::endl;
	std::cin >> startSupply;
	std::cout << "Input the decrease speed" << std::endl;
	std::cin >> decreaseSpeed;
	
	currentSupply = startSupply;
	for(int daysCounter = 0; currentSupply >= 0; currentSupply -= decreaseSpeed, daysCounter++){
		std::cout << "After\t" << daysCounter << "\tdays your supply will be\t" << currentSupply \
			<< "\tkg." << std::endl;
		if (daysCounter == 100){
			break;
		}
	}
	return 0;
}

