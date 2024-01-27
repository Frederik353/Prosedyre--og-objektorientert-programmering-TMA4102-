#include "AnimationWindow.h"
#include "cannonball.h"
#include "std_lib_facilities.h"
#include <iostream>
#include <vector>

// #-- -- -- -- -- -- -- -- -- -- -- -- presentation -- -- -- -- -- -- -- -- --

void showTask(int task, char subTask) {
  cout << " ------ Oppgave " << task << " " << subTask << " ------" << endl;

  switch (task) {
  case 4: {
    switch (subTask) {
    case 'd': {
      cout << "testing" << endl;
      break;
    }

    default: {
      cout << "invalid subtask" << endl;
      break;
    }
    }
    break;
  }

  default: {
    cout << "invalid task" << endl;

    break;
  }
  }
}

int main() {

  std::vector<std::pair<int, std::vector<char>>> tasks = {
      {3, {'c'}},
  };

  std::cout << "Vil du kjore alle oppgaver fra valgt oppgave? (ja/nei): ";
  std::string response;
  std::cin >> response;
  bool runAll = (response == "ja");

  if (runAll) {
    for (const auto &taskPair : tasks) {
      const int &task = taskPair.first;
      const std::vector<char> &subTasks = taskPair.second;

      for (const char &subTask : subTasks) {
        showTask(task, subTask);
      }
    }
  } else {
    cout << "Velg oppgave: ";
    int task;
    cin >> task;

    cout << "Velg underoppgave oppgave: ";
    char subTask;
    cin >> subTask;

    showTask(task, subTask);
  }

  return 0;
}