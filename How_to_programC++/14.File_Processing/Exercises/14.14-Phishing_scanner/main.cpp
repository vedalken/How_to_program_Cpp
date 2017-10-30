#include "PhishingScanner.h"
#include "Email.h"

int main()
{
	Email nonPhishingEmail("non_phishing_email.txt");
	nonPhishingEmail.phishingScan();

	Email phishingEmail("phishing_email.txt");
	phishingEmail.phishingScan();

	return 0;
}
