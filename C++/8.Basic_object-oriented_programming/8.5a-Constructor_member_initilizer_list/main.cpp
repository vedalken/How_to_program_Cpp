#include <iostream>

class Something
{
    private:
        const int value_;
    public:
        Something();
        int get() const { return value_; }
};

Something::Something()
    : value_{ 5 }
{
}

int main()
{
    Something something;
    std::cout << something.get() << std::endl;

    return 0;
}
