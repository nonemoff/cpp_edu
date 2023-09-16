#include "../include/func.h"
#include "../include/struct.h"

#include <iostream>

void scalpel(Point point1, Point point2) {
  if (point1.X != point2.X && point1.Y != point2.Y) {
    std::cout << "Making a cut..." << std::endl;
  } else {
    std::cout << "Making a hole..." << std::endl;
  }
}

void hemostat(Point point) { std::cout << "Adding hemostat..." << std::endl; }

void tweezers(Point point) { std::cout << "Using tweezers..." << std::endl; }

void suture(Point point1, Point point2){
	std::cout << "Suturing... End of operation." << std::endl;
}
