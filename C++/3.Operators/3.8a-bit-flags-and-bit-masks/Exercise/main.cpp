#include <iostream>

int main()
{
	unsigned char option_viewed = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_favorited = 0x04;
	unsigned char option_shared = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char myArticleFlags = 0;
	
	myArticleFlags |= option_viewed;

	if (myArticleFlags & option_deleted) {
		// do something
	}

	// unset the article as favorite
	myArticleFlags &= ~option_favorited;

	return 0;
}
