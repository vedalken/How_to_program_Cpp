/* 
 * Class InfixExpr enable valid infix notation expression evaluation.
 */

#ifndef INFIX_EXPR
#define INFIX_EXPR

#include <string>
#include <map>
#include "stack.h"

class InfixExpr
{
public:
    static const char c_postfixNumDelim;

    InfixExpr();
    InfixExpr(const char* a_infix);
    const InfixExpr& operator=(const char* a_infix);
    InfixExpr(const InfixExpr&) = delete;
    InfixExpr& operator=(const InfixExpr&) = delete;

    const std::string& getInfix() const;
    const std::string& getPostfix() const;

    void convertToPostfix();

private:
    static const std::map<char, int> c_operatorPrecedence;

    bool isOperator(char op) const;
    bool precedence(char op1, char op2) const;

    std::string m_infix;
    std::string m_postfix;
    Stack<char> m_stack;
};

#endif
