/*
 * Matriz.h
 *
 *  Created on: Sep 22, 2022
 *      Author: USER
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "Pixel.h"

class Matriz {
private:
	int _filas = 0;
	int _columnas = 0;
	Pixel** _frame;
	uint16_t* _pwmData;
public:
	Matriz(int filas, int columnas);
	virtual ~Matriz();
	Pixel& pixel(int fila, int columna);
	const int NumLeds();
	void ClearFrame();
	void SetGlobalBrigthness(double x);
	uint32_t RGBto32bits(Pixel pix);
	uint32_t* GetNeoPixelData();
	uint32_t NeoPixelDataLength();
};

#endif /* MATRIZ_H_ */
