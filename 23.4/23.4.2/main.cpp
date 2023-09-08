#include <iostream>

#define SPRING 0
#define SUMMER 0
#define AUTUMN 0
#define WINTER 1

#if SPRING
int main(){
	std::cout << "SPRING" << std::endl;
}
#endif

#if SUMMER
int main(){
	std::cout << "SUMMER" << std::endl;
}
#endif

#if AUTUMN
int main(){
	std::cout << "AUTUMN" << std::endl;
}
#endif

#if WINTER
int main(){
	std::cout << "WINTER" << std::endl;
}
#endif
