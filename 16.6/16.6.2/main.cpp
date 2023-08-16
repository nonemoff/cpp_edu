#include <iostream>

int main(){

	std::string int_part, dec_part;
	std::cout << "Input the integer part: ";
	std::cin >> int_part;
	std::cout << "Input the decimal part: ";
	std::cin >> dec_part;

	std::string result = int_part + '.' + dec_part;
	double d_result = std::stod(result);
	std::cout << d_result << std::endl;
	return 0;
}
