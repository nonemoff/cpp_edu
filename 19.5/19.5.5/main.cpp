#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main(){
	std::vector<bool> sector(13, false);
	int score_team = 0;
	int score_viewer = 0;
	
	std::string base_q = "files/q";
	std::string base_a = "files/a";

	int current_pos = 0;
	for (int i = 0; i < 13; i++){
		std::cout << "Input the offset: ";
		int offset; std::cin >> offset;

		current_pos = (current_pos + offset) % 13;

		while(sector[current_pos]) current_pos++;
		sector[current_pos] = true;
		std::cout << "Sector #" << current_pos + 1 << std::endl;

		std::ifstream question;
		std::string path = base_q + std::to_string(current_pos);
		question.open(path);
		std::string temp;
		std::getline(question, temp);
		std::cout << "Your question: " << std::endl;
		std::cout << temp << std::endl;
		std::cout << "Input tour answer: ";
		std::cin >> temp;
		
		std::ifstream answer;
		path = base_a + std::to_string(current_pos);
		answer.open(path);
		std::string temp1;
		std::getline(answer,temp1);

		if(temp == temp1){
			std::cout << "+1 for team" << std::endl;
			score_team++;
		} else {
			std::cout << "+1 for viewers" << std::endl;
			score_viewer++;
		}

		if (score_team > 6){
			std::cout << "Team won" << std::endl;
			return 0;
		}
		if (score_viewer > 6){
			std::cout << "Viewer won" << std::endl;
			return 0;
		}
		
	}
	std::cout << "end";
}
