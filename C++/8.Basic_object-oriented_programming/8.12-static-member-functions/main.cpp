#include <iostream>

class Something
{
    public:
        static int GetValue() { return s_value; }
    private:
        static int s_value;
};

int Something::s_value = 1;

int main()
{
    std::cout << Something::GetValue() << std::endl;
    return 0;
}
