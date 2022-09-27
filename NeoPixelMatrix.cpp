// NeoPixelMatrix.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "ConRender.h"
#include "Frame.h"
#include "Serial.hpp"

using System::Console;
using namespace std;

unsigned char buffer[1024];
unsigned char checksum = 0;

void DrawMario(Frame *frm) {
    frm->pixel(0, 0).SetRGB(255, 255, 255);
    frm->pixel(0, 1).SetRGB(255, 255, 255);
    frm->pixel(0, 2).SetRGB(255, 255, 255);
    frm->pixel(0, 3).SetRGB(255, 255, 255);
    frm->pixel(0, 4).SetRGB(255, 255, 255);
    frm->pixel(0, 5).SetRGB(237, 27, 36);
    frm->pixel(0, 6).SetRGB(237, 27, 36);
    frm->pixel(0, 7).SetRGB(237, 27, 36);
    frm->pixel(0, 8).SetRGB(237, 27, 36);
    frm->pixel(0, 9).SetRGB(237, 27, 36);
    frm->pixel(0, 10).SetRGB(255, 255, 255);
    frm->pixel(0, 11).SetRGB(255, 255, 255);
    frm->pixel(0, 12).SetRGB(255, 255, 255);
    frm->pixel(0, 13).SetRGB(255, 255, 255);
    frm->pixel(0, 14).SetRGB(255, 255, 255);
    frm->pixel(0, 15).SetRGB(255, 255, 255);

    frm->pixel(1, 0).SetRGB(255, 255, 255);
    frm->pixel(1, 1).SetRGB(255, 255, 255);
    frm->pixel(1, 2).SetRGB(255, 255, 255);
    frm->pixel(1, 3).SetRGB(255, 255, 255);
    frm->pixel(1, 4).SetRGB(237, 27, 36);
    frm->pixel(1, 5).SetRGB(237, 27, 36);
    frm->pixel(1, 6).SetRGB(237, 27, 36);
    frm->pixel(1, 7).SetRGB(237, 27, 36);
    frm->pixel(1, 8).SetRGB(237, 27, 36);
    frm->pixel(1, 9).SetRGB(237, 27, 36);
    frm->pixel(1, 10).SetRGB(237, 27, 36);
    frm->pixel(1, 11).SetRGB(237, 27, 36);
    frm->pixel(1, 12).SetRGB(237, 27, 36);
    frm->pixel(1, 13).SetRGB(255, 255, 255);
    frm->pixel(1, 14).SetRGB(255, 255, 255);
    frm->pixel(1, 15).SetRGB(255, 255, 255);

    frm->pixel(2, 0).SetRGB(255, 255, 255);
    frm->pixel(2, 1).SetRGB(255, 255, 255);
    frm->pixel(2, 2).SetRGB(255, 255, 255);
    frm->pixel(2, 3).SetRGB(255, 255, 255);
    frm->pixel(2, 4).SetRGB(69, 35, 0);
    frm->pixel(2, 5).SetRGB(69, 35, 0);
    frm->pixel(2, 6).SetRGB(69, 35, 0);
    frm->pixel(2, 7).SetRGB(255, 194, 15);
    frm->pixel(2, 8).SetRGB(255, 194, 15);
    frm->pixel(2, 9).SetRGB(10, 10, 10);
    frm->pixel(2, 10).SetRGB(255, 194, 15);
    frm->pixel(2, 11).SetRGB(255, 255, 255);
    frm->pixel(2, 12).SetRGB(255, 255, 255);
    frm->pixel(2, 13).SetRGB(255, 255, 255);
    frm->pixel(2, 14).SetRGB(255, 255, 255);
    frm->pixel(2, 15).SetRGB(255, 255, 255);

    frm->pixel(3, 0).SetRGB(255, 255, 255);
    frm->pixel(3, 1).SetRGB(255, 255, 255);
    frm->pixel(3, 2).SetRGB(255, 255, 255);
    frm->pixel(3, 3).SetRGB(69, 35, 0);
    frm->pixel(3, 4).SetRGB(255, 194, 15);
    frm->pixel(3, 5).SetRGB(69, 35, 0);
    frm->pixel(3, 6).SetRGB(255, 194, 15);
    frm->pixel(3, 7).SetRGB(255, 194, 15);
    frm->pixel(3, 8).SetRGB(255, 194, 15);
    frm->pixel(3, 9).SetRGB(10, 10, 10);
    frm->pixel(3, 10).SetRGB(255, 194, 15);
    frm->pixel(3, 11).SetRGB(255, 194, 15);
    frm->pixel(3, 12).SetRGB(255, 194, 15);
    frm->pixel(3, 13).SetRGB(255, 255, 255);
    frm->pixel(3, 14).SetRGB(255, 255, 255);
    frm->pixel(3, 15).SetRGB(255, 255, 255);

    frm->pixel(4, 0).SetRGB(255, 255, 255);
    frm->pixel(4, 1).SetRGB(255, 255, 255);
    frm->pixel(4, 2).SetRGB(255, 255, 255);
    frm->pixel(4, 3).SetRGB(69, 35, 0);
    frm->pixel(4, 4).SetRGB(255, 194, 15);
    frm->pixel(4, 5).SetRGB(69, 35, 0);
    frm->pixel(4, 6).SetRGB(69, 35, 0);
    frm->pixel(4, 7).SetRGB(255, 194, 15);
    frm->pixel(4, 8).SetRGB(255, 194, 15);
    frm->pixel(4, 9).SetRGB(255, 194, 15);
    frm->pixel(4, 10).SetRGB(10, 10, 10);
    frm->pixel(4, 11).SetRGB(255, 194, 15);
    frm->pixel(4, 12).SetRGB(255, 194, 15);
    frm->pixel(4, 13).SetRGB(255, 194, 15);
    frm->pixel(4, 14).SetRGB(255, 255, 255);
    frm->pixel(4, 15).SetRGB(255, 255, 255);

    frm->pixel(5, 0).SetRGB(255, 255, 255);
    frm->pixel(5, 1).SetRGB(255, 255, 255);
    frm->pixel(5, 2).SetRGB(255, 255, 255);
    frm->pixel(5, 3).SetRGB(255, 255, 255);
    frm->pixel(5, 4).SetRGB(69, 35, 0);
    frm->pixel(5, 5).SetRGB(255, 194, 15);
    frm->pixel(5, 6).SetRGB(255, 194, 15);
    frm->pixel(5, 7).SetRGB(255, 194, 15);
    frm->pixel(5, 8).SetRGB(255, 194, 15);
    frm->pixel(5, 9).SetRGB(10, 10, 10);
    frm->pixel(5, 10).SetRGB(10, 10, 10);
    frm->pixel(5, 11).SetRGB(10, 10, 10);
    frm->pixel(5, 12).SetRGB(10, 10, 10);
    frm->pixel(5, 13).SetRGB(255, 255, 255);
    frm->pixel(5, 14).SetRGB(255, 255, 255);
    frm->pixel(5, 15).SetRGB(255, 255, 255);

    frm->pixel(6, 0).SetRGB(255, 255, 255);
    frm->pixel(6, 1).SetRGB(255, 255, 255);
    frm->pixel(6, 2).SetRGB(255, 255, 255);
    frm->pixel(6, 3).SetRGB(255, 255, 255);
    frm->pixel(6, 4).SetRGB(255, 255, 255);
    frm->pixel(6, 5).SetRGB(255, 194, 15);
    frm->pixel(6, 6).SetRGB(255, 194, 15);
    frm->pixel(6, 7).SetRGB(255, 194, 15);
    frm->pixel(6, 8).SetRGB(255, 194, 15);
    frm->pixel(6, 9).SetRGB(255, 194, 15);
    frm->pixel(6, 10).SetRGB(255, 194, 15);
    frm->pixel(6, 11).SetRGB(255, 255, 255);
    frm->pixel(6, 12).SetRGB(255, 255, 255);
    frm->pixel(6, 13).SetRGB(255, 255, 255);
    frm->pixel(6, 14).SetRGB(255, 255, 255);
    frm->pixel(6, 15).SetRGB(255, 255, 255);

    frm->pixel(7, 0).SetRGB(255, 255, 255);
    frm->pixel(7, 1).SetRGB(255, 255, 255);
    frm->pixel(7, 2).SetRGB(255, 255, 255);
    frm->pixel(7, 3).SetRGB(255, 255, 255);
    frm->pixel(7, 4).SetRGB(237, 27, 36);
    frm->pixel(7, 5).SetRGB(237, 27, 36);
    frm->pixel(7, 6).SetRGB(0, 0, 254);
    frm->pixel(7, 7).SetRGB(237, 27, 36);
    frm->pixel(7, 8).SetRGB(237, 27, 36);
    frm->pixel(7, 9).SetRGB(0, 0, 254);
    frm->pixel(7, 10).SetRGB(237, 27, 36);
    frm->pixel(7, 11).SetRGB(237, 27, 36);
    frm->pixel(7, 12).SetRGB(255, 255, 255);
    frm->pixel(7, 13).SetRGB(255, 255, 255);
    frm->pixel(7, 14).SetRGB(255, 255, 255);
    frm->pixel(7, 15).SetRGB(255, 255, 255);

    frm->pixel(8, 0).SetRGB(255, 255, 255);
    frm->pixel(8, 1).SetRGB(255, 255, 255);
    frm->pixel(8, 2).SetRGB(255, 255, 255);
    frm->pixel(8, 3).SetRGB(255, 255, 255);
    frm->pixel(8, 4).SetRGB(237, 27, 36);
    frm->pixel(8, 5).SetRGB(237, 27, 36);
    frm->pixel(8, 6).SetRGB(237, 27, 36);
    frm->pixel(8, 7).SetRGB(0, 0, 254);
    frm->pixel(8, 8).SetRGB(237, 27, 36);
    frm->pixel(8, 9).SetRGB(237, 27, 36);
    frm->pixel(8, 10).SetRGB(0, 0, 254);
    frm->pixel(8, 11).SetRGB(237, 27, 36);
    frm->pixel(8, 12).SetRGB(237, 27, 36);
    frm->pixel(8, 13).SetRGB(237, 27, 36);
    frm->pixel(8, 14).SetRGB(255, 255, 255);
    frm->pixel(8, 15).SetRGB(255, 255, 255);

    frm->pixel(9, 0).SetRGB(255, 255, 255);
    frm->pixel(9, 1).SetRGB(255, 255, 255);
    frm->pixel(9, 2).SetRGB(237, 27, 36);
    frm->pixel(9, 3).SetRGB(237, 27, 36);
    frm->pixel(9, 4).SetRGB(237, 27, 36);
    frm->pixel(9, 5).SetRGB(237, 27, 36);
    frm->pixel(9, 6).SetRGB(0, 0, 254);
    frm->pixel(9, 7).SetRGB(0, 0, 254);
    frm->pixel(9, 8).SetRGB(0, 0, 254);
    frm->pixel(9, 9).SetRGB(0, 0, 254);
    frm->pixel(9, 10).SetRGB(237, 27, 36);
    frm->pixel(9, 11).SetRGB(237, 27, 36);
    frm->pixel(9, 12).SetRGB(237, 27, 36);
    frm->pixel(9, 13).SetRGB(237, 27, 36);
    frm->pixel(9, 14).SetRGB(255, 255, 255);
    frm->pixel(9, 15).SetRGB(255, 255, 255);

    frm->pixel(10, 0).SetRGB(255, 255, 255);
    frm->pixel(10, 1).SetRGB(255, 255, 255);
    frm->pixel(10, 2).SetRGB(255, 194, 15);
    frm->pixel(10, 3).SetRGB(255, 194, 15);
    frm->pixel(10, 4).SetRGB(237, 27, 36);
    frm->pixel(10, 5).SetRGB(0, 0, 254);
    frm->pixel(10, 6).SetRGB(254, 242, 0);
    frm->pixel(10, 7).SetRGB(0, 0, 254);
    frm->pixel(10, 8).SetRGB(0, 0, 254);
    frm->pixel(10, 9).SetRGB(254, 242, 0);
    frm->pixel(10, 10).SetRGB(0, 0, 254);
    frm->pixel(10, 11).SetRGB(237, 27, 36);
    frm->pixel(10, 12).SetRGB(255, 194, 15);
    frm->pixel(10, 13).SetRGB(255, 194, 15);
    frm->pixel(10, 14).SetRGB(255, 255, 255);
    frm->pixel(10, 15).SetRGB(255, 255, 255);

    frm->pixel(11, 0).SetRGB(255, 255, 255);
    frm->pixel(11, 1).SetRGB(255, 255, 255);
    frm->pixel(11, 2).SetRGB(255, 194, 15);
    frm->pixel(11, 3).SetRGB(255, 194, 15);
    frm->pixel(11, 4).SetRGB(255, 194, 15);
    frm->pixel(11, 5).SetRGB(0, 0, 254);
    frm->pixel(11, 6).SetRGB(0, 0, 254);
    frm->pixel(11, 7).SetRGB(0, 0, 254);
    frm->pixel(11, 8).SetRGB(0, 0, 254);
    frm->pixel(11, 9).SetRGB(0, 0, 254);
    frm->pixel(11, 10).SetRGB(0, 0, 254);
    frm->pixel(11, 11).SetRGB(255, 194, 15);
    frm->pixel(11, 12).SetRGB(255, 194, 15);
    frm->pixel(11, 13).SetRGB(255, 194, 15);
    frm->pixel(11, 14).SetRGB(255, 255, 255);
    frm->pixel(11, 15).SetRGB(255, 255, 255);

    frm->pixel(12, 0).SetRGB(255, 255, 255);
    frm->pixel(12, 1).SetRGB(255, 255, 255);
    frm->pixel(12, 2).SetRGB(255, 194, 15);
    frm->pixel(12, 3).SetRGB(255, 194, 15);
    frm->pixel(12, 4).SetRGB(0, 0, 254);
    frm->pixel(12, 5).SetRGB(0, 0, 254);
    frm->pixel(12, 6).SetRGB(0, 0, 254);
    frm->pixel(12, 7).SetRGB(0, 0, 254);
    frm->pixel(12, 8).SetRGB(0, 0, 254);
    frm->pixel(12, 9).SetRGB(0, 0, 254);
    frm->pixel(12, 10).SetRGB(0, 0, 254);
    frm->pixel(12, 11).SetRGB(0, 0, 254);
    frm->pixel(12, 12).SetRGB(255, 194, 15);
    frm->pixel(12, 13).SetRGB(255, 194, 15);
    frm->pixel(12, 14).SetRGB(255, 255, 255);
    frm->pixel(12, 15).SetRGB(255, 255, 255);

    frm->pixel(13, 0).SetRGB(255, 255, 255);
    frm->pixel(13, 1).SetRGB(255, 255, 255);
    frm->pixel(13, 2).SetRGB(255, 255, 255);
    frm->pixel(13, 3).SetRGB(255, 255, 255);
    frm->pixel(13, 4).SetRGB(0, 0, 254);
    frm->pixel(13, 5).SetRGB(0, 0, 254);
    frm->pixel(13, 6).SetRGB(0, 0, 254);
    frm->pixel(13, 7).SetRGB(255, 255, 255);
    frm->pixel(13, 8).SetRGB(255, 255, 255);
    frm->pixel(13, 9).SetRGB(0, 0, 254);
    frm->pixel(13, 10).SetRGB(0, 0, 254);
    frm->pixel(13, 11).SetRGB(0, 0, 254);
    frm->pixel(13, 12).SetRGB(255, 255, 255);
    frm->pixel(13, 13).SetRGB(255, 255, 255);
    frm->pixel(13, 14).SetRGB(255, 255, 255);
    frm->pixel(13, 15).SetRGB(255, 255, 255);

    frm->pixel(14, 0).SetRGB(255, 255, 255);
    frm->pixel(14, 1).SetRGB(255, 255, 255);
    frm->pixel(14, 2).SetRGB(255, 255, 255);
    frm->pixel(14, 3).SetRGB(69, 35, 0);
    frm->pixel(14, 4).SetRGB(69, 35, 0);
    frm->pixel(14, 5).SetRGB(69, 35, 0);
    frm->pixel(14, 6).SetRGB(255, 255, 255);
    frm->pixel(14, 7).SetRGB(255, 255, 255);
    frm->pixel(14, 8).SetRGB(255, 255, 255);
    frm->pixel(14, 9).SetRGB(255, 255, 255);
    frm->pixel(14, 10).SetRGB(69, 35, 0);
    frm->pixel(14, 11).SetRGB(69, 35, 0);
    frm->pixel(14, 12).SetRGB(69, 35, 0);
    frm->pixel(14, 13).SetRGB(255, 255, 255);
    frm->pixel(14, 14).SetRGB(255, 255, 255);
    frm->pixel(14, 15).SetRGB(255, 255, 255);

    frm->pixel(15, 0).SetRGB(255, 255, 255);
    frm->pixel(15, 1).SetRGB(255, 255, 255);
    frm->pixel(15, 2).SetRGB(69, 35, 0);
    frm->pixel(15, 3).SetRGB(69, 35, 0);
    frm->pixel(15, 4).SetRGB(69, 35, 0);
    frm->pixel(15, 5).SetRGB(69, 35, 0);
    frm->pixel(15, 6).SetRGB(255, 255, 255);
    frm->pixel(15, 7).SetRGB(255, 255, 255);
    frm->pixel(15, 8).SetRGB(255, 255, 255);
    frm->pixel(15, 9).SetRGB(255, 255, 255);
    frm->pixel(15, 10).SetRGB(69, 35, 0);
    frm->pixel(15, 11).SetRGB(69, 35, 0);
    frm->pixel(15, 12).SetRGB(69, 35, 0);
    frm->pixel(15, 13).SetRGB(69, 35, 0);
    frm->pixel(15, 14).SetRGB(255, 255, 255);
    frm->pixel(15, 15).SetRGB(255, 255, 255);
}

