#include "utils.h"
#include <iostream>
#include <random>
#include <string>

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
int checkCharacters(std::string code, std::string guess) {
  int count1[256] = {0};
  int count2[256] = {0};
  for (char c : code) {
    count1[static_cast<unsigned char>(c)++];
  }
  for (char c : guess) {
    count2[static_cast<unsigned char>(c)++];
  }
  int common = 0;
  for (int i = 0; i < 256; i++) {
    common += std::min(count1[i], count2[i]);
  }
  return common;
}

// oppgave 4 a
// constexpr over const for å evaluere uttrykket ved kompilering som gjør det
// mulig å bruke den til å definere si lengden på en array.
int playMasterMind() {
  constexpr int size = 4;
  constexpr int letters = 6;
  char lower = 'A';
  char upper = 'A' + letters - 1;
  std::string code = randomizeString(size, lower, upper);
  std::string guess;
  guess = readInputToString(size, lower, upper);
}