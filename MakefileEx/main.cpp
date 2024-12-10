#include "Chair.hpp"
#include <iostream>

#define ip "\n> "

using namespace std;

// Returns user-inputted string
string sinp();
// Returns user-inputted double
double dinp();

// Main function
int main(int argc, char* argv[]){
    string wt, s; double sa;
    cout << "Please choose a chair wood-type:" ip;
    wt = sinp();
    cout << "Please choose a chair shape:" ip;
    s = sinp();
    cout << "Please choose a chair seat-area:" ip;
    sa = dinp();
    cout << "Please choose a leg number:" ip;
    Chair c(wt, s, sa, int(dinp()));

    while (true) {
        cout << "\nPlease select an option:\n"
                "  0) Exit Program\n"
                "  1) Sit Down\n"
                "  2) Fix Chair\n"
                "  3) Print Chair" ip;
        wt = sinp();

        if (wt == "0")
            return 0;
        else if (wt == "1") {
            cout << "\nHow much force would you like to sit down with?" ip;
            c.sitDown(int(dinp()));
        }
        else if (wt == "2")
            c.repair();
        else if (wt == "3")
            c.print();
        else
            cerr << "Invalid input. Please try again.\n";

    }

    return 0;
}

string sinp() {
    string inp;
    std::getline(cin, inp);
    return inp;
}

double dinp() {
    string inp;
    std::getline(cin, inp);
    return stod(inp);
}