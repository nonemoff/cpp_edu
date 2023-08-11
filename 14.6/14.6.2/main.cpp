#include <iostream>

void make_empty(char arr[][3]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			arr[i][j] = ' ';
		}
	}
}

bool is_correct(int v){
	return v > 0 && v < 4;
}

void display(char arr[0][3]){
	std::cout << std::endl;
	for(int j = 0; j < 5; j++){
		for(int i = 0; i < 5; i++){
			if (i == 1 || i == 3){
				if (j == 1 || j == 3){
					std::cout << "+";
				} else {
					std::cout << "|";
				}
			} else if (j == 1 || j == 3){
				std::cout << "-";
			} else {
				int x, y;
				if (j == 4) y = 2;
				if (j == 2) y = 1;
				if (j == 0) y = 0;
				if (i == 4) x = 2;
				if (i == 2) x = 1;
				if (i == 0) x = 0;
				std::cout << arr[y][x];
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


bool check_winner(char arr[][3]){
	for (int i = 0; i < 3; i++){
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' '){
			return true;
		} else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ') {
			return true;
		}
	}
	return false;
}


int main(){
	char field[3][3];
	while(true){
		make_empty(field);
		display(field);
		for (int turn = 1; turn <= 9; turn++){
			char player = (turn % 2 == 1) ? 'X' : 'O';
			bool correct_input = false;

			int x, y;

			while(!correct_input){
				std::cout << "Player " << player << "! Input your next turn."\
					" Input coordinate in range [1;3]" << std::endl;
				std::cout << "x: ";
				std::cin >> x;
				std::cout << "y: ";
				std::cin >> y;
				
				if (is_correct(x) && is_correct(y) && field[y-1][x-1] == ' '){
					correct_input = true;
				} else {
					std::cout << "Incorrect input!" << std::endl;
				}				
			}
			field[y-1][x-1] = player;
			display(field);

			if(check_winner(field)){
				std::cout << "Player " << player << " won!" << std::endl;
				break;
			}
		}
		std::cout << "GAME OVER!" << std::endl << std::endl;
	}
	return 0;
}
