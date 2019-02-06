#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include "infix_expr.h"

class ExprEval
{
public:
    ExprEval(InfixExpr& a_infixExpr);
    int evaluatePostfix();

private:
    int calculate(int a_val1, int a_val2, char op);

    InfixExpr& m_infixExpr;
    Stack<int> m_intStack;
};

#endif
