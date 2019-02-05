#include "infix_expr.h"

int main()
{
    InfixExpr e = "(6 + 2) * 5 - 8 / 4";
    e.convertToPostfix();

    std::cout << e.getPostfix() << std::endl;
    return 0;
}
