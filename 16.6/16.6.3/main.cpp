#include <iostream>
#include <sstream>
#include <string>

int main(){
	std::cout << "Inpur your operation: " << std::endl;
	std::string buffer; 
	std::getline (std::cin, buffer);
	std::stringstream buffer_stream(buffer);
	std::string a, b, oper;
	buffer_stream >> a >> oper >> b;

	double a_d, b_d, result;
	a_d = std::stod(a);
	b_d = std::stod(b);
	if (oper == "+") {
		result = a_d + b_d;
	} else if (oper == "-"){
		result = a_d - b_d;
	} else if (oper == "*"){
		result = a_d * b_d;
	} else if (oper == "/"){
		result = a_d / b_d;
	} else {
		std::cout << "Wrong input!" << std::endl;
		return 0;
	}
	std::cout << "Result: " << result << std::endl;	
	return 0;
}
