#include "GenStack.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  GenStack g(50);
  cout << g.size << endl;
  g.push('c');
  g.push('a');
  g.push('t');
  cout << g.pop() << endl;
  cout << g.pop() << endl;
  cout << g.pop() << endl;
}
