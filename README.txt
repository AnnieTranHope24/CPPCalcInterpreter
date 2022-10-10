Annie Tran

Changes that I made:

ast.C, ast.h
- added the StoreNode that extends UnaryNode, RecallNode that extends AST
- for exercise 6, I added to the constructors of each class above a parameter
typed int and an int field that indicate the index of the memory.

parser.C, parser.h
- updated Term() so it returned RestTerm(Storable())
- updated RestTerm() so it handled times and divide
- updated the grammar for Storable to Storable  --> Factor S (number) | Factor
- updated Storable so it followed the new grammar
- updated the grammar for Factor to Factor --> number|R (number) | (Expr)
- updated Factor so it followed the new grammar

calculator.C, calculator.h
- instead of having a field 'memory' typed int, calculator now has a field 'memories,'
which is an array sized 10 of integers.
- added an int parameter to store() and recall() to indicate the index of the memory

Examples of expressions for testing
- 4S(8) + R(8) =8
- (3-5S(2))*R(2) = -10
- 7S(8)/R(8) + R(2) = 1

Through this assignment, I learned how to write code based on a piece of grammar. The key is 
to break the grammar into small pieces and consider all the cases possible. I also understand 
why being able to look 1 character ahead and put it back if needed is useful. I learned more 
about the C++ programming language. One thing that I found pretty inconvenient about C++ is 
when I made any changes to any classes, I needed to change both the .C file and the header file.
I forgot to do that here and there, and it took me quite much time to fix the errors.
