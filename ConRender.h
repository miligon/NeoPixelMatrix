#pragma once

#include "Frame.h"

class ConRender {
private:
	int _filas;
	int _columnas;
	//Frame* _display;
	void _SetRGB(int r, int g, int b);

public:
	ConRender();
	void ShowFrame(Frame* frm);
};

