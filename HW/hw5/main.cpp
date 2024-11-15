#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "GraphicEditor.h"
using namespace std;

int main() {
	cout << "±×·¡ÇÈ ¿¡µðÅÍÀÔ´Ï´Ù." << endl;
	GraphicEditor* gEditor = new GraphicEditor();
	gEditor->printt();

	delete gEditor;
	return 0;
}
