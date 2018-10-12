#include <fstream>
#include <iostream>
#include "InOut.h"

using namespace std;

InOut::InOut() {

} //default constructor
InOut::~InOut() {

} //destructor

void InOut::openIn(string path) { //opens file w/ path. terminates if failure
  in.open(path);
  if(!in) {
    cerr << "File not found. Execution terminated.\n";
    exit(EXIT_FAILURE);
  }
}
void InOut::closeIn() { //closes ifstream
  in.close();
}
string InOut::readLine() {
  string line;
  getline(in,line);
  return line;
}

void InOut::openOut(string path) {
  out.open(path);
}
void InOut::closeOut() {
  out.close();
}
void InOut::writeLine(string s) {
  out << s << endl;
}
void InOut::write(string s) {
  out << s;
}
