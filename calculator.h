#ifndef calculator_h
#define calculator_h

#include <string>
 
using namespace std;


class Calculator {
 public:
   Calculator();

   int eval(string expr);
   void store(int val, int loc);
   int recall(int loc);

 private:
   int memories[10];
};

extern Calculator* calc;

#endif

