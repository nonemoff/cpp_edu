#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Task {
  std::string name;
	std::time_t timer = 0;
  bool is_active = false;

  Task(std::string inputed_name) : name(inputed_name){};
};

void options() {
  std::cout << "---- OPTIONS ----" << std::endl;
  std::cout << "Type \"begin\" to start task" << std::endl;
  std::cout << "Type \"end\" to compete task" << std::endl;
  std::cout << "Type \"status\" to task stats" << std::endl;
  std::cout << "Type \"options\" to see options" << std::endl;
  std::cout << "Type \"exit\" to exit application" << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << std::endl << std::endl;
}

void add(std::vector<Task> &tasks, std::string name) { tasks.emplace_back(name); }

void begin(std::vector<Task> &tasks, int &current_task_index,
           std::time_t &timer) {
  std::cout << "Input task`s name: ";
  std::string name;
  std::cin >> name;
  bool is_added = false;
  int new_task_index = -1;
  for (int i = 0; i < tasks.size(); i++) {
    if (tasks[i].name == name) {
      new_task_index = i;
      is_added = true;
      break;
    }
  }
  std::time_t current_time = std::time(nullptr);
  if (is_added) {
    if (new_task_index != current_task_index) {
      if (current_task_index != -1) {
        tasks[current_task_index].is_active = false;
        tasks[current_task_index].timer += std::difftime(current_time, timer);
      }
      tasks[new_task_index].is_active = true;
      current_task_index = new_task_index;
      timer = current_time;
    }
  } else if (!is_added) {
    add(tasks, name);
    if (tasks.size() == 1) {
      current_task_index = 0;
    } else {
      if (current_task_index != -1) {
        tasks[current_task_index].is_active = false;
        tasks[current_task_index].timer += std::difftime(current_time, timer);
      }
      current_task_index = tasks.size() - 1;
    }
    timer = current_time;
    tasks[current_task_index].is_active = true;
  } else {
    std::cout << "You already started this task" << std::endl;
  }
}

void status(std::vector<Task> &tasks) {
  if (tasks.size() == 0) {
    std::cout << "You have not any tasks!" << std::endl;
  } else {
    for (int i = 0; i < tasks.size(); i++) {
      std::cout << "-----------------" << std::endl;
      std::cout << "Task name: " << tasks[i].name << std::endl;
			std::tm* local = std::localtime(&tasks[i].timer);
			local->tm_hour -= 3;
      std::cout << "Task timer: " << std::put_time(local,"%H:%M:%S") << std::endl;
      std::cout << "Task status: "
                << ((tasks[i].is_active) ? "active" : "inactive") << std::endl;
    }
  }
}

void end(std::vector<Task> &tasks, int &current_task_index,
         std::time_t &timer) {
  if (tasks.size() != 0) {
    std::time_t current_time = std::time(nullptr);
    tasks[current_task_index].is_active = false;
    tasks[current_task_index].timer += std::difftime(current_time, timer);
    current_task_index = -1;
  } else {
    std::cout << "You have not any tasks!" << std::endl;
  }
}

int main() {
  std::vector<Task> tasks;
  int current_task_index;
  std::time_t timer;

  options();
  while (true) {
    std::cout << "Input option: " << std::endl;
    std::string option;
    std::cin >> option;
    if (option == "begin") {
      begin(tasks, current_task_index, timer);
    } else if (option == "end") {
      end(tasks, current_task_index, timer);
    } else if (option == "status") {
      status(tasks);
    } else if (option == "options") {
      options();
    } else if (option == "exit") {
      std::cout << "Exiting..." << std::endl;
      break;
    } else {
      std::cout << "Wrong input!" << std::endl;
      std::cout << "Input \"options\" to see all comands" << std::endl;
    }
		std::cout << std::endl;
  }

  return 0;
}
