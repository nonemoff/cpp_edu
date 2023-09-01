#include <iostream>
#include <vector>
#include <string>


enum ROOM_TYPES{
	BEDROOM,
	KITCHEN,
	BATHROOM,
	CHILDRENS_ROOM,
	LIVING_ROOM
};

enum BUILDING_TYPES{
	HOUSE,
	GARAGE,
	BARN,
	SAUNA
};



struct Room{
	unsigned int type;
	float square;
};

struct Floor{
	unsigned int number;
	float height;
	std::vector<Room> rooms;
};

struct Building{
	unsigned int type;
	float square;
	bool have_tube;
	std::vector<Floor> floors;
};

struct Land{
	unsigned int number;
	std::vector<Building> buildings;
};

struct Village{
	std::string name;
	std::vector<Land> lands;
};

int main(){
	return 0;
}
