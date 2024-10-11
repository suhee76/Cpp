#include <iostream>
#include <cstring>
#include <sstream> // stringstream을 사용하기 위한 헤더 파일
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this -> size =  size;
		scores = new int[size];
	}
	Dept(const Dept& dept);
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index);
};

Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	scores = new int[size]; // 메모리 할당
	for (int i = 0; i < size; i++) {
		scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {
	if (scores)
		delete[] scores;
}

void Dept::read() {
	cout << "10개 점수 입력>> ";
	string line;
	getline(cin, line); // 한 줄 입력 받기
	stringstream ss(line); // 읽은 문자열을 stringstream으로 변환
	for (int i = 0; i <= size; i++) {
		ss >> scores[i]; // 스페이스로 구분된 점수 읽기
	}
}

bool Dept::isOver60(int index) {
	return (scores[index] >= 60);
}

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}