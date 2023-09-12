#include <iostream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>

int main(){
	std::cout << "Input timer: ";
	std::tm delta = {};
	std::cin >> std::get_time(&delta, "%M:%S");
	std::time_t timer = 0;
	std::time_t delta_t = delta.tm_min * 60 + delta.tm_sec;
	while(true){
		timer+=1;
		sleep(1);
		std::time_t temp = delta_t - timer;
		if (temp == 0){
			break;
		}
		std::tm* temp_tm = std::gmtime(&temp);
		std::cout << std::put_time(temp_tm, "%M:%S") << std::endl;
	}
	
	std::cout << "DING! DING! DING!" << std::endl;
}
