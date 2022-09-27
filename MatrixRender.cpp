#include <iostream>
#include "MatrixRender.h"

using namespace std;

void MatrixRender::_SetRGB(int r, int g, int b)
{
    throw gcnew System::NotImplementedException();
}

MatrixRender::MatrixRender(String ^port)
{
    InterfacePort.SetPortName(port);
    // Parámetros del hardware
    InterfacePort.SetPortBaudRate(115200);
    InterfacePort.SetPortParity(Parity::None);
    InterfacePort.SetPortDataBits(8);
    InterfacePort.SetPortStopBits(StopBits::One);
    InterfacePort.SetPortHandshake(Handshake::None);
    buffer = new unsigned char[1024];
    buf_response = new unsigned char[100];
}

bool MatrixRender::Inicializar()
{
    if (!InterfacePort.OpenPort()) {
        return false;
    }
    else {
        return true;
    }
}

void MatrixRender::_FrameToSerial(Frame *frm) {
    int r, g, b, y;
    memset(buffer, 0, 1024);
    checksum = 0;

    for (int i = 0; i < frm->GetRows(); i++) {
        for (int j = 0; j < frm->GetCols(); j++) {
            frm->pixel(i, j).GetRGB(&r, &g, &b);
            y = (int)((frm->pixel(i, j).GetBrillo()) * 100.0);
            buffer[(((i * 16) + j) * 4) + 0] = (unsigned char)r;
            buffer[(((i * 16) + j) * 4) + 1] = (unsigned char)g;
            buffer[(((i * 16) + j) * 4) + 2] = (unsigned char)b;
            buffer[(((i * 16) + j) * 4) + 3] = (unsigned char)y;
            checksum = checksum ^ (unsigned char)r ^ (unsigned char)g ^ (unsigned char)b ^ (unsigned char)y;
        }
    }
}

bool MatrixRender::SendFrame(Frame *frm)
{
    InterfacePort.Write((unsigned char*)"!", 1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(9));
    if (InterfacePort.Read() == '#') {
        cout << "Handshake recibido!" << endl;
        cout << "Size: " << sizeof(buffer) << endl;
        _FrameToSerial(frm);
        InterfacePort.Write(buffer, 1024);
        while (InterfacePort.Available() < 4);
        InterfacePort.ReadChars(buf_response, 4);
        if (buf_response[0] == '$' &&
            buf_response[1] == '=' &&
            buf_response[2] == '$')
        {
            cout << "Verificando Checksum . . ." << endl;
            if (buf_response[3] == checksum)
            {
                cout << "Checksum OK" << endl;
                InterfacePort.Write((unsigned char*)"!", 1);
                return true;
            }
            else
            {
                cout << "Checksum BAD " << (int)buf_response[3] << ", " << (int)checksum << endl;
                InterfacePort.Write((unsigned char*)"-", 1);
                return false;
            }
        }
        else
        {
            cout << "Info NO OK" << endl;
            return false;
        }
    }
    else
    {
        cout << "No recibi Handshake!";
        return false;
    }
}
