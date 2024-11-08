#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	// ���� �Ҹ��� (��� ���迡�� �Ҹ��ڰ� �ùٸ��� ȣ��ǵ��� �ϱ� ����)
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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
		else if (availableInk < pages) {
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
		else {
			availableCount -= pages;
			availableInk -= pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}

	void printInkJet(int pages) {
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount <<
			"��, ���� ��ũ " << availableInk << endl;
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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
		else if (availableToner < (pages / 2)) {
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
		else {
			availableCount -= pages;
			availableToner -= (pages / 2);
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}

	void printLaser(int pages) {
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount <<
			"��, ���� ��� " << availableToner << endl;
	}
};

int main() {
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : Officejet V40, HP, ���� ���� 5��, ���� ��ũ 10" << endl;
	cout << "������ : SCX-6x45, �Ｚ����, ���� ���� 3�� ���� ��� 20" << endl;

	// ���� �޸� �Ҵ� (new�� ����Ͽ� ��ü ����)
	InkJetPrinter* inkP = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laserP = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	int type, count;
	string continuePrint;

	while (true) {
		cout << "\n������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> type >> count;
		if (type == 1) {
			inkP->print(count);
		}
		else if (type == 2) {
			laserP->print(count);
		}
		inkP->printInkJet(count);
		laserP->printLaser(count);

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> continuePrint;
		if (continuePrint == "n" || continuePrint == "N")
			break;
	}

	// �������� ������ ��ü �޸� ����
	delete inkP;
	delete laserP;
}