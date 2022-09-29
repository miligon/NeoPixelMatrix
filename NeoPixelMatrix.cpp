// NeoPixelMatrix.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "ConRender.h"
#include "MatrixRender.h"
#include "Frame.h"
#include "Imagenes.h"

using System::Console;
using namespace std;


void Delay(int x) {std::this_thread::sleep_for(std::chrono::milliseconds(x));}

int PrintMenu() {
    // Configura la consola para mostrar acentos
    char opt = 0;
    cout << endl
        << "Matriz de NeoPixel v1.0" << endl
        << "==================================================" << endl
        << endl
        << "\t1) Dibujar a Mario" << endl
        << "\t2) Rellenar matriz completa con color" << endl
        << "\t3) Apagar matriz" << endl
        << "\t4) Cambiar brillo" << endl
        << "\t5) Voltear Horizontalmente" << endl
        << "\t6) Voltear Verticalmente" << endl
        << "\t7) Mostrar animaci\xA2n" << endl
        << "\t8) Salir" << endl
        << endl;
        cout << "Ingrese el n\xA3mero de la opci\xA2n deseada y presione enter: ";
        opt = _getch();
    cout << opt << endl;
    return opt;
}

//Envia una secuencia de frames al microcontrolador
void animacion(Frame* frm, MatrixRender^ matrix, ConRender *render) {
    system("cls");
    DrawMario(frm, 0.00);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    for (double brillo = 0.0; brillo <= 0.60; brillo += 0.2) {
        Delay(30);
        system("cls");
        frm->SetGlobalBrigthness(brillo);
        render->ShowFrame(frm);
        matrix->SendFrame(frm);
    }
    Delay(60);
    system("cls");
    DrawMario1(frm, 0.60);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    Delay(60);
    system("cls");
    DrawMario2(frm, 0.60);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    Delay(60);
    system("cls");
    DrawMario1(frm, 0.60);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    Delay(60);
    system("cls");
    DrawMario2(frm, 0.60);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    Delay(60);
    system("cls");
    DrawMario(frm, 0.60);
    render->ShowFrame(frm);
    matrix->SendFrame(frm);
    for (double brillo = 0.60; brillo >= 0.00; brillo -= 0.2) {
        Delay(30);
        system("cls");
        frm->SetGlobalBrigthness(brillo);
        render->ShowFrame(frm);
        matrix->SendFrame(frm);
    }
}

int main()
{
    // Objetos para visualizar imagen en consola y framebuffer
    ConRender render;
    Frame frm(16,16);
    frm.ClearFrame();

    int r, g, b;
    double y;
    
    cout << "Conectando con el Hardware . . ." << endl;
    MatrixRender matrix("COM4");

    if (!matrix.Inicializar()) {
        cout << "Error al conectar con el hardware" << endl;
        cout << "Saliendo . . ." << endl;
        system("pause");
        exit(0);
    }
    
    render.ShowFrame(&frm);
    matrix.SendFrame(&frm);

    Delay(250);
    cout << endl << "Conectado!" << endl;
    Delay(700);

    char opt = 0;
    while ((opt = PrintMenu()) != 0x38)
    {
        switch (opt)
        {
        case 0x31:
            DrawMario1(&frm, 0.8);
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
            break;
        case 0x33:
            frm.ClearFrame();
            break;
        case 0x34:
            cout << "Ingrese el valor para el brillo(0.0-1.0): ";
            cin >> y;
            frm.SetGlobalBrigthness(y);
            matrix.SendFrameBrillo(y);
            break;
        case 0x35:
            frm.FlipHorizontal();
            break;
        case 0x36:
            frm.FlipVertical();
            break;
        case 0x37:
            animacion(&frm, %matrix, &render);
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
        matrix.SendFrame(&frm);
    }
    frm.ClearFrame();
    matrix.SendFrame(&frm);
}