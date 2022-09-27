/*
 * Pixel.cpp
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#include <math.h>
#include "Pixel.h"

Pixel::Pixel(double brillo) {
	_brillo = brillo;
}

void Pixel::SetBrillo(double valor){
	_brillo = (valor <= 1.0) ? valor : 1.0;
	_brillo = (_brillo >= 0.0) ? _brillo : 0.0;
}
double Pixel::GetBrillo(){
	return _brillo;
}
double Pixel::_sRGBtoLin(double colorChannel)
{
	if (colorChannel <= 0.04045) {
		return colorChannel / 12.92;
	}
	else {
		return pow(((colorChannel + 0.055) / 1.055), 2.4);
	}
}
void Pixel::_NormalizarLuminosidad(int sR, int sG, int sB) {
	double  vR, vG, vB;
	double Y = 0.0;
	vR = sR / 255;
	vG = sG / 255;
	vB = sB / 255;

	Y = (0.2126 * _sRGBtoLin(vR) + 0.7152 * _sRGBtoLin(vG) + 0.0722 * _sRGBtoLin(vB));
	/*
		if ( Y <= (216/24389)) {       // The CIE standard states 0.008856 but 216/24389 is the intent for 0.008856451679036
			return Y * (24389/27);  // The CIE standard states 903.3, but 24389/27 is the intent, making 903.296296296296296
		} else {
			return pow(Y,(1/3)) * 116 - 16;
		}*/

}
void Pixel::GetRGB(int* r, int* g, int* b) {
	*r = Color::_red * _brillo;
	*g = Color::_green * _brillo;
	*b = Color::_blue * _brillo;
}

int Pixel::GetRed() { return _sRGBtoLin(Color::_red / 255.0 * _brillo) * 255.0; };
int Pixel::GetGreen() { return _sRGBtoLin(Color::_green / 255.0 * _brillo) * 255.0; };
int Pixel::GetBlue() { return _sRGBtoLin(Color::_blue / 255.0 * _brillo) * 255.0; };