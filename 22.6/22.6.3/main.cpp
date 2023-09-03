#include <iostream>
#include <string>
#include <map>

int main(){
	std::map<char, int> letters;

	std::cout << "Input the first word: ";
	std::string word; std::cin >> word;

	for (int i = 0; i < word.length(); i++){
		if (letters.count(word[i]) == 0){
			letters[word[i]] = 1;
		} else {
			letters[word[i]]++;
		}
	}
	
	std::cout << "Input the second word: ";
	std::cin >> word;

	for (int i = 0; i < word.length(); i++){
		if (letters.count(word[i]) == 0){
			std::cout << "false" << std::endl;
			return 0;
		} else {
			letters[word[i]]--;
		}
	}

	for (std::map<char, int>::iterator it = letters.begin(); it != letters.end(); it++){
		if (it->second != 0){
			std::cout << "false" << std::endl;
			return 0;
		}
	}

	std::cout << "true" << std::endl;
	return 0;
}


