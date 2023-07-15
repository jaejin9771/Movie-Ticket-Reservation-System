#ifndef TICKETING_H
#define TICKETING_H
#include "Theater.h"
#include "Movie.h"
#include <iostream>
#include <list>
using namespace std;

class Ticketing {
	int genId = 1000; // +
	list<Movie> movieList; // +
public:
	Ticketing();
	~Ticketing();
	int generateId(); // 
	void showMenu(); //
	void showAdminMenu(); //
	void showTitle(); //
	int inputMenu(); // �޴� �Է� +
	void searchMovie(); //��ȭ �˻� +
	void deleteMovie(); // ��ȭ ���� +
	void changeAdmin(); // ������ ��� +
	void addMovie(); // ��ȭ �߰� +
};

#endif
