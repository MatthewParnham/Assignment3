#include "GenStack.h"
#include "inOut.h"
#include "SynCheck.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments. Execution terminated." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }

//Declarations
  GenStack<char> stack(100);
  InOut ino;
  SynCheck checker;


  while(true) { //loops until user chooses to end

    ino.openIn(filePath);//attempts to open ifstream with filepath
    bool check = checker.delimMatch(ino.in, stack); //returns true if no errors & false if errors
    ino.closeIn(); //close file

    if(check) { //tells user if program had no errors
      cout << "No delimiter errors were found in " << filePath << endl;
    }

    cout << "Would you like to check another file? (y/n)" << endl;
    string input;
    cin >> input;
    if(input == "y" || input == "Y") {
      cout << "Please enter file name:" << endl;
      cin >> filePath; // replaces filePath variable w/ user input
    }
    else {
      break;
    }
  }
}
