#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "GraphicEditor.h"
using namespace std;

int main() {
	cout << "그래픽 에디터입니다." << endl;
	GraphicEditor* gEditor = new GraphicEditor();
	gEditor->printt();

	delete gEditor;
	return 0;
}