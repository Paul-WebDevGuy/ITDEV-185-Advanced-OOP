
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/*
    Paul Satterlee
    Assignment 2
    ITDEV185 Spring2022-900
*/
int main()
{
    int numStudents;                    //to hold total number of students
    string name;                        //to hold students name
    string first;                       //to hold first student in line
    string last;                        //to hold last student in line
    const int MAX_STUDENTS = 20;        //maximum number of students in a class

    //create output file for writing to
    ofstream outputFile;
    outputFile.open("studentList.txt");

    //create input file to read from
    ifstream inFile;

    //get number of students in class
    cout << "Enter the number of students in class.  Number of students must be between 1 and 20:  ";;
    cin >> numStudents;

    //validate number of students
    while (numStudents < 1 || numStudents > MAX_STUDENTS)
    {
        cout << "That number of students is not valid.  Please enter a valid number between 1 and 20" << endl;
        cin >> numStudents;
    }
    
    //if only one student is in the class, they will be first and last in line
    if (numStudents == 1)
    {
        cout << "Please enter the first students name: ";
        cin >> name;

        //write name to file
        outputFile << name;

        //close output file
        outputFile.close();

        //read in name from file
        inFile.open("studentList.txt");
        inFile >> name;

        cout << name << " is at the front and back of the line.";
        cout << "\n";

        exit(0);
    }

    //User enters names of each student in class
    for (int i = 1; i < numStudents + 1; i++)
    {
        cout << "Please enter student number " << i << "'s name:  ";
        cin >> name;

        //write each name to the file
        outputFile << name << endl;
    }
    //close outputFile
    outputFile.close();

    //open inFile for reading
    inFile.open("studentList.txt");

    //check to make sure inFile exists
    if (!inFile)
    {
        cout << "Error. File does not exist.";
        exit(1);
    }

    //read through list of names in file and determine who is first and who is last
    while(getline(inFile, name))
    {
        //check if first and last are empty
        if (first.empty())
        {
            first = name;
        }
        else if (last.empty())
        {
            last = name;
        }

        //find first name alpahbetically
        if (name < first)
        {
            first = name;
        }

        //find last name alphabetically
        if (name > last)
        {
            last = name;
        }
    }

    //close input file
    inFile.close();

    //display results
    cout << "\n";
    cout << first << " is at the head of the line.\n";
    cout << last << " is at the back of the line.\n";
}


