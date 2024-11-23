#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "UI.h"
using namespace std;

class GraphicEditor {
public:
	vector<Shape*> v;

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
					v.push_back(newShape);
				}
			}
			else if ((pUI->number) == 2) {
				pUI->func2();

				// 삭제할 인덱스가 유효한지 체크
				if (pUI->delIndex >= 0 && pUI->delIndex < v.size()) {
					delete v[pUI->delIndex];
					v.erase(v.begin() + pUI->delIndex);
				}
			}
			else if ((pUI->number) == 3) {
				int index = 0;
				for (Shape* p : v) {
					cout << index << ": ";
					p->paint();
					index++;
				}
			}
			else if ((pUI->number) == 4) {
				break;
			}
		}

	}
};