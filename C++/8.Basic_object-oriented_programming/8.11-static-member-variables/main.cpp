#include <iostream>

class Something
{
    public:
        Something() { m_id = s_idgen++; }
        int GetID() const { return m_id; }
    private:
        static int s_idgen;
        int m_id;
};

int Something::s_idgen = 1;

int main()
{
    Something cFirst;
    Something cSecond;
    Something cLast;

    std::cout << cFirst.GetID() << std::endl;
    std::cout << cSecond.GetID() << std::endl;
    std::cout << cLast.GetID() << std::endl;
    
    return 0;
}
