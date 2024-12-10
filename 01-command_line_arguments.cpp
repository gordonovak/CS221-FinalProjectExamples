// Written by gordie
#include <iostream>

using namespace std;

void print_arguments(int& argc, char**& argv);

// Command line arguments let you change variables within your program before actually running your program.
// To use them, you would write your executable call with additional strings:

//      ./a.out arg1 arg2 arg3

// To actually use these new arguments (ex. "arg1") we have to write our main function like this:
int main(int argc, char* argv[] ){
    // argc is the number of arguments (for "./a.out arg1 arg2 arg3" we have 4 arguments)
    // argv is an array with all the arguments such that for "./a.out arg1 arg2 arg3"
    //      argv[0] = "./a.out";
    //      argv[1] = "arg1";
    //      argv[2] = "arg2";
    //      argv[3] = "arg3";

    /*  Say for example, if I typed into the terminal:

            [user ~/]$ g++ 01-command_line_arguments.cpp
            [user ~/]$ ./a.out argument hello a_nice_message

        I would then have FOUR arguments:
            argv[0] = "./a.out";
            argv[1] = "argument";
            argv[2] = "hello"
            argv[3] = "a_nice_message";
    */

    // We can print all the arguments with this function:
    print_arguments(argc, argv);

    // To learn how to grab an input file from the terminal, go to the next program.

    return 0;
}

// You can copy this function 
void print_arguments(int& argc, char**& argv) {
    std::cout << "Printing arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    std::cout << std::endl;
}

