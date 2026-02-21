#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    // file variables
    ofstream outputFile;
    string filename;
    string name;
    char mode;
    
    // user input variables
    int age;
    double gpa;
    string x = "y";

    //create file, ask user if they want to append or overwrite file
    cout << "Enter file name: ";
    getline(cin, filename);

    cout << "Append to file (a) or overwrite file (o)? ";
    cin >> mode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer

    if (mode == 'a' || mode == 'A')
    {
        outputFile.open(filename, ios::app);
    }
    else if (mode == 'o' || mode == 'O')
    {
        outputFile.open(filename);
    }


    // user input loop
    while (x != "n")
    {
        cout << "Enter name: ";
        getline(cin, name);
        outputFile << name << endl;
        
        cout << "Enter age: ";
        cin >> age;
        outputFile << age << endl;

        cout << "Enter GPA: ";
        cin >> gpa;
        outputFile << gpa << endl;

        cout << "Would you like to enter another record? (y/n); ";
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Information has been saved to " << filename << endl;

    outputFile.close();

    //clear terminal screen
    system("cls");

    // read file and display in terminal
    ifstream inputFile;
    inputFile.open(filename);

    while (getline(inputFile, name)) {
    if (!(inputFile >> age >> gpa)) {
        break;
    }
    inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
    }

    inputFile.close();

    return 0;
}