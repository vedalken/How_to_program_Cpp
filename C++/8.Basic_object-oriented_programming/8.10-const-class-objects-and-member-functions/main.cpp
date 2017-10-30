class Something
{
private:
    int m_value;
public:
    void ResetValue() const { } // Compile error!
    void ResetValue() {}
};

int main()
{
    Something mySomething;
    mySomething.ResetValue();
    return 0;
}
