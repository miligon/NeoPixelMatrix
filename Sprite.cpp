/*
 * Sprite.cpp
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#include "Sprite.h"

Sprite::Sprite(int NumeroDeFrames, int filas, int columnas)
{
	_NumOfFrames = NumeroDeFrames;
	_sprite = new Frame[1];
	for (int i = 0; i < NumeroDeFrames; i++) 
	{
		_sprite->EstablecerTamaño(filas, columnas);
	}
}
void Sprite::insert(int index, Frame frm) {
	if (_NumOfFrames <= index) 
	{
		Frame* buf = new Frame[_NumOfFrames + 1];
  	    
		for (int i = 0; i < index - 1; i++) {
			buf[i] = _sprite[i];
		}
		buf[index - 1] = frm;
		for (int i = index - 1; i < _NumOfFrames; i++) {
			buf[i + 1] = _sprite[i];

		}
		_NumOfFrames += 1;
		_sprite = buf;
	}
}
void Sprite::append(Frame frm) {
	Frame* buf = new Frame[_NumOfFrames + 1];

	for (int i = 0; i < _NumOfFrames; i++) {
		buf[i] = _sprite[i];
	}
	buf[_NumOfFrames] = frm;
	_NumOfFrames += 1;
	_sprite = buf;
}
/*
void Sprite::remove(int index) {
	Frame* buf = new Frame[_NumOfFrames - 1];

	for (int i = 0; i < _NumOfFrames; i++) {
			buf[i] = _sprite[i];
		}
	}
	buf[_NumOfFrames] = frm;
	_NumOfFrames += 1;
}*/

void Sprite::SetSpeed(int x) {
	_FramesPorSeg = x;
}

int Sprite::GetSpeed() {
	return _FramesPorSeg;
}
Frame& Sprite::frame(int index) {
	return _sprite[index];
}
