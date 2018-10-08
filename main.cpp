#include "GenStack.h"
#include "inOut.h"
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

  ino.openIn(filePath);
  string line;
  int currentLine = 0;
  while(getline(ino.in,line)) {
    currentLine++;
    for (int i = 0; i < line.size()-1; i++) {

      if(line[i] == '(' || line[i] == '[' || line[i] == '{') {
        stack.push(line[i]);
        cout << "On line " << currentLine << ", " << line[i] << " added to stack." << endl;
      }
      
      else if(line[i] == ')') {
        if(stack.peek() == '(') {
          cout << stack.pop() << " popped from stack." << endl;
        }
        else {
          //record error
          cout << "On line " << currentLine << ", expected " <<  stack.peek() << " and found " << line[i] << endl;
          return 0;
        }
      }
      else if(line[i] == ']') {
        if(stack.peek() == '[') {
          cout << stack.pop() << " popped from stack." << endl;
        }
        else {
          //record error
          cout << "On line " << currentLine << ", expected " <<  stack.peek() << " and found " << line[i] << endl;
          return 0;
        }
      }
      else if(line[i] == '}') {
        if(stack.peek() == '{') {
          cout << stack.pop() << " popped from stack." << endl;
        }
        else {
          //record error
          cout << "On line " << currentLine << ", expected " <<  stack.peek() << " and found " << line[i] << endl;
          return 0;
        }
      }

    }
  }

  while(!stack.isEmpty()) {
    cout << "End of file reached, expecting " << stack.pop() << endl;
  }

/*
  GenStack<char> g(2);
  cout << g.size << endl;
  g.push('c');
  g.push('a');
  g.push('t');
  cout << g.size << endl;
  cout << g.pop() << endl;
  cout << g.pop() << endl;
  cout << g.pop() << endl;*/
}
