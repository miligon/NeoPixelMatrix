/*
 * Color.cpp
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#include "Color.h"

Color::Color(int r, int g, int b) {
	_red = r;
	_green = g;
	_blue = b;
}

void Color::GetRGB(int *r, int *g, int *b){
	*r = _red;
	*g = _green;
	*b = _blue;
}

void Color::SetRGB(int r, int g, int b){
	_red = r;
	_green = g;
	_blue = b;
}

void Color::SetRed(int x){
	_red = x;
}
int Color::GetRed(){
	return _red;
}
void Color::SetGreen(int x){
	_green = x;
}
int Color::GetGreen(){
	return _green;
}
void Color::SetBlue(int x){
	_blue = x;
}
int Color::GetBlue(){
	return _blue;
}

Color Color::operator +(Color color_operando){
	int rojo = (int)(this->_red + color_operando.GetRed());
	int verde = (int)(this->_green + color_operando.GetGreen());
	int azul = (int)(this->_blue + color_operando.GetBlue());
	return Color(rojo, verde, azul);
}
