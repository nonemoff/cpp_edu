#include <iostream>
#include <string>
#include <cmath>

void add();
void substract();
void scale();
void length();
void normalize();

struct Vctr{
	float x;
	float y;
};

int main(){
		std::cout << "--- OPTIONS ---"<< std::endl;
		std::cout << "add - suming two vectors" << std::endl;
		std::cout << "substract - substracting two vectors" << std::endl;
		std::cout << "scale - multiplying vector on scalar" << std::endl;
		std::cout << "length - finding vector`s length" << std::endl;
		std::cout << "normalize - normalizing vector" << std::endl;
		std::cout << "exit - exiting program" << std::endl << std::endl;
	while (true){
		std::cout << "Input the option: ";
		std::string com; std::cin >> com;
		if (com == "add"){
			add();
		} else if (com == "substract"){
			substract();
		} else if (com == "scale"){
			scale();
		} else if (com == "length"){
			length();
		} else if (com == "normalize"){
			normalize();
		} else if (com == "exit"){
			std::cout << "Exiting..." << std::endl;
			return 0;
		} else {
			std::cout << "Wrong input!" << std::endl;
		}
	}
	return 0;
}


void add(){
	//  Input
	Vctr a, b, c;
	std::cout << "Input coordinates of vector a: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> a.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> a.y;
	std::cout << "Input coordinates of vector b: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> b.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> b.y;

	//  Adding
	c.x = a.x + b.x;
	c.y = a.y + b.y;

	//  Output
	std::cout << "Result:" << std::endl;
	std::cout << "X: " << c.x << " Y: " << c.y << std::endl;
}


void substract(){
	//  Input
	Vctr a, b, c;
	std::cout << "Input coordinates of vector a: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> a.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> a.y;
	std::cout << "Input coordinates of vector b: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> b.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> b.y;

	//  Substracting
	c.x = a.x - b.x;
	c.y = a.y - b.y;

	//  Output
	std::cout << "Result:" << std::endl;
	std::cout << "X: " << c.x << " Y: " << c.y << std::endl;
}


void scale(){
	//  Input
	Vctr a, c;
	float scal;
	std::cout << "Input coordinates of vector a: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> a.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> a.y;
	std::cout << "Input scalar:" << std::endl;
	std::cin >> scal;

	//  Scaling
	c.x = a.x * scal;
	c.y = a.y * scal;

	// Output
	std::cout << "Result:" << std::endl;
	std::cout << "X: " << c.x << " Y: " << c.y << std::endl;
}


void length(){
	//  Input
	Vctr a;
	float len;
	std::cout << "Input coordinates of vector a: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> a.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> a.y;

	// Counting
	len = std::sqrt(std::pow(a.x,2) + std::pow(a.y,2));

	// Output
	std::cout << "Result:" << std::endl;
	std::cout << len << std::endl;
}
void normalize(){
	//  Input
	Vctr a, c;
	std::cout << "Input coordinates of vector a: " << std::endl;
	std::cout << "Input x:" << std::endl;
	std::cin >> a.x;
	std::cout << "Input y:" << std::endl;
	std::cin >> a.y;
	
	//  Normalizing
	float len_rev = 1/std::sqrt(std::pow(a.x,2) + std::pow(a.y,2));
	c.x = a.x * len_rev;
	c.y = a.y * len_rev;

	// Output
	std::cout << "Result:" << std::endl;
	std::cout << "X: " << c.x << " Y: " << c.y << std::endl;	
}
