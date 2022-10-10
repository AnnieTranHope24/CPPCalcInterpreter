#ifndef token_h
#define token_h

#include <string>
using namespace std;

enum TokenType {
   identifier,keyword,number,add,sub,times,divide,lparen,rparen,eof,unrecognized
};

class Token {
public:

  Token();//constructor
  Token(TokenType typ, int line, int col); //constructor signatture
  virtual ~Token(); //destructor, override too

  TokenType getType() const;
  int getLine() const;
  int getCol() const;
  virtual string getLex() const; //abstract method

private://fields
  TokenType type;
  int line,col;
};

class LexicalToken: public Token { //inheritance public: only access the public things
 public:
   LexicalToken(TokenType typ, string* lex, int line, int col);
   ~LexicalToken();

   virtual string getLex() const; //override using the virtual keyword, not just 2 df methods

 private:
   string* lexeme;
};

#endif




