/*
 * Frame.h
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#ifndef INC_FRAME_H_
#define INC_FRAME_H_

#include "Pixel.h"

class Frame {
private:
	int _filas;
	int _columnas;
	Pixel** _frame;

public:
	Frame(int tam_x = 1, int tam_y = 1);
	~Frame();
	Pixel& pixel(int fila, int column);
	int GetRows();
	int GetCols();
	void ClearFrame();
	void EstablecerTamaño(int filas, int columnas);
	void SetColorFrame(Color newColor);
	void SetColorFrame(int r, int g, int b);
	void SetGlobalBrigthness(double x);
	void FlipHorizontal();
	void FlipVertical();
	void DrawLine(int x0, int y0, int x1, int y1);
	void DrawRectangulo(int x0, int y0, int x1, int y1);
	void LoadImg(const char *path);

	Frame operator +(Frame frame_operando);
};

#endif /* INC_FRAME_H_ */
