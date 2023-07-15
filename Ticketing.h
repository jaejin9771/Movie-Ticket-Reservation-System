#ifndef TICKETING_H
#define TICKETING_H
#include "Theater.h"
#include "Movie.h"
#include <iostream>
using namespace std;

class Ticketing {
public:
	Ticketing();
	~Ticketing();
	void showMenu();
	void showAdminMenu();
	void showTitle();
};

#endif
