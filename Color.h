/*
 * Color.h
 *
 *  Created on: Sep 21, 2022
 *      Author: USER
 */

#ifndef INC_COLOR_H_
#define INC_COLOR_H_

class Color {
protected:
	int _red;
	int _blue;
	int _green;
public:
	Color(int r=0, int g=0, int b=0);

	void GetRGB(int *r, int *g, int *b);
	void SetRGB(int r, int g, int b);

	void SetRed(int x);
	int GetRed();
	void SetGreen(int x);
	int GetGreen();
	void SetBlue(int x);
	int GetBlue();

	Color operator +(Color color_operando);
};

#endif /* INC_COLOR_H_ */
