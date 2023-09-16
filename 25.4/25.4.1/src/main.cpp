#include "../include/func.h"
#include "../src/func.cpp"

int main() {
  Point point1, point2;
  Point temp1, temp2;

  std::cout << "Start of operation." << std::endl;

  std::cout << "Input the first point of a cut <X Y>: ";
  std::cin >> point1.X >> point1.Y;

  std::cout << "Input the second point of a cut <X Y>: ";
  std::cin >> point2.X >> point2.Y;

  scalpel(point1, point2);

  std::cout << "Input the coordinate of a hemostat <X Y>: ";
  std::cin >> temp1.X >> temp1.Y;

  hemostat(temp1);

  std::cout << "Input the coordinate of a tweezers <X Y>: ";
  std::cin >> temp1.X >> temp1.Y;

  tweezers(temp1);

  while (true) {
    std::cout << "Input the first point of a cut <X Y>: ";
    std::cin >> temp1.X >> temp1.Y;

    std::cout << "Input the second point of a cut <X Y>: ";
    std::cin >> temp2.X >> temp2.Y;

		if (temp1.X == point1.X && temp1.Y == point1.Y && temp2.X == point2.X && temp2.Y == point2.Y){
			break;
		} else if (temp1.X == point2.X && temp1.Y == point2.Y && temp2.X == point1.X && temp2.Y == point1.Y){
			break;
		} 
		std::cout << "You did not aim the cut!" << std::endl;
  }

	suture(temp1, temp2);

	return 0;
}
