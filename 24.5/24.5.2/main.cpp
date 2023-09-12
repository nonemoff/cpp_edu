#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct Person {
  std::string name;
  std::tm date;

  Person(std::string _name, std::tm _date) : name(_name), date(_date){};
};

void get_closest_bd(std::vector<Person> persons) {
  std::time_t temp = std::time(nullptr);
  std::tm *time = std::localtime(&temp);
  time->tm_sec = 0;
  time->tm_min = 0;
  time->tm_hour = 0;
  time->tm_year = 0;

  int min_index;
  long min_diff = 0;
  bool is_any_today = false;

  for (int i = 0; i < persons.size(); i++) {
    long diff = std::difftime(std::mktime(&persons[i].date), std::mktime(time));

    if (time->tm_mon == persons[i].date.tm_mon &&
        time->tm_mday == persons[i].date.tm_mday) {
      std::cout << "TODAY is " << persons[i].name << "`s bday!" << std::endl;
      is_any_today = true;
    } else {
      if (min_diff == 0) {
        min_diff = diff;
        min_index = i;
      } else if (min_diff < 0 && diff > 0) {
        min_diff = diff;
        min_index = i;
      } else if (min_diff < 0 && diff < 0 && min_diff > diff) {
        min_diff = diff;
        min_index = i;
      } else if (min_diff > 0 && diff > 0 && min_diff > diff) {
				min_diff = diff;
				min_index = i;
      }
    }
  }
	if (!is_any_today){
		std::cout << "Closest bday has " << persons[min_index].name << " on " << std::put_time(&persons[min_index].date, "%m/%d");
	}
}

int main() {
  std::vector<Person> persons;

  while (true) {
    std::string name_temp;
    std::tm date_temp;

    std::cout << "Input name: ";
    std::cin >> name_temp;
    if (name_temp == "end") {
      break;
    }

    std::cout << "Input date: ";
    std::string input;
    std::cin >> std::get_time(&date_temp, "%Y/%m/%d");
    date_temp.tm_sec = 0;
    date_temp.tm_min = 0;
    date_temp.tm_hour = 0;
    date_temp.tm_year = 0;

    persons.emplace_back(name_temp, date_temp);
  }
  if (persons.size() != 0) {
    get_closest_bd(persons);
  } else {
    std::cout << "There is no bdays :(" << std::endl;
  }
  return 0;
}
