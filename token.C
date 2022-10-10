#include "token.h"

Token::Token() : //namespace
  type(eof), //initialize fields
  line(0),
  col(0)
{}

Token::~Token() {}//empty body

Token::Token(TokenType typ, int lineNum, int colNum) : 
  type(typ),
  line(lineNum),
  col(colNum)
{}//empty body

TokenType Token::getType() const {
  return type;
}

int Token::getLine() const {
  return line;
}

int Token::getCol() const {
  return col;
}

string Token::getLex() const { return ""; } //accessor

LexicalToken::LexicalToken(TokenType typ, string* lex, int lineNum, int colNum) :
   Token(typ,lineNum,colNum),//invoke supper class's constructor, super in java
   lexeme(lex)
{}

LexicalToken::~LexicalToken() {
   try {
      delete lexeme;//find the destructor and clean up
   } catch (...) {}//if already cleaned
}

string LexicalToken::getLex() const {//accessor
  return *lexeme;//do not have to dereference
}

