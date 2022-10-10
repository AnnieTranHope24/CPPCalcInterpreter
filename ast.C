#include "ast.h"
#include <iostream>
#include "calculator.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}
//unary node
UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}
//unary node

//store and recalll
StoreNode::StoreNode(AST* sub, int mLocation):
	UnaryNode(sub),
	location(mLocation)
{}
int StoreNode::evaluate(){
	int result = getSubTree() ->evaluate();
	calc->store(result, location); // modify store() too, add a parameter location
	return result;
}
RecallNode::RecallNode(int mLocation):
	AST(),
	location(mLocation)
{}
int RecallNode::evaluate(){
	return calc->recall(location);
}
//store and recall


AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}
MulNode::MulNode(AST* left, AST* right):
   BinaryNode(left,right)
{}
int MulNode::evaluate() {
	return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}
DivNode::DivNode(AST* left, AST* right):
   BinaryNode(left,right)
{}
int DivNode::evaluate() {
	return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}


//numNode
NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}

//StoreNode
