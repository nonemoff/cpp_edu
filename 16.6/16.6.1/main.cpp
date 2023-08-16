#include <iostream>

int main(){
	float speed = 0.f;
	float epsilon = 0.1f;
	do {
		char speed_str[4];
		float delta;
		std::sprintf(speed_str, "%.1f", speed);
		std::cout << "Current speed: " << speed_str << std::endl;
		std::cout << "Input how speed changed: ";
		std::cin >> delta;
		speed += delta;
	} while (speed > 0 + epsilon);
	std::cout << "Car stoped!" << std::endl;
	return 0;
}
