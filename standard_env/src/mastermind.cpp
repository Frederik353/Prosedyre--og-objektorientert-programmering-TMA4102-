#include "utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// oppgave 4 e
int checkCharactersAndPosition(std::string code, std::string guess) {
  int correct = 0;
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == guess[i]) {
      correct++;
    }
  }
  return correct;
}

// oppgave 4 f
// ikke mer effektiv enn vanlig dobbel for loop før over 17 bokstaver og bruker
// mer minne
// kan forbedres ved å vite size og spenn (lower, upper) for å lage en array
// i hvilket tilfelle over 3 bokstaver er raskere (rent teoretisk)
// iterer gjennom mulige vil gi spen * lengde
// antar i disse tilfellene spen = 6, endring av spen vil endre resultatet
// avhenging av tettheten av bokstaver
int checkCharacters(char lower, char upper, std::string code,
                    std::string guess) {
  int span = upper - lower + 1;
  std::vector<int> count1(span, 0);
  std::vector<int> count2(span, 0);
  for (char c : code) {
    count1[static_cast<unsigned char>(c) - static_cast<int>(lower)]++;
  }
  for (char c : guess) {
    count2[static_cast<unsigned char>(c) - static_cast<int>(lower)]++;
  }
  int common = 0;
  for (int i = 0; i < span; i++) {
    common += std::min(count1[i], count2[i]);
  }
  return common;
}

// oppgave 4 a
// constexpr over const for å evaluere uttrykket ved kompilering som gjør det
// mulig å bruke den til å definere si lengden på en array.
void playMasterMind(int guesses = 10) {
  constexpr int size = 4;
  constexpr int letters = 6;
  char lower = 'A';
  char upper = 'A' + letters - 1;
  std::string code = randomizeString(size, lower, upper);
  std::string guess;

  for (int i = 0; i < guesses; i++) {
    guess = readInputToString(size, lower, upper);
    // stringToUpper(guess);
    int correct = checkCharactersAndPosition(code, guess);
    if (correct == size) {
      std::cout << "riktig!" << std::endl;
      return;
    }
    int common = checkCharacters(lower, upper, code, guess);
    std::cout << "Antall riktige bokstaver: " << correct << std::endl;
    std::cout << "Antall riktige bokstaver pa rett plass: " << correct
              << std::endl;
  }
  std::cout << "----------- Du klarte det ikke i tide  -----------"
            << std::endl;
}
