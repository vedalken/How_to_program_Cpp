#include <iostream>
#include <cstdint>

class RGBA
{
    public:
        RGBA(uint8_t=0, uint8_t=0, uint8_t=0, uint8_t=255);
        void print() const;
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;
};

RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
{
}

void RGBA::print() const
{
    std::cout << "r=" << (int)m_red << " g=" << (int)m_green 
        << " b=" << (int)m_blue << " alpha=" << (int)m_alpha << std::endl;
}

int main()
{
    RGBA teal(0, 127, 127);
    teal.print();

    return 0;
}
