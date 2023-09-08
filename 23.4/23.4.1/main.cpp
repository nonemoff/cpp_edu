#include <iostream>

#define OUTPUT "input the day number: "
#define ERROR "wrong input"
#define MON "mon"
#define TUES "tues"
#define WEDNES "wednes"
#define THURS "thurs"
#define FRI "fri"
#define SATUR "satur"
#define SUN "sun"
#define DAY "day"

enum DAYS{
	MONDAY = 1,
	TUESDAY = 2,
	WEDNESDAY = 3,
	THURSDAY = 4,
	FRIDAY = 5,
	SATURDAY = 6,
	SUNDAY = 7
};

int main(){
	std::cout << OUTPUT << std::endl;
	int day; std::cin >> day;
	
	switch(day){
		case MONDAY:
			std::cout << MON DAY << std::endl;
			break;
		case TUESDAY:
			std::cout << TUES DAY << std::endl;
			break;
		case WEDNESDAY:
			std::cout << WEDNES DAY << std::endl;
			break;
		case THURSDAY:
			std::cout << THURS DAY << std::endl;
			break;
		case FRIDAY:
			std::cout << FRI DAY << std::endl;
			break;
		case SATURDAY:
			std::cout << SATUR DAY << std::endl;
			break;
		case SUNDAY:
			std::cout << SUN DAY << std::endl;
			break;
		default:
			std::cout << ERROR << std::endl;
			break;
	}


	return 0;
}
