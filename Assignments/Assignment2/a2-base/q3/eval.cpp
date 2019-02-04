
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;

Token performOp(Token val1, Token val2, Token op);

int main () 
{
    cout << endl;
    cout << "This program can evalute a single well-formed arithmetic expression in two ways:" << endl;
    cout << "   1. Pass a text file from the shell. ex) ./infixeval < textfile.txt" << endl;
    cout << "   2. Input a single well-formed arithmetic expression followed by pressing enter and then the appropriate end of file character (normally Ctrl+d or Ctrl+z)" << endl;

    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || !(opstack.isEmpty()))
    {
        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                Token val2 = numstack.pop();
                Token op = opstack.pop();
                Token val1 = numstack.pop();
                Token result = performOp(val1, val2, op);
                numstack.push(result);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if (!(opstack.isEmpty()) && (opstack.peek().tt == pltok || opstack.peek().tt == mitok 
                || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token val2 = numstack.pop();
                Token op = opstack.pop();
                Token val1 = numstack.pop();
                Token result = performOp(val1, val2, op);
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (!(opstack.isEmpty()) && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token val2 = numstack.pop();
                Token op = opstack.pop();
                Token val1 = numstack.pop();
                Token result = performOp(val1, val2, op);
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    t = numstack.peek();
    cout << endl << "Answer: " << t;


    cout << endl;

    return 0;
} // main()

// Desc:    Performs operation on two integer tokens
// Inputs:  Token val1 - token of the first value
//          Token val2 - token of the second value
//          Token op - token of the operation, will be of token type pltok, mitok, asttok, or slashtok
// Return:  Returns the result of applying the operation on the two input tokens
Token performOp(Token val1, Token val2, Token op)
{
    Token result;
    result.tt = integer;
    // Perform operation
    switch(op.tt)
    {
        case pltok:
            result.val = val1.val + val2.val;
            break;
        case mitok:
            result.val = val1.val - val2.val;
            break;
        case asttok:
            result.val = val1.val * val2.val;
            break;
        case slashtok:
            result.val = val1.val / val2.val;
            break;
    }
    
    return result;

} // performOp()
