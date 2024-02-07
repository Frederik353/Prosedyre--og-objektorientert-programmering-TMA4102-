#include <string>

int checkCharactersAndPosition(std::string code, std::string guess);

int checkCharacters(char lower, char upper, std::string code,
                    std::string guess);

int playMasterMind(int guesses = 10);