void Delay(int x) {std::this_thread::sleep_for(std::chrono::milliseconds(x));}

void FrameToSerial(Frame *frm) {
    int r, g, b, y;
    memset(buffer, 0, 1024);
    checksum = 0;

    for (int i = 0; i < frm->GetRows(); i++) {
        for (int j = 0; j < frm->GetCols(); j++) {
            frm->pixel(i, j).GetRGB(&r, &g, &b);
            y = (int)((frm->pixel(i, j).GetBrillo()) * 100.0);
            buffer[(((i*16) + j) * 4) + 0] = (unsigned char)r;
            buffer[(((i*16) + j) * 4) + 1] = (unsigned char)g;
            buffer[(((i*16) + j) * 4) + 2] = (unsigned char)b;
            buffer[(((i*16) + j) * 4) + 3] = (unsigned char)y;
            checksum = checksum ^ (unsigned char)r ^ (unsigned char)g ^ (unsigned char)b ^ (unsigned char)y;
        }
    }
}

int PrintMenu() {
    // Configura la consola para mostrar acentos
    char opt = 0;
    cout << endl
        << "Matriz de NeoPixel v1.0" << endl
        << "==================================================" << endl
        << endl
        << "\t1) Dibujar a Mario Bros " << endl
        << "\t2) Rellenar matriz completa con color" << endl
        << "\t3) Apagar matriz" << endl
        << "\t4) Salir" << endl
        << endl;
        cout << "Ingrese el n\xA3mero de la opci\xA2n deseada y presione enter: ";
        cin.get(opt);
    cout << opt << endl;
    return opt;
}

