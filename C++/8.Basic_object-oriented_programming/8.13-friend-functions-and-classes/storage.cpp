#include <iostream>

class Storage
{
private:
    int m_nvalue;
    double m_dvalue;
public:

    Storage(int nvalue, double dvalue)
        : m_nvalue(nvalue),
          m_dvalue(dvalue)
    {
    }

    friend class Display;
};

class Display
{
public:
    Display(bool displayIntFirst) :
        m_displayIntFirst(displayIntFirst)
    {
    }

    void DisplayItem(const Storage &storage) const
    {
        if (m_displayIntFirst) {
            std::cout << storage.m_nvalue << " " << storage.m_dvalue << std::endl;
        }
        else {
            std::cout << storage.m_dvalue << " " << storage.m_nvalue << std::endl;
        }
    }
private:
    bool m_displayIntFirst;
};

int main()
{
    const Storage cStorage(5, 5.3123);
    const Display cDisplay(false);

    cDisplay.DisplayItem(cStorage);
    
    return 0;
}
