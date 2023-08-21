#include <iostream>

void even(long long n, int& ans){
	if (n != 0){
		if (n % 2 == 0) ans++;
		even(n/10, ans);
	}
}

int main(){
	long long a = 9223372036854775806;
	int ans = 0;
	even(a,ans);
	std::cout << ans << std::endl;
	return 0;
}
