// Written by gordie
#include <iostream>
#include <fstream>

using namespace std;

#define DEFAULT "defaultFile.txt"

void print_arguments(int& argc, char**& argv);

// Before looking this over, please read the "01-command-line-arguments.cpp"

// Let's write our main function like before:
int main(int argc, char* argv[]) {

    /*  If we want to specify an input file through the terminal, we would type:

        g++ cppfile.cpp
        ./a.out "inputFile.txt"

        The "inputFile.txt" argument will be stored in argv[1]
    */

    print_arguments(argc, argv);

    // Let's first make a read file:
    ifstream fileReader;

    // Now, let's make sure that we actually have MORE THAN 1 ARGUMENT:
    if (argc > 1) {
        // If the user provided MORE THAN 1 ARGUMENT, we can use the file they gave:
        fileReader.open(argv[1]);
    }
    else {
        // Otherwise, use a default file:
        fileReader.open(DEFAULT);
    }

    // Now, we need to make sure that file actually exists:
    if (!fileReader.is_open()){
        // If it doesn't exist, we end the program.
        cerr << "ERR: File could not be opened. Ending program." << endl;
        return -1;
    }

    // And that's it.

    return 0;

}

void print_arguments(int& argc, char**& argv) {
    std::cout << "Printing arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    std::cout << std::endl;
}