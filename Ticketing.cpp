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
	cout << "================= ���� �ý��� ===================\n";
}
void Ticketing::showMenu() {
	cout << "=================================================\n";
	cout << "1. ��ȭ �˻�\n";
	cout << "2. ����\n";
	cout << "3. ���� ��ȸ\n";
	cout << "4. ���� ���\n";
	cout << "5. ������ ���\n";
	cout << "6. ����\n";
	cout << "=================================================\n";
}

int Ticketing::inputMenu() {
	int menuNum = -1;
	cout << "�Է� : ";
	cin >> menuNum;
	return menuNum;
}

void Ticketing::showAdminMenu() {
	cout << "================ ������ �޴� ================\n";
	cout << "1. ��ȭ �߰�\n";
	cout << "2. ��ȭ ����\n";
	cout << "3. ��ȭ ��ȸ\n";
	cout << "4. ��������\n";
	cout << "============================================\n";
}

void Ticketing::searchMovie() {
	cout << "==== ��ȭ�˻�\n";
	cout << "=================================================\n";

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); it++) {
		cout << "������ȣ : " << it->getId() << "\n" << "���� : " << it->getName() << "\n" << "�帣 : " << it->getGenre() << "\n";
		cout << endl;
	}
	cout << "-------------------------------------------------\n";
}

void Ticketing::deleteMovie() {
	int tempId;
	cout << "==== ��ȭ����\n";
	searchMovie();
	cout << "���� �� ��ȭ ������ȣ : ";
	cin >> tempId;

	list<Movie>::iterator it;
	for (it = movieList.begin(); it != movieList.end(); ++it) {
		if (it->getId() == tempId) {
			movieList.erase(it);
			cout << "��ȭ�� �����Ǿ����ϴ�.\n";
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

	cout << "==== ��ȭ�߰�\n";
	cout << "���� : ";
	cin >> name;
	cout << "�帣 : ";
	cin >> genre;

	Movie movie = Movie(generateId(), name, genre, Theater());

	movieList.push_back(movie);
}

void Ticketing::changeAdmin() {
	int pw = 0;
	cout << "������ ��ȣ �Է� : ";
	cin >> pw;

	if (pw != ADMIN_PASSWORD) {
		cout << "�н����尡 ��ġ���� �ʽ��ϴ�.\n";
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