#include <iostream>

bool substr(const char* str, const char* sstr){
	for (int i = 0; *(str + i) != '\0'; i++){
		for(int j = 0; true; j++){
			if (*(sstr + j) == '\0'){
				return true;
			}
			if (*(sstr + j) != *(str + i + j)){
				break;
			}
		}
	}
	return false;
}

int main(){

	const char* a = "Hello world";
	const char* b = "wor";
	const char* c = "banana";

	std::cout << substr(a,b) << " " << substr(a,c);
	return 0;
}
