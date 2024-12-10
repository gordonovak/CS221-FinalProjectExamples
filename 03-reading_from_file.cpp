//Written by gordon novak
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Person {
    string firstname;
    string lastname;
    int age;
    int salary;

    Person() { 
        age = 0; 
        salary = 0;
    }
};

// How to grab data from a text file with this format

// Lets say I have a person in my data.txt that looks like this:

// Brenna Hanson 19 43000
// John Smith 55 120000

// Brenna is 19 years old with a salary of $43000 dollars.

// Here is an example of an extraction function:

vector<Person*> extractData(string fileName) {
    
    //Lets create an ifstream object:
    ifstream fileReader(fileName);
    //Create a vector to store all your objects
    vector<Person*> personList;

    if (!fileReader.is_open()) {
        cout << "ERR: File is not open.\n";
        return personList;
    }

    string fname, lname;
    int age, sal;
    while (fileReader >> fname) {
        //Create your object
        Person* p;
        
        //Input data into your variables
        fileReader >> lname;
        fileReader >> age;
        fileReader >> sal;

        //Then put your data into the object
        p->firstname = fname;
        p->lastname = lname;
        p->age = age;
        p->salary = sal;
        
        //Add the person to the vector
        personList.push_back(p);
    }

    // Make sure to close your file.
    fileReader.close();
    
    //Return your vector when done
    return personList;
}
