// Written by gordon novak

// This file is a full example of what this whole process put together looks like.
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define DEFAULT "inputFile.txt"

struct Person {
    string firstname;
    string lastname;
    int age;
    int salary;

    Person() { 
        age = 0; 
        salary = 0;
    }

    void printPerson(){
        cout    << firstname << " " << lastname << endl
                << "  Age: " << age << endl
                << "  Salary: $" << salary << endl;
    }
};

vector<Person> extractData(string fileName, vector<Person>& vec);
void print_arguments(int& argc, char**& argv);

int main(int argc, char* argv[]) {

    //Print out our arguments for testing purposes
    print_arguments(argc, argv);

    vector<Person> personList;

    if (argc > 1)
        extractData(argv[1], personList);
    else
        extractData(DEFAULT, personList);

    // Check if our vector returned empty
    if (personList.size() == 0)
        return -1;

    // Print our personList
    cout << "--Printing personList:--" << endl;
    for (auto& i: personList) {
        i.printPerson();
    }

    return 0;
}


// Extract data function to get data from input File
vector<Person> extractData(string fileName, vector<Person>& personList) {
    
    ifstream fileReader(fileName);

    if (!fileReader.is_open()) {
        cerr << "ERR: Could not read data from file \"" + fileName + "\". Ending program." << endl;
        return personList;
    }

    string fname, lname;
    int age, sal;
    while (fileReader >> fname) {
        Person p;
    
        p.firstname = fname;
        fileReader >> p.lastname;
        fileReader >> p.age;
        fileReader >> p.salary;

        personList.push_back(p);
    }

    return personList;
}

// Prints out our arguments
void print_arguments(int& argc, char**& argv) {
    std::cout << "Printing arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    std::cout << std::endl;
}