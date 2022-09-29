/*
 * Matriz.cpp
 *
 *  Created on: Sep 22, 2022
 *      Author: USER
 */


#include "stm32f4xx_hal.h"
#include "Matriz.h"

Matriz::Matriz(int filas, int columnas) {
	_filas = filas;
	_columnas = columnas;
	// Inicializa un array de n filas de tipo Pixel
	_frame = new Pixel* [_filas];
	// Cada fila se inicializa como un array de n columnas de tipo Pixel
	for (int i = 0; i < _filas; ++i) {
		_frame[i] = new Pixel[_columnas];
	}
	_pwmData = new uint16_t[(24*NumLeds())+50];
}

Matriz::~Matriz() {
	// Elimina la matriz inicializada en el constructor
	for (int i = 0; i < _filas; ++i) {
		delete[] _frame[i];
	}
	delete [] _frame;
}

Pixel& Matriz::pixel(int fila, int columna){
	return _frame[fila][columna];
}

const int Matriz::NumLeds(){return _filas*_columnas;};
uint32_t Matriz::RGBto32bits(Pixel pix){
	return (uint32_t)((pix.GetGreen()<<16) | (pix.GetRed()<<8) | (pix.GetBlue()));
}

void Matriz::ClearFrame(){
	for (int i = 0; i<_filas; i++){
		for (int j = 0; j<_columnas; j++){
			this->pixel(i,j).SetRGB(0,0,0);
			this->pixel(i,j).SetBrillo(1.0);
		}
	}
}

void Matriz::SetGlobalBrigthness(double x){
	for (int i = 0; i<_filas; i++){
		for (int j = 0; j<_columnas; j++){
			this->pixel(i,j).SetBrillo(x);
		}
	}
}

uint32_t Matriz::NeoPixelDataLength(){return (24*NumLeds())+50;}

uint32_t* Matriz::GetNeoPixelData()
{
	delete [] _pwmData;  // Elimina los datos del
	_pwmData = new uint16_t[(24*NumLeds())+50];
	uint32_t indx=0;
	uint32_t color;

	// Filas pares
	for (int i=0; i<_filas; i+=2){
		for (int j=0; j<_columnas; j++){
			color = RGBto32bits(this->pixel(i,j));
			indx = (j*24)+(i*(24*_columnas));
			//Transforma los bits en pulsos de pwm
			for (int i=23; i>=0; i--){
				if (color&(1<<i)){
					_pwmData[indx] = 60;  // 2/3 of 90
				}else{
					_pwmData[indx] = 30;  // 1/3 of 90
				}
				indx++;
			}
		}
	}
	// Filas impares
	for (int i=1; i<_filas; i+=2)
		{
			for (int j=0; j<_columnas; j++)
			{
				color = RGBto32bits(this->pixel(i,j));

				indx = ((_columnas-j)*24)+(i*(24*_columnas))-24;
				//Transforma los bits en pulsos de pwm
				for (int i=23; i>=0; i--)
				{
					if (color&(1<<i)){
						_pwmData[indx] = 60;  // 2/3 of 90
					}
					else{
						_pwmData[indx] = 30;  // 1/3 of 90
					}
					indx++;
				}
			}
		}

	// Pulso de reset
	indx = 24 * _columnas * _filas;
	for (int i=0; i<50; i++)
	{
		_pwmData[indx] = 0;
		indx++;
	}

	return (uint32_t*)_pwmData;
}
