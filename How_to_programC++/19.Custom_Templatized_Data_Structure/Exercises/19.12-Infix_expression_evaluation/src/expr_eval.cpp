#include <cmath>
#include "expr_eval.h"

ExprEval::ExprEval(InfixExpr& a_infixExpr)
    : m_infixExpr(a_infixExpr), m_intStack()
{
}

/*
 * Function: calculate
 * -------------------
 * Function evaluate arguments of binary operator type.
 */

int ExprEval::calculate(int a_val1, int a_val2, char op)
{
    switch (op)
    {
        case '+': return a_val1 + a_val2;
        case '-': return a_val1 - a_val2;
        case '*': return a_val1 * a_val2;
        case '/': return a_val1 / a_val2;
        case '^': return pow(a_val1, a_val2);
        case '%': return a_val1 % a_val2;
    }

    return 0;
}

/*
 * Function: evaluatePostfix
 * -------------------------
 * Function evaluate postfix expression.
 */

int ExprEval::evaluatePostfix()
{
    const std::string& postfix = m_infixExpr.getPostfix();

    if (postfix.empty()) {
        // "lazy" infix to postfix conversion
        m_infixExpr.convertToPostfix();
    }

    // read postfix expression
    for (auto it = postfix.cbegin(); it != postfix.cend(); ++it)
    {
        if (isdigit(*it))
        {
            std::string number;
            while (*it != InfixExpr::c_postfixNumDelim)
            {
                number.push_back(*it);
                ++it;
            }
            // discard postfix number delimiter

            m_intStack.push(std::stoi(number));
        }
        else {
            // extract two elements
            int x = 0, y = 0;
            m_intStack.pop(x);
            m_intStack.pop(y);
            // calculate: `y op x`
            int result = calculate(y, x, *it);
            m_intStack.push(result);
        }
    }

    // result of postfix expression evaluation
    int result = 0;
    m_intStack.pop(result);

    return result;
}
