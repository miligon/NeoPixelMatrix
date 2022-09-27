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
	Frame(int tam_x, int tam_y);
	~Frame();
	Pixel& pixel(int fila, int column);
	int GetRows();
	int GetCols();
	void ClearFrame();
	void SetColorFrame(int r, int g, int b);
	void SetGlobalBrigthness(double x);
	void DrawLine(int x0, int y0, int x1, int y1);
	void DrawRectangulo(int x0, int y0, int x1, int y1);
	void LoadImg(const char *path);
};

#endif /* INC_FRAME_H_ */
