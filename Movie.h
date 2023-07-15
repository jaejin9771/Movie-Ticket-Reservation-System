#ifndef MOVIE_H
#define MOVIE_H
#include "Theater.h"
#include <iostream>
using namespace std;

class Movie
{
	int id;
	Theater theater;
	string name;
	string genre;
public:
	Movie();
	Movie(int, string, string, Theater);
	string getName();
	string getGenre();
	void setName(string);
	void setGenre(string);
	void print();
	string toString();
	Theater* getTheater();
	~Movie();
	int getId();

};
#endif

