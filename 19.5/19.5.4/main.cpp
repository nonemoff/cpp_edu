#include <iostream>
#include <fstream>
#include <string>


bool is_format_png(std::string str){
	int max_index = str.size() - 1;
	std::string format = "";
	if (max_index > 2){
		format += str[max_index - 3];
		format += str[max_index - 2];
		format += str[max_index - 1];
		format += str[max_index];
		std::cout << format << std::endl;
		if (format == ".png"){ 
			return true;
		} else {
			std::cout << "Incorrect file format" << std::endl;
		}
	} else {
		std::cout << "Incorrect file name" << std::endl;
		return false;
	}
}

void is_file_png(char arr[]){
	if (((int) arr[0] == -119) && \
			arr[1] == 'P' && \
			arr[2] == 'N' && \
			arr[3] == 'G'){
		std::cout << "File is png" << std::endl;
	} else {
		std::cout << "Corrupted file. Format is not png" << std::endl;
	}
}

int main(){
	char arr[4];
	
	std::string path;
	std::ifstream file;
	std::cout << "Input path to the file: ";
	std::cin >> path;
	file.open(path);
	if (!file.is_open()){
		std::cout << "Wrong path to the file" << std::endl;
	} else {
		if (!is_format_png(path)){
			return 1;
		}
		for (int i = 0; i < 4; i++){
			if (file.eof()){
				std::cout << "Corrupted file. File is too small" << std::endl;
				return 1;
			}
			file.get(arr[i]);
		}
		is_file_png(arr);		
	}
	return 0;
}
