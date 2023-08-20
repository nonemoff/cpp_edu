#include <iostream>

void pswap(int* pa, int* pb){
	int c = *pb;
	*pb = *pa;
	*pa = c;
}

int main(){
	int a = 10;
	int b = 20;
	std::cout << "Before pswap: " << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	pswap(&a, &b);

	std::cout << "After pswap: " << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	return 0;
}

