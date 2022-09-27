/*
 * Sprite.h
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#ifndef INC_SPRITE_H_
#define INC_SPRITE_H_

#include "Frame.h"

class Sprite {
private:
	int _FramesPorSeg = 0;
	int _NumOfFrames = 0;
	int _columnas = 0;
	int _filas = 0;
	Frame* _sprite;
public:
	Sprite(int NumeroDeFrames, int filas, int columnas);
	void insert(int index, Frame frm);
	void append(Frame frm);
	//void remove(int index);
	void SetSpeed(int x);
	int GetSpeed();
	Frame& frame(int index);
};

#endif /* INC_SPRITE_H_ */
