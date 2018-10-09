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


  GenStack<char> stack(100);
  InOut ino;
  SynCheck checker;
  while(true) {
    ino.openIn(filePath);
    cout << checker.delimMatch(ino.in, stack) << endl;
    ino.closeIn();
    cout << "Would you like to check another file? (y/n)" << endl;
    string input;
    cin >> input;
    if(input == "y") {
      cout << "Please enter file name:" << endl;
      cin >> filePath;
    }
    else {
      break;
    }
  }
}
