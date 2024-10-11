#include <iostream>
#include <cstring>
#include <sstream> 
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index);
};

Dept::~Dept() {
	if (scores)
		delete[] scores;
}

void Dept::read() {
	cout << "10개 점수 입력>> ";
	string line;
	getline(cin, line); 
	stringstream ss(line); 
	for (int i = 0; i <= size; i++) {
		ss >> scores[i]; 
	}
}

bool Dept::isOver60(int index) {
	return (scores[index] >= 60);
}

int countPass(Dept &dept) { // 참조로 전달
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