int main()
{
    // Crea una instancia de la clase Serial
    Serial a;

    cout << "Conectando con el Hardware . . ." << endl;
    // Establece los parámetros de la comunicación
    a.SetPortName("COM4");
    a.SetPortBaudRate(115200);
    a.SetPortParity(Parity::None);
    a.SetPortDataBits(8);
    a.SetPortStopBits(StopBits::One);
    a.SetPortHandshake(Handshake::None);

    //Abre el puerto
    if (!a.OpenPort()) {
        cout << "Error al conectar con el hardware" << endl;
        cout << "Saliendo . . ." << endl;
        system("pause");
        exit(0);
    }
    Delay(250);
    cout << endl << "Conectado!" << endl;
    Delay(700);

    ConRender render;
    Frame frm(16,16);

    int r, g, b;
    double y;
    unsigned char buf_response[100];
    render.ShowFrame(&frm);

    char opt = 0;
    while ((opt = PrintMenu()) != 0x34)
    {
        switch (opt)
        {
        case 0x31:
            DrawMario(&frm);
            a.Write((unsigned char *)"!",1);
            //std::this_thread::sleep_for(std::chrono::milliseconds(9));
            if (a.Read() == '#') {
                cout << "Handshake recibido!" << endl;
                cout << "Size: " << sizeof(buffer) << endl;
                FrameToSerial(&frm);
                a.Write(buffer,1024);
                while (a.Available() < 4);
                a.ReadChars(buf_response, 4);
                if ( buf_response[0] == '$' && 
                     buf_response[1] == '=' &&
                     buf_response[2] == '$')
                {
                    cout << "Verificando Checksum . . ." << endl;
                    if (buf_response[3] == checksum)
                    {
                        cout << "Checksum OK" << endl;
                        a.Write((unsigned char*)"!", 1);
                    }
                    else
                    {
                        cout << "Checksum BAD " << (int)buf_response[3] << ", " << (int)checksum << endl;
                        a.Write((unsigned char*)"-", 1);
                    }
                }
                else
                {
                    cout << "Info NO OK" << endl;
                }
            }
            else
            {
                cout << "No recibi Handshake!";
            }
            system("pause");
            break;
        case 0x32:
            cout << "Ingrese el valor para rojo (0-255): ";
            cin >> r;
            cout << "Ingrese el valor para verde (0-255): ";
            cin >> g;
            cout << "Ingrese el valor para azul (0-255): ";
            cin >> b;
            frm.SetColorFrame(r, g, b);
            cout << "Ingrese el valor para el brillo(0.0-1.0: ";
            cin >> y;
            frm.SetGlobalBrigthness(y);
            FrameToSerial(&frm);
            cout << buffer;
            system("pause");
            //a.Write(FrameToSerial(&frm));
            break;
        case 0x33:
            frm.ClearFrame();
            break;
        default:
            cout << endl << "Opci\xA2n no valida" << endl;
            system("pause");
            break;
        }
        cout << endl << endl;
        cin.clear();
        system("cls");
        render.ShowFrame(&frm);
    }
}