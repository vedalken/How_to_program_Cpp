#include "infix_expr.h"
#include "expr_eval.h"

int main()
{
    InfixExpr e("(60+21)*12 - 80512/40");
    ExprEval exprEval(e);

    // evaluate postfix expression    
    int result = exprEval.evaluatePostfix();
 
    std::cout << "infix: " << e.getInfix() << std::endl;
    std::cout << "postfix: " << e.getPostfix() << std::endl;
    std::cout << "result: " << result << std::endl;

    return 0;
}
