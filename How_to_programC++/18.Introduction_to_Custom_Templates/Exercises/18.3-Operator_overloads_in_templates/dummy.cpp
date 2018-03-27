#include "dummy.h"

Dummy::Dummy()
  : Dummy(0)
{
}

Dummy::Dummy(int a_dummy)
{
	m_dummy = a_dummy;
}

Dummy::Dummy(const Dummy& a_dummy)
{
	m_dummy = a_dummy.m_dummy;
}

Dummy::~Dummy()
{
}

bool Dummy::operator==(const Dummy& rhs)
{
	return (m_dummy == rhs.m_dummy);
}
