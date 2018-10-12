#ifndef SYNCHECK_H
#define SYNCHECK_H

#include <iostream>
#include "GenStack.h"
#include "inOut.h"

class SynCheck {
public:
  SynCheck();
  ~SynCheck();

  bool delimMatch(ifstream& file, GenStack<char>& stack); //matches delimiters
};

#endif
