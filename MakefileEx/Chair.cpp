#include "Chair.hpp"
#include <ctime>

void Chair::print() {
    cout    << woodType << " chair:\n"
            << "  Shape: " << seatShape << endl
            << "  Area: " << seatArea << "in\n"
            << "  Legs: " << legs << endl
            << ((!broken) ? "Not currently broken.\n" : "Broken.\n");
}

void Chair::sitDown(int force) {
    srand(time(0));
    double odds = float(force)/seatArea;
    if (rand()%100 < odds) {
        cout << "Oh no, your seat is broken!\n";
        broken = true;
    }
    else {
        cout << "You sat down successfully\n";
    }
}

void Chair::repair() {
    if (!broken) {
        cout << "Cannot repair because chair is not broken.\n";
    }
    else {
        cout << "Chair repaired successfully!\n";
        broken = false;
    }
}