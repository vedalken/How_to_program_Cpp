class Count
{
private:
	int m_x;
public:
	Count(): m_x(0) {}
	void print() const;
	friend void setX(Count &count, int value);
};
