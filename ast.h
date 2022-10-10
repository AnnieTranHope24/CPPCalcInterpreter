#ifndef ast_h
#define ast_h

using namespace std;

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
};

class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};
class StoreNode : public UnaryNode {
 public:
   StoreNode(AST* sub, int mLocation);

   int evaluate();
 private:
   int location;   
};

class RecallNode : public AST {
 public:
   RecallNode(int mLocation);

   int evaluate();
 private:
   int location;   
};


class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);
   
   int evaluate();
};

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);

   int evaluate();
};
class MulNode : public BinaryNode {
 public:
   MulNode(AST* left, AST* right);

   int evaluate();
};
class DivNode : public BinaryNode {
 public:
   DivNode(AST* left, AST* right);

   int evaluate();
};

class NumNode : public AST {
 public:
   NumNode(int n);

   int evaluate();

 private:
   int val;
};



#endif

