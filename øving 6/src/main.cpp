#include "bouncingBall.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// oppgave 1 a
void writeToFile() {
  std::string filename = "../output.txt";
  std::ofstream file(filename, std::ios::app);
  if (!file.is_open()) {
    std::cerr << "Kunne ikke åpne filen." << std::endl;
    return;
  }

  std::string word;
  std::cout << "Skriv inn ord. Skriv 'quit' for å avslutte programmet."
            << std::endl;

  while (true) {
    std::cin >> word;
    if (word == "quit") {
      break;
    }
    file << word << std::endl;
  }
  file.close();
}

// oppgave 1 b
void addLineNumbers() {
  std::string filename = "../output.txt";
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Kunne ikke åpne filen." << std::endl;
    return;
  }

  std::string line;
  int lineNumber = 1;
  while (std::getline(file, line)) {
    std::cout << lineNumber << " " << line << std::endl;
    lineNumber++;
  }
  file.close();
}

// oppgave 2 a
/*
i capitalsMap[country];
blir [] brukt som ikke er tillat på en const map siden den kan endre på mapen
hvis det ikke finnes en key for country.
*/

// oppgave 3 a

// #-- -- -- -- -- -- -- -- -- -- -- -- presentation -- -- -- -- -- -- -- -- --

void showTask(int task, char subTask) {
  cout << " ------ Oppgave " << task << " " << subTask << " ------" << endl;

  switch (task) {
  case 1: {
    switch (subTask) {
    case 'a': {
      cout << "write to file" << endl;
      writeToFile();

      break;
    }
    case 'b': {
      cout << "add line numbers" << endl;
      addLineNumbers();
      break;
    }
    default: {
      cout << "invalid subtask" << endl;
      break;
    } break;
    }
  }
  case 4: {
    switch (subTask) {
    case 'a': {
      cout << "bouncing ball" << endl;
      bouncingBall();

      break;
    }
    default: {
      cout << "invalid subtask" << endl;
      break;
    } break;
    }
  }
  default: {
    cout << "invalid task" << endl;

    break;
  }
  }
}

int main() {

  std::vector<std::pair<int, std::vector<char>>> tasks = {
      {1,
       {
           'a',
       }},
      {4, {'a'}},
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