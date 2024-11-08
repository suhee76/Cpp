#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	// 가상 소멸자 (상속 관계에서 소멸자가 올바르게 호출되도록 하기 위해)
	virtual ~Printer() {}
	virtual void print(int pages) = 0;
	void setModel(string m) { model = m; }
	void setManufacturer(string mf) { manufacturer = mf; }
	void setAvailableCount(int c) { availableCount = c; }
};

class InkJetPrinter : protected Printer {
	int availableInk;
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) {
		setModel(model);
		setManufacturer(manufacturer);
		setAvailableCount(availableCount);
		this->availableInk = availableInk;
	}
	~InkJetPrinter() {}

	void print(int pages) override {
		if (availableCount < pages) {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		}
		else if (availableInk < pages) {
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		}
		else {
			availableCount -= pages;
			availableInk -= pages;
			cout << "프린트하였습니다." << endl;
		}
	}

	void printInkJet(int pages) {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount <<
			"장, 남은 잉크 " << availableInk << endl;
	}
};

class LaserPrinter : protected Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) {
		setModel(model);
		setManufacturer(manufacturer);
		setAvailableCount(availableCount);
		this->availableToner = availableToner;
	}
	~LaserPrinter() {}

	void print(int pages) override {
		if (availableCount < pages) {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		}
		else if (availableToner < (pages / 2)) {
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		}
		else {
			availableCount -= pages;
			availableToner -= (pages / 2);
			cout << "프린트하였습니다." << endl;
		}
	}

	void printLaser(int pages) {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount <<
			"장, 남은 토너 " << availableToner << endl;
	}
};

int main() {
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : Officejet V40, HP, 남은 종이 5장, 남은 잉크 10" << endl;
	cout << "레이저 : SCX-6x45, 삼성전자, 남은 종이 3장 남은 토너 20" << endl;

	// 동적 메모리 할당 (new를 사용하여 객체 생성)
	InkJetPrinter* inkP = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laserP = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	int type, count;
	string continuePrint;

	while (true) {
		cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> type >> count;
		if (type == 1) {
			inkP->print(count);
		}
		else if (type == 2) {
			laserP->print(count);
		}
		inkP->printInkJet(count);
		laserP->printLaser(count);

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> continuePrint;
		if (continuePrint == "n" || continuePrint == "N")
			break;
	}

	// 동적으로 생성된 객체 메모리 해제
	delete inkP;
	delete laserP;
}