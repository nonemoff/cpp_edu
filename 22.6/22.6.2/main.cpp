#include <map>
#include <iostream>
#include <string>

int main(){
	std::map<std::string, int> dict;
	while(true){
		std::cout << "Your Input: ";
		std::string temp; std::cin >> temp;
		if (temp == "Next"){
			std::cout << dict.begin()->first << std::endl;
			dict.begin()->second--;
			if (dict.begin()->second == 0){
				dict.erase(dict.begin());
			}
		} else {
			if (dict.count(temp) == 0) {
				dict[temp] = 1;
			} else {
				dict[temp]++;
			}
		}
	}
	return 0;
}
