// #include "AnimationWindow.h"
#include "masterVisual.h"
#include "mastermind.h"
#include "std_lib_facilities.h"
#include "utils.h"
#include <bits/c++config.h>
#include <iostream>
#include <vector>

using namespace std;

/*
oppgave 2 e
redefinerer flere funksjoner må ha header guards

#ifndef header.h
#define header.h

#endif // header.h

eller

#pragma once

ikke i cpp standard men fungerer på de fleste kompilatorer
*/

// #-- -- -- -- -- -- -- -- -- -- -- -- presentation -- -- -- -- -- -- -- -- --

void showTask(int task, char subTask) {
  cout << " ------ Oppgave " << task << " " << subTask << " ------" << endl;

  switch (task) {
  case 1: {
    switch (subTask) {
    case 'a': {
      cout << "v0: 5" << endl << "pass by value" << endl;
      break;
    }
    case 'b': {
      cout << "description" << endl;
      break;
    }
    case 'c': {
      cout << "description" << endl;
      break;
    }
    case 'd': {
      cout << "description" << endl;
      break;
    }
    }
    break;
  }
  case 3: {
    switch (subTask) {
    case 'b': {
      int length;
      char lower;
      char upper;
      cout << "randomize string" << endl;
      cout << "skriv inn lengde:";
      cin >> length;
      cout << "skriv inn nedre grense:";
      cin >> lower;
      cout << "skriv inn ovre grense:";
      cin >> upper;
      randomizeString(length, lower, upper);
      break;
    }
    default: {
      cout << "invalid subtask" << endl;
      break;
    }
    }
    break;
  }
  case 4: {
    cout << "play mastermind" << endl;
    playMasterMind();
    break;
  }
  case 5: {
    cout << "play mastermind visual" << endl;
    playMastermindVisual();

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
      {1, {'b', 'c', 'd', 'f'}},
      {3, {'b', 'c', 'd', 'f'}},
      {4, {'b'}},
      {5, {'a'}},
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