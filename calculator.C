#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>


Calculator::Calculator()
{
    for(int i = 0; i < 10; ++i)
        memories[i] = 0;
}

int Calculator::eval(string expr) {

   Parser* parser = new Parser(new istringstream(expr));
   
   AST* tree = parser->parse();
   
   int result = tree->evaluate();
   
   delete tree;
   
   delete parser;
   
   return result;
}

void Calculator::store(int val, int loc) {
   memories[loc]= val;
}

int Calculator::recall(int loc) {//modify recall
   return memories[loc];
}
