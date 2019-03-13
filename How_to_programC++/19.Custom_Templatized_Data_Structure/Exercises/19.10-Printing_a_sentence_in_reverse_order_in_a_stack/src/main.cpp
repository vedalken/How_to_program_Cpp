#include <iostream>
#include <stack>

int main()
{
    std::stack<char> text;
    char c;

    std::cout << "Input sentence: ";
    while ((c = std::cin.get()) != EOF) {
        std::cout << c;
        text.push(c);
    }

    std::cout << "Reversed input sentence: ";
    while (!text.empty()) {
        std::cout << text.top();
        text.pop();
    }
    std::cout << std::endl;

    return 0;
}
