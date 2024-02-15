
#pragma once
#include <string>
#include <map>

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW
};

struct Config {
    Color ballColorUp;
    Color ballColorDown;
    int ballSpeed;
};

// Definerer et map som kobler heltallene 1-4 med en farge
std::map<int, Color> colorMap = {
    {1, RED},
    {2, GREEN},
    {3, BLUE},
    {4, YELLOW}
};


void bouncingBall();