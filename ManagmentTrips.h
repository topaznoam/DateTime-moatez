#ifndef __ManagmentTrips_H
#define __ManagmentTrips_H
#include "Trip.h"

class ManagmentTrips {
	Trip** trip;
	int index;

public:
	bool operator==(Date d);
	bool operator>(Date d);
	bool operator<(Date d);
};

#endif
