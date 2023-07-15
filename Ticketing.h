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
	int inputMenu(); // 메뉴 입력 +
	void searchMovie(); //영화 검색 +
	void deleteMovie(); // 영화 삭제 +
	void changeAdmin(); // 관리자 모드 +
	void addMovie(); // 영화 추가 +
};

#endif
