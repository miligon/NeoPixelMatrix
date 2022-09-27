/*
 * Pixel.h
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#ifndef INC_PIXEL_H_
#define INC_PIXEL_H_

#include "Color.h"

class Pixel : public Color{
private:
	double _brillo = 0.0;
	void _NormalizarLuminosidad(int sR, int sG, int sB);
	double _sRGBtoLin(double colorChannel);
public:
	Pixel(double brillo = 1.0);

	void SetBrillo(double valor);
	double GetBrillo();
	void GetRGB(int* r, int* g, int* b);
	int GetRed();
	int GetGreen();
	int GetBlue();

};

#endif /* INC_PIXEL_H_ */
