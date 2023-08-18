#include <iostream>
#include <string>
#include <sstream>

enum Switches 
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

int main(){
	Switches state;
	for (int day = 1; day < 3; day++){
		std::cout << "--- DAY " << day << " ---" << std::endl;
		for (int hour = 0; hour < 24; hour++){
			if (hour < 10){
				std::cout << "TIME: 0";
			} else {
				std::cout << "TIME: ";
			}
			std::cout << hour << ":00" << std::endl;
			
			//Input
			std::cout << "Temperature inside, temperature outside, movement, lights:" << std::endl;
			std::string input; std::getline(std::cin, input);
			std::stringstream input_stream(input);
			std::string t_in, t_out, mv, li;
			input_stream >> t_in >> t_out >> mv >> li;
			
			//Output
			if (state & WATER_PIPE_HEATING){
				//was on
				if (std::stoi(t_out) > 5){
					//makes off
					std::cout << "WATER PIPE HEATING: OFF" << std::endl;
					state &= ~Switches::WATER_PIPE_HEATING;
				}//else stay on
			} else {
				//was off
				if (std::stoi(t_out) < 0){
					//makes on
					std::cout << "WATER PIPE HEATING: ON" << std::endl;
					state |= Switches::WATER_PIPE_HEATING;
				}//else stay off
			}
		}
	}
	return 0;
}
