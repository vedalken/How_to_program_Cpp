#pragma once

#include <vector>

class Prime
{
    public:
	Prime();
	explicit Prime(size_t a_number);
	~Prime();
	
	size_t getNumber() const { return m_number; }
	void setNumber(size_t a_number) { m_number = a_number; }
	
	bool isPrime() const;
	bool isPrime(size_t number) const;
	bool isPrime(size_t number, std::vector<bool>* a_primes) const;

	void factorization() const;
    private:
	/* Helper methods */
	void toggleMultipleBits(std::vector<bool>& a_vec, size_t index) const;
	size_t findFirstPrime(const std::vector<bool>& a_vec, size_t a_startIndex) const;

        size_t m_number;
};
