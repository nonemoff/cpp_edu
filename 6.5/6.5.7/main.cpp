#include <iostream>

int main(){
	int m, n;
	std::cout << "Введите числитель дроби" << std::endl;
	std::cin >> m;
	std::cout << "Введите знаминатель дроби" << std::endl;
	std::cin >> n;

	int i = 1;
	while(true){
		i++;
		if (m % i == 0 && n % i == 0){
			m /= i;
			n /= i;
		}
		if (i > m && i > -m || i > n && i > -n) {
			break;
		}
	}
	std::cout << "Сокращенная дробь: " << m << "/" << n << std::endl;
	return 0;
}
