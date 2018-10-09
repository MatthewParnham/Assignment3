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

      if(line[i] == '(' || line[i] == '[' || line[i] == '{') {
        stack.push(line[i]);
      }
      else if(line[i] == ')' || line[i] == ']' || line[i] == '}') {
        if(stack.isEmpty()) {
          cout << "On line " << currentLine << " an extra " << line[i] << " was found." << endl;
          return false;
        }
        if(stack.peek() == '(') {
          if(line[i] != ')') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << endl;
            return false;
          }
        }
        else if(stack.peek() == '[') {
          if(line[i] != ']') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << endl;
            return false;
          }
        }
        else if(stack.peek() == '{') {
          if(line[i] != '}') {
            cout << "On line " << currentLine << ": Found incorrect " << line[i] << endl;
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
  return finalVal;
}
