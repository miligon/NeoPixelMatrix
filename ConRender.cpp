#include <iostream>
#include "ConRender.h"

using System::Console;
using namespace std;

ConRender::ConRender()
{
	//Console::OutputEncoding = System::Text::Encoding::UTF7;
	Console::Clear();
}

void ConRender::_SetRGB(int r, int g, int b)
{
	cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void ConRender::ShowFrame(Frame* frm) {
	
	//double brillo_anterior = 0.0;
	cout << endl;
	frm->FlipHorizontal();
	for (int i = 0; i < frm->GetRows(); i++) {
		for (int k = 0; k < frm->GetCols(); k++) {
			int r, g, b;
			//brillo_anterior = frm->pixel(i, k).GetBrillo();
			frm->pixel(i, k).GetRGB(&r, &g, &b);
			_SetRGB(r, g, b);
			//cout << "\xDB";
			cout << "\xFE ";
			//cout << "(" << r <<","<<g<<","<<b<<") ";
		}
		cout << endl;
	}
	frm->FlipHorizontal();
	Console::ResetColor();
}
