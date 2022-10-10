#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return Prog();
}

AST* Parser::Prog() { //-> Expr eof
   AST* result = Expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
      cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
      throw ParseError;
   }

   return result;
}

AST* Parser::Expr() { //-> Term RestExpr
   return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e) { //RestExpr -> +, -, null
   Token* t = scan->getToken();

   if (t->getType() == add) {
      return RestExpr(new AddNode(e,Term()));
   }

   if (t->getType() == sub){
      return RestExpr(new SubNode(e,Term()));
   }

   scan->putBackToken();

   return e;
}

AST* Parser::Term() { //need Storable and RestTerm 
   
   return RestTerm(Storable());
}

AST* Parser::RestTerm(AST* e) { //RestTerm
   // cout << "RestTerm not implemented" << endl;

   // throw ParseError; 
      Token* t = scan->getToken();

   if (t->getType() == times) {
      return RestTerm(new MulNode(e,Storable()));
   }

   if (t->getType() == divide)
      return RestTerm(new DivNode(e,Storable()));

   scan->putBackToken();

   return e;
}

AST* Parser::Storable() {

   AST* result = Factor();
   
 // problem is here  
	Token* nextT = scan->getToken();
	if(nextT->getType() == keyword){
		   Token* t1 = scan->getToken();
		   Token* t2 = scan->getToken();
		   Token* t3 = scan->getToken();
		   		if ((t1->getType() != lparen) || (t2->getType() != number)||(t3->getType() != rparen)) {
			cout << "Syntax Error: Expected a specified memory index in form lparen number rparen, found token at column " << t1->getCol() << endl;
			throw ParseError;
		}
			istringstream in(t2->getLex());
			int val;
			in >> val;
			if(val<0 || val>=10){
				cout << "Error: Memory location is not available " <<"\n";;
				throw ParseError;
			}
		return new StoreNode(result, val);//modify storenode
	}
	scan->putBackToken();
	return result;

   
 
}

AST* Parser::Factor() {
   // cout << "Factor not implemented" << endl;

   // throw ParseError; 
   Token* t = scan->getToken();
      if (t->getType() == number) {
      istringstream in(t->getLex());
      int val;
      in >> val;
      return new NumNode(val);
	  }
	  if (t->getType() == keyword) {
		   Token* t1 = scan->getToken();
		   Token* t2 = scan->getToken();
		   Token* t3 = scan->getToken();		  
		   		if ((t1->getType() != lparen) || (t2->getType() != number)||(t3->getType() != rparen)) {
			cout << "Syntax Error: Expected a specified memory index in form lparen number rparen, found token at column " << t1->getCol() << endl;
			throw ParseError;
		}
			istringstream in(t2->getLex());
			int val;
			in >> val;	
			if(val<0 || val>=10){
				cout << "Error: Memory location is not available " <<"\n";;
				throw ParseError;
			}			
		  
		  return new RecallNode(val); //modify recallnode
		}
	  if (t->getType() == lparen) {
			AST* result = Expr();
			Token* nextT = scan->getToken();

		if (nextT->getType() != rparen) {
			cout << "Syntax Error: Expected a right parentheis, found token at column " << nextT->getCol() << endl;
			throw ParseError;
		}

		return result;
		}
}
   
