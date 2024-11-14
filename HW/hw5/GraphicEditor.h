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
						pStart = newShape;  // 처음으로 도형을 추가하는 경우
						pLast = newShape;
					}
					else {
						pLast->add(newShape);  // 마지막에 추가
						pLast = newShape;  // 새로 추가된 도형이 마지막이 된다.
					}
				}
			}
			else if ((pUI->number) == 2) {
				pUI->func2();

				// 삭제할 인덱스가 유효한지 체크
				if (pUI->delIndex >= 0) {
					Shape* prev = NULL;
					Shape* current = pStart;
					int index = 0;

					// 삭제 작업
					while (current != NULL && index < pUI->delIndex) {
						prev = current;
						current = current->getNext();
						index++;
					}

					if (current != NULL) {
						if (prev != NULL) {
							prev->add(current->getNext());  // 삭제할 노드를 이전 노드와 연결
						}
						else {
							pStart = current->getNext();  // 첫 번째 노드를 삭제할 경우
						}
						delete current; // 삭제
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