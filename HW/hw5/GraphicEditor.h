#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "UI.h"
using namespace std;

class GraphicEditor {
public:
	Shape* pStart = NULL;
	Shape* pLast = NULL;

	void printt() {
		UI ui;
		UI* pUI = &ui;

		while (true) {
			pUI->print();
			if ((pUI->number) == 1) {
				pUI->func1();
				Shape* newShape = NULL;
				if ((pUI->type) == 1) {
					newShape = new Line();
				}
				else if ((pUI->type) == 2) {
					newShape = new Circle();
				}
				else if ((pUI->type) == 3) {
					newShape = new Rect();
				}

				if (newShape) {
					if (pStart == NULL) {
						pStart = newShape;  // ó������ ������ �߰��ϴ� ���
						pLast = newShape;
					}
					else {
						pLast->add(newShape);  // �������� �߰�
						pLast = newShape;  // ���� �߰��� ������ �������� �ȴ�.
					}
				}
			}
			else if ((pUI->number) == 2) {
				pUI->func2();

				// ������ �ε����� ��ȿ���� üũ
				if (pUI->delIndex >= 0) {
					Shape* prev = NULL;
					Shape* current = pStart;
					int index = 0;

					// ���� �۾�
					while (current != NULL && index < pUI->delIndex) {
						prev = current;
						current = current->getNext();
						index++;
					}

					if (current != NULL) {
						if (prev != NULL) {
							prev->add(current->getNext());  // ������ ��带 ���� ���� ����
						}
						else {
							pStart = current->getNext();  // ù ��° ��带 ������ ���
						}
						delete current; // ����
					}
				}
			}
			else if ((pUI->number) == 3) {
				int index = 0;
				Shape* p = pStart;
				while (p != NULL) {
					cout << index << ": ";
					p->paint();
					p = p->getNext();
					index++;
				}
			}
			else if ((pUI->number) == 4) {
				break;
			}
		}

	}
};