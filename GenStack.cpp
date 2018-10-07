#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack() {
  myArray = new char[10];
  size = 10;
  top = -1;
}

GenStack::GenStack(int maxSize) {
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack() {
  delete myArray;
  cout << "Stack Destroyed" << endl;
}

void GenStack::push(char d) {
  //error check
  if (top >= size-1) {
    std::cout << "Stack full. Could not push " << d << endl;
  }
  else {
    myArray[++top] = d;
  }
}

char GenStack::pop() {
  //error check
  if (top < 0) {
    std::cout << "Stack empty. Nothing to pop." << endl;
    return '\0';
  }
  else {
    return myArray[top--];
  }
}

char GenStack::peek() {
  if(top < 0) {
    std::cout  << "Stack empty." << endl;
    return '\0';
  }
  return myArray[top];
}

bool GenStack::isFull() {
  return (top == size-1);
}

bool GenStack::isEmpty() {
  return (top == -1);
}
