#include "Ticketing.h"
#include <iostream>

#define ADMIN_PASSWORD 1234

enum {
	SEARCH = 1,
	RESERVATION,
	RESERVATION_CHECK,
	RESERVATION_CANCEL,
	ADMIN,
	EXIT
};
enum {
	ADD_MOVIE = 1,
	DELETE_MOVIE,
	SEARCH_MOVIE,
	MAIN
};
Ticketing::Ticketing()
{

}

Ticketing::~Ticketing()
{

}
void Ticketing::showTitle() {
	cout << "================= 예매 시스템 ===================\n";
}
void Ticketing::showMenu() {
	cout << "=================================================\n";
	cout << "1. 영화 검색\n";
	cout << "2. 예약\n";
	cout << "3. 예약 조회\n";
	cout << "4. 예약 취소\n";
	cout << "5. 관리자 모드\n";
	cout << "6. 종료\n";
	cout << "=================================================\n";
}

int Ticketing::inputMenu() {
	int menuNum = -1;
	cout << "입력 : ";
	cin >> menuNum;
	return menuNum;
}

void Ticketing::showAdminMenu() {
	cout << "================ 관리자 메뉴 ================\n";
	cout << "1. 영화 추가\n";
	cout << "2. 영화 삭제\n";
	cout << "3. 영화 조회\n";
	cout << "4. 메인으로\n";
	cout << "============================================\n";
}

void Ticketing::searchMovie() {
	cout << "==== 영화검색\n";
	cout << "=================================================\n";

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); it++) {
		cout << "고유번호 : " << it->getId() << "\n" << "제목 : " << it->getName() << "\n" << "장르 : " << it->getGenre() << "\n";
		cout << endl;
	}
	cout << "-------------------------------------------------\n";
}
bool Ticketing::checkMovie(int id) {
	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); it++) {
		if (it->getId() == id) {
			return true;
		}
	}
	return false;
}

void Ticketing::reserveMovie() {
	int tempId;
	int row, col;
	list<Movie>::iterator it;

	cout << "==== 영화예약\n";
	searchMovie();
	cout << "예약 할 영화 고유번호 : "; // 예약 할 번호가 없으면 다시 입력 부탁
	cin >> tempId;
	checkMovie(tempId);
	cout << "좌석번호(행^열) >> ";
	cin >> row >> col;

	for (it = movieList.begin(); it != movieList.end(); ++it) {
		if (it->getId() == tempId) {
			Theater* theater = it->getTheater();

			if (theater->getSeat(row, col) == 1) {
				cout << "이미 예약된 좌석입니다.\n";
				goto EXIT;
			}

			theater->setSeat(1, row, col);

			cout << "예약되었습니다.\n";
			break;
		}
	}
EXIT: NULL;
}

void Ticketing::initMenu() {
	showTitle();
	while (true) {
		showMenu();

		int menuNum = inputMenu();
		switch (menuNum) {
		case SEARCH:
			searchMovie();
			break;
		case RESERVATION:
			reserveMovie();
			break;
		case RESERVATION_CHECK:
			reserveCheck(-1);
			break;
		case RESERVATION_CANCEL:
			reserveCancel();
			break;
		case ADMIN:
			changeAdmin();
			break;
		case EXIT:
			exit(0);
			break;
		}
	}
}

void Ticketing::reserveCancel() {
	int tempId;
	int row, col;
	cout << "==== 예약취소\n";

	cout << "예약취소 할 영화 고유번호 : ";
	cin >> tempId;
	checkMovie(tempId);
	reserveCheck(tempId);
	cout << "좌석 선택(행^열) : ";
	cin >> row >> col;

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); ++it) {
		if (it->getId() == tempId) {
			Theater* theater = it->getTheater();

			if (theater->getSeat(row, col) == -1) {
				cout << "예약되지 않은 좌석은 취소할 수 없습니다.\n";
				goto EXIT;
			}

			theater->setSeat(-1, row, col);
			cout << "예약 취소 되었습니다.\n";
			break;
		}
	}
EXIT: NULL;
}

void Ticketing::reserveCheck(int _tempId) {
	int tempId;
	cout << "==== 예약조회\n";
	searchMovie();
	if (movieList.size() == 0) {
		cout << "예약 가능한 영화가 없습니다.\n";
		return;
	}
	if (_tempId == -1) {
		cout << "예약조회 할 영화 고유번호 : ";
		cin >> tempId;
	}
	else {
		tempId = _tempId;
	}

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); ++it) {
		if (it->getId() == tempId) {
			Theater* theater = it->getTheater();
			theater->printSeat();
			break;
		}
	}
}

void Ticketing::deleteMovie() {
	int tempId;
	cout << "==== 영화삭제\n";
	searchMovie();
	cout << "삭제 할 영화 고유번호 : ";
	cin >> tempId;

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); ++it) {
		if (it->getId() == tempId) {
			movieList.erase(it);
			cout << "영화가 삭제되었습니다.\n";
			break;
		}
	}
}

int Ticketing::generateId() {
	return genId++;
}

void Ticketing::addMovie() {
	string name;
	string genre;

	cout << "==== 영화추가\n";
	cout << "제목 : ";
	cin >> name;
	cout << "장르 : ";
	cin >> genre;

	Movie movie = Movie(generateId(), name, genre, Theater());

	movieList.push_back(movie);
}

void Ticketing::changeAdmin() {
	int pw = 0;
	cout << "관리자 암호 입력 : ";
	cin >> pw;

	if (pw != ADMIN_PASSWORD) {
		cout << "패스워드가 일치하지 않습니다.\n";
		initMenu();
	}

	while (true) {
		showAdminMenu();
		int menuNum = inputMenu();
		switch (menuNum) {
		case ADD_MOVIE:
			addMovie();
			break;
		case DELETE_MOVIE:
			deleteMovie();
			break;
		case SEARCH_MOVIE:
			searchMovie();
			break;
		case MAIN:
			initMenu();
			break;
		default:
			break;
		}
	}
}