#include <iostream>
using namespace std;

#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
	mem[size] = {};
}

Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address) {
	return mem[address];
}

void Ram::write(int address, char value) {
	mem[address] = value;
}