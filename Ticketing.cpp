#include "Ticketing.h"
#include <iostream>

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

void Ticketing::showAdminMenu() {
	cout << "================ ������ �޴� ================\n";
	cout << "1. ��ȭ �߰�\n";
	cout << "2. ��ȭ ����\n";
	cout << "3. ��ȭ ��ȸ\n";
	cout << "4. ��������\n";
	cout << "============================================\n";
}