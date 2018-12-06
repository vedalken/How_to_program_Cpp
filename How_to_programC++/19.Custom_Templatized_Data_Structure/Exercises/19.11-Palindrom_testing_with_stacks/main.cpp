#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::string text;
    std::stack<char> stackText;

    std::cout << "Input sentence: ";
    std::getline(std::cin, text);

    // add non-space and non-punctuation characters
    // to the stack
    for (char c : text) {
        if (isspace(c) || ispunct(c)) {
            continue;
        }
        stackText.push(c);
    }

    // half length
    const size_t halfLength = stackText.size() / 2;
    const bool oddLength = stackText.size() % 2;

    std::stack<char> halfStack;

    // pop first half to new stack
    for (size_t i = 0; i < halfLength; ++i) {
        halfStack.push(stackText.top());
        stackText.pop();
    }

    if (oddLength) {
        // remove neutral element
        stackText.pop();
    }

    // compare pushed and popped stack
    if (halfStack == stackText) {
        std::cout << "Palindrom" << std::endl;
    }

    return 0;
}
