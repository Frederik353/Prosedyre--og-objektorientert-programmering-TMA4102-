#include "masterVisual.h"
#include "mastermind.h"
#include "utils.h"
#include <vector>

void addGuess(MastermindWindow &mwin, const string code,
              const char startLetter) {
  mwin.guesses.push_back(Guess{code, startLetter});
}

void addFeedback(MastermindWindow &mwin, const int correctPosition,
                 const int correctCharacter) {
  mwin.feedbacks.push_back(Feedback{correctPosition, correctCharacter});
}

void MastermindWindow::drawCodeHider() {
  if (code_hidden) {
    draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY,
                   Color::black);
  }
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size,
                                   const string &title)
    : AnimationWindow(x, y, w, h, title),
      guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
      guess{
          {upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
      size(size) {
  add(guess);
  add(guessBtn);
  guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks() {
  std::map<int, Color> colorConverter{
      {1, Color::red},  {2, Color::green},       {3, Color::yellow},
      {4, Color::blue}, {5, Color::blue_violet}, {6, Color::dark_cyan}};

  char lower = 'A';
  for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size());
       guessIndex++) {
    // Implementer funksjonalitet slik at det vises fargede rektangler i
    // grafikkvinduet Tegn gjettet som ligger på plassen guessIndex i vektoren
    // guesses.
    std::string s = guesses[guessIndex].code;
    int yPos = 3 * padY + guessIndex * padY * 2;

    for (int k = 0; k < size; k++) {
      int xPos = padX + 2 * k * padX;
      int colorNum = s[k] - lower + 1; //  1 indexed shit
      Color color = colorConverter.at(colorNum);

      draw_rectangle({xPos, yPos}, padX, padY, color);
    }
  }

  for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {

    int yPos = 5.5 * padY + feedbackIndex * padY * 2;

    int total = 0;
    Color colors[4];

    int correct = feedbacks[feedbackIndex].correctPosition;
    int common = feedbacks[feedbackIndex].correctCharacter;


    for (int i = 0; i < correct; i++) {
      colors[total] = Color::black;
      total++;
    }
    for (int i = 0; i < common; i++) {
      colors[total] = Color::grey;
      total++;
    }
    int circlesLeft =  - total;
    for (int i = total; i < 4; i++) {
      colors[i] = Color::white;
    }

    for (int i = 0; i < size; i++) {
      int xPos = 9 * padX + (padX / 4) * 0.5 + (padX / 4) * i;
      draw_circle({xPos, yPos}, radCircle + 1, Color::black);
      draw_circle({xPos, yPos}, radCircle, colors[i]);
    }
  }
}

string MastermindWindow::wait_for_guess() {

  while (!button_pressed && !should_close()) {
    drawGuessesAndFeedbacks();
    // Burde tegnes sist siden den skal ligge på toppen
    drawCodeHider();

    next_frame();
  }
  button_pressed = false;

  string newGuess = guess.getText();
  guess.setText("");

  return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper) {
  bool validInput = false;
  string guess;
  while (!validInput && !should_close()) {
    guess.clear();
    string input = wait_for_guess();
    if (input.size() == n) {
      for (unsigned int i = 0; i < n; i++) {
        char ch = input.at(i);
        if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch)) {
          guess += toupper(ch);
        } else
          break;
      }
    }
    std::cout << "guess: " << guess << " " << guess.size() << " " << n << std::endl;
    if (guess.size() == n) {
      validInput = true;
    } else {
      cout << "Invalid input guess again" << endl;
    }
  }
  return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) { code_hidden = hidden; }

void playMastermindVisual() {
  constexpr int guesses = 6;
  constexpr int size = 4;
  constexpr int letters = 6;
  MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};
  char lower = 'A';
  char upper = 'A' + letters - 1;
  std::string code = randomizeString(size, lower, upper);
  std::string guess;
  addGuess(mwin, code, lower);

  bool win = false;
  for (int i = 0; i < guesses; i++) {
    guess = mwin.getInput(size, lower, upper);
    addGuess(mwin, guess, lower);
    // stringToUpper(guess);
    int correct = checkCharactersAndPosition(code, guess);
    int common = checkCharacters(lower, upper, code, guess) - correct;
    addFeedback(mwin, correct, common);

    if (correct == size) {
    win = true;
    break;
    }



    std::cout << "Antall riktige bokstaver: " << common << std::endl;
    std::cout << "Antall riktige bokstaver pa rett plass: " << correct
              << std::endl;
  }
  if (win){
      std::cout << "riktig!" << std::endl;
     }
  else
  {
    std::cout << "----------- Du klarte det ikke i tide  -----------" << std::endl;
  }
  mwin.drawGuessesAndFeedbacks();
  mwin.setCodeHidden(false);
  mwin.wait_for_close();

}
