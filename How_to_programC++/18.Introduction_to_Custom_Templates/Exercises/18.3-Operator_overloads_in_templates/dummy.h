#ifndef DUMMY_H
#define DUMMY_H

class Dummy
{
public:
	Dummy();
	Dummy(int);
	Dummy(const Dummy& d);
	~Dummy();

	bool operator==(const Dummy& rhs);
	int get() const { return m_dummy; }
private:
	int m_dummy;
};

#endif
