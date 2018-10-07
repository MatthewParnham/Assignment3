#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;

template <class T>
class GenStack {
public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); //deconstructor

  void push(const T& d); //push a reference of object d of class T
  T pop(); //remove object from top of stack and return it
  T peek(); //return top of stack without removing

  bool isFull(); //check if stack is full
  bool isEmpty(); //check if stack is empty

  int size;
  int top;

  T *myArray;
};

template <class T>
GenStack<T>::GenStack() {
  myArray = new T[10];
  size = 10;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize) {
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack() {
  delete myArray;
  cout << "Stack Destroyed" << endl;
}

template <class T>
void GenStack<T>::push(const T& d) {
  //error check
  if (top >= size-1) {
    //std::cout << "Stack full. Could not push " << d << endl;
    GenStack temp(size);
    while(!this->isEmpty()) {
      temp.push(this->pop());
    }
    delete myArray;
    size += 100;
    myArray = new T[size];
    while(!temp.isEmpty()) {
      this->push(temp.pop());
    }
    myArray[++top] = d;
  }
  else {
    myArray[++top] = d;
  }
}

template <class T>
T GenStack<T>::pop() {
  //error check
  if (top < 0) {
    std::cout << "Stack empty. Nothing to pop." << endl;
    return '\0';
  }
  else {
    return myArray[top--];
  }
}

template <class T>
T GenStack<T>::peek() {
  if(top < 0) {
    std::cout  << "Stack empty." << endl;
    return '\0';
  }
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull() {
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty() {
  return (top == -1);
}

#endif
