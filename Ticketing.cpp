#include "Ticketing.h"
#include <iostream>

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

void Ticketing::showAdminMenu() {
	cout << "================ 관리자 메뉴 ================\n";
	cout << "1. 영화 추가\n";
	cout << "2. 영화 삭제\n";
	cout << "3. 영화 조회\n";
	cout << "4. 메인으로\n";
	cout << "============================================\n";
}