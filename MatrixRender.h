#pragma once
#include "Serial.hpp"
#include "Frame.h"

ref class MatrixRender{
private:
	unsigned char *buffer;
	unsigned char *buf_response;
	unsigned char checksum = 0;
	Serial InterfacePort;
	//Frame* _display;
	void _SetRGB(int r, int g, int b);

public:
	MatrixRender(String^ port);
	bool Inicializar();
	void _FrameToSerial(Frame *frm);
	bool SendFrame(Frame *frm);
};

