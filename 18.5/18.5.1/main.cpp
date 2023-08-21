#include <iostream>
#include <vector>

void swapvec(std::vector<int>& a, std::vector<int>& b){
	if (a.size() != b.size()){
		std::cout << "Cannot swap vectors with different size!" << std::endl;
	} else {
		for(int i = 0; i < a.size(); i++){
			int temp;
			temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
	}
}

int main(){
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> b = {11, 12, 13, 14, 15, 16, 17};

	swapvec(a,b);
	std::cout << "Vec a: ";
	for (int i = 0; i < a.size(); i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl << "Vec b: ";
	for (int i = 0; i < b.size(); i++){
		std::cout << b[i] << " ";
	}

	return 0;
}
