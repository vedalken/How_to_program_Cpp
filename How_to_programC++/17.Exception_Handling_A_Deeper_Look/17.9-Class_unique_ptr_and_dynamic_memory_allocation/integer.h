#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
	explicit Integer(int = 0);
	~Integer();
	void set(int);
	int get() const;
private:
	int m_value;
};

#endif
