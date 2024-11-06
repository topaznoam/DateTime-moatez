#ifndef __ManagementTrip_H
#define __ManagementTrip_H
#include "Trip.h"
class ManagementTrip {
	Trip** trips;
	int index;
public:
	ManagementTrip();
	const ManagementTrip& operator=(const ManagementTrip& other);
	void operator+=(Trip* other);
	void operator>>(Trip* other);
	void operator-=(Trip* other);

};
#endif