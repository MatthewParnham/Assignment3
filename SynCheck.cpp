#include "SynCheck.h"
#include <iostream>
#include "GenStack.h"
#include "inOut.h"

SynCheck::SynCheck() {

}
SynCheck::~SynCheck() {

}

bool SynCheck::delimMatch(ifstream& file, GenStack<char>& stack) {
  int currentLine = 0;
  string line;
  while(getline(file,line)) {
    currentLine++;
    for (int i = 0; i < line.size()-1; i++) {

      if(line[i] == '/' && line[i+1] == '/') {
        break; //skips rest of line if // is found
      }

      if(line[i] == '(' || line[i] == '[' || line[i] == '{') {
        stack.push(line[i]); //pushes opening delimiters to stack
      }
      else if(line[i] == ')' || line[i] == ']' || line[i] == '}') { //if closing delim
        if(stack.isEmpty()) { //if the stack is empty
          cout << "On line " << currentLine << " an extra " << line[i] << " was found." << endl;
          return false;
        }
        if(stack.peek() == '(') {
          if(line[i] != ')') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << ". Expected " << stack.peek() << endl;
            return false;
          }
        }
        else if(stack.peek() == '[') {
          if(line[i] != ']') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << ". Expected " << stack.peek() << endl;
            return false;
          }
        }
        else if(stack.peek() == '{') {
          if(line[i] != '}') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << ". Expected " << stack.peek() << endl;
            return false;
          }
        }
        stack.pop();
      }
    }
  }
  bool finalVal = stack.isEmpty();
  while(!stack.isEmpty()) {
    cout << "Found unmatched " << stack.pop() << endl;
  }
  return finalVal; //returns false if any errors. returns true if no errors
}
