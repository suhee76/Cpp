#include <iostream>
#include "UI.h"  
using namespace std;

int UI::number = 0;
int UI::type = 0;
int UI::delIndex = 0;

UI::UI() {};

void UI::print() {
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> number;
}
void UI::func1() {
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> type;
}
void UI::func2() {
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> delIndex;
}