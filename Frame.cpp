/*
 * Frame.cpp
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#include "Frame.h"

Frame::Frame(int tam_x, int tam_y) {
	_filas = tam_y;
	_columnas = tam_x;
	// Inicializa un array de n filas de tipo Pixel
	_frame = new Pixel* [_filas];
	// Cada fila se inicializa como un array de n columnas de tipo Pixel
	for (int i = 0; i < _filas; ++i) {
		_frame[i] = new Pixel[_columnas];
	}
}

Frame::~Frame() {
	// Elimina la matriz inicializada en el constructor
	for (int i = 0; i < _filas; ++i) {
		delete[] _frame[i];
	}
	delete [] _frame;
}


int Frame::GetRows() { return _filas; }
int Frame::GetCols() { return _columnas; }

void Frame::EstablecerTamaņo(int filas, int columnas) {

	// Elimina la matriz inicializada en el constructor
	for (int i = 0; i < _filas; ++i) {
		delete[] _frame[i];
	}
	delete[] _frame;

	_filas = filas;
	_columnas = columnas;
	
	// Inicializa un array de n filas de tipo Pixel
	_frame = new Pixel * [_filas];
	// Cada fila se inicializa como un array de n columnas de tipo Pixel
	for (int i = 0; i < _filas; ++i) {
		_frame[i] = new Pixel[_columnas];
	}
}

Pixel& Frame::pixel(int fila, int columna){
	return _frame[fila][columna];
}

void Frame::SetColorFrame(Color newColor) {
	int r, g, b;
	r = newColor.GetRed();
	g = newColor.GetGreen();
	b = newColor.GetBlue();
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j).SetRGB(r, g, b);
		}
	}
}

void Frame::SetColorFrame(int r, int g, int b) {
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j).SetRGB(r, g, b);
		}
	}
}

void Frame::ClearFrame() {
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j).SetRGB(0, 0, 0);
			this->pixel(i, j).SetBrillo(1.0);
		}
	}
}

void Frame::SetGlobalBrigthness(double x) {
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j).SetBrillo(x);
		}
	}
}

void Frame::FlipHorizontal() {
	Frame buffer(_columnas, _filas);
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			buffer.pixel(i, 15 - j) = this->pixel(i, j);
		}
	}

	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j) = buffer.pixel(i, j);
		}
	}
}

void Frame::FlipVertical() {
	Frame buffer(_columnas, _filas);
	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			buffer.pixel(15-i, j) = this->pixel(i, j);
		}
	}

	for (int i = 0; i < _filas; i++) {
		for (int j = 0; j < _columnas; j++) {
			this->pixel(i, j) = buffer.pixel(i, j);
		}
	}
}

void Frame::DrawLine(int x0, int y0, int x1, int y1){

}

void Frame::DrawRectangulo(int x0, int y0, int x1, int y1){

}

void Frame::LoadImg(const char* path) {

}

Frame Frame::operator +(Frame frame_operando) {
	Frame buf(16,16);
	//Pixel resultado;
	//for (int i = 0; i < this->GetRows(); i++) {
	//	for (int j = 0; j < this->GetCols(); j++) {
			//resultado = this->pixel(i, j) + frame_operando.pixel(i, j);
			//buf.pixel(i, j) = resultado;
		//}
	//}
	return buf;
}
