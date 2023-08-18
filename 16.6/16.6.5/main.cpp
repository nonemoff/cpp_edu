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

void pipe_control(std::string t_out, int& state){
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

void climat_control(std::string t_in_string, int& state){
	int t_in = std::stoi(t_in_string);
	if (state & HEATERS){
		//heaters were on. conditioner was off
		if (t_in >= 25){
			//makes heaters off
			std::cout << "HEATERS: OFF" <<std::endl;
			state &= ~HEATERS;
		}
		if (t_in > 30){
			//makes conditioner on
			std::cout << "CONDITIONER: ON" << std::endl;
			state |= CONDITIONER;
		}
	} else if(state & CONDITIONER){
		//heaters were off. conditioner was on
		if (t_in < 25){
			//makes conditioner off
			std::cout << "CONDITIONER: OFF" << std::endl;
			state &= ~CONDITIONER;
		} 
		if (t_in < 22){
			//makes heaters on
			std::cout << "HEATERS ON" << std::endl;
			state |= HEATERS;
		}
	} else {
		//heaters were off. conditioner was off
		if (t_in < 22){
			//makes heaters on
			std::cout << "HEATERS ON" << std::endl;
			state |= HEATERS;
		} 
		if (t_in > 30){
			//makes conditioner on
			std::cout << "CONDITIONER: ON" << std::endl;
			state |= CONDITIONER;
		}
	}
}

void light_control(std::string mv, std::string li, int& state, int time){
	int color = 5000;
	if (time > 16 && time < 21){
		color -= (time % 16) * (5000 - 2700)/4;
	} else if (time >= 21){
		color = 2700;
	}

	//outside
	if (time == 6 && state & LIGHTS_OUTSIDE){
		//makes off
		std::cout << "LIGHTS OUTSIDE: OFF" << std::endl;
		state &= ~LIGHTS_OUTSIDE;
	}

	if (state & LIGHTS_OUTSIDE){
		//lights outside were on
		if (mv != "yes" && (time > 16 || time < 6)){
			//makes off
			std::cout << "LIGHTS OUTSIDE: OFF" << std::endl;
			state &= ~LIGHTS_OUTSIDE;
		} //else stay on
	} else {
		//lights outside were off
		if (mv == "yes" && (time > 16 || time < 6)){
			//makes on
			std::cout << "LIGHTS OUTSIDE: ON" << std::endl;
			state |= LIGHTS_OUTSIDE;
		} //else stay off
	}

	//inside
	if (state & LIGHTS_INSIDE){
		//lights inside were on
		if (li != "on"){
			//makes off
			std::cout << "LIGHTS INSIDE: OFF" << std::endl;
			state &= ~LIGHTS_INSIDE;
		} //else stay on
	} else {
		//lights inside were off
		if (li == "on"){
			//makes on
			std::cout << "LIGHTS INSIDE: ON" << std::endl;
			state |= LIGHTS_INSIDE;
		} //else stay off
	}

	if (state & LIGHTS_OUTSIDE || state & LIGHTS_INSIDE){
		std::cout << "COLOR: " << color << "K" << std::endl;
	}
}

int main(){
	int state = 0;
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
			pipe_control(t_out, state);
			climat_control(t_in, state);
			light_control(mv, li, state, hour);
			std::cout << std::endl;
		}
	}
	return 0;
}
