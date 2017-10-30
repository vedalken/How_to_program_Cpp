#include <iostream>
#include "Time.h"

int main()
{
	Time wakeup(6, 45, 0);
	const Time noon(12, 0, 0);

	                      // OBJECT     MEMBER FUNCTION
	wakeup.setHour(18);   // non-const  non-const

	//noon.setHour(12);     // const      non-const --> ERROR!

	wakeup.getHour();     // non-const  const

	noon.getMinute();     // const      const
	noon.printUniversal();// const      const

	//noon.printStandard(); // const      non-const --> ERROR!

	return 0;
}
