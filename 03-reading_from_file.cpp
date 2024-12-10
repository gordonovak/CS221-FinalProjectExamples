//Written by gordon novak
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Example struct
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

// This file covers how to use an ifstream object to grab data from a file

// Lets say I have a person in my data.txt that looks like this:

// Brenna Hanson 19 43000
// John Smith 55 120000

// Brenna is 19 years old with a salary of $43000 dollars.

// I want to create a Person object with:
//    firstname = "Brenna"
//    lastname = "Hanson"
//    age = 19
//    salary = 43000

// To do this, I would utilize something like the function below.

// First, we specify our return type as a vector filled with People. We should take in a fileName to read data from.
vector<Person*> extractData(string fileName) {
    
    //Lets then create an ifstream object:
    ifstream fileReader(fileName);
    //Create a vector to store all your objects
    vector<Person*> personList;

    // Check to make sure the file is open.
    if (!fileReader.is_open()) {
        cout << "ERR: File is not open.\n";
        // If it's not open, we return an empty vector
        return personList;
    }

    // Define all the variables a Person may have beforehand.
    string fname, lname;
    int age, sal;
    
    // Then, we write our while loop with the ifstream object
    
    while (fileReader >> fname) { // In this while loop, we are saying:
        //Create your object      // "Keep putting information into our fname string until there are no more strings left in the file"
        Person* p;
        
        // Input data into your variables in order:
        fileReader >> lname;
        fileReader >> age;
        fileReader >> sal;

        // Then put your data into the object:
        p->firstname = fname;
        p->lastname = lname;
        p->age = age;
        p->salary = sal;
        
        // Add the person to the vector:
        personList.push_back(p);
        
    } // Then we loop again until the file is empty.

    // Make sure to close your file.
    fileReader.close();
    
    //Return your vector when done
    return personList;
}
