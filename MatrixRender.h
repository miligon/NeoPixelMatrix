#pragma once
#include "Serial.hpp"
#include "Frame.h"

ref class MatrixRender{
private:
	int _filas;
	int _columnas;
	Serial InterfacePort;
	//Frame* _display;
	void _SetRGB(int r, int g, int b);

public:
	MatrixRender(String^ port);
	bool Inicializar();
	void ShowFrame(Frame* frm);
};

