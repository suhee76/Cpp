#include <iostream>
#include "UI.h"  
using namespace std;

int UI::number = 0;
int UI::type = 0;
int UI::delIndex = 0;

UI::UI() {};

void UI::print() {
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> number;
}
void UI::func1() {
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> type;
}
void UI::func2() {
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> delIndex;
}