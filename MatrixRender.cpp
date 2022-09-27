#include "MatrixRender.h"

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

void MatrixRender::ShowFrame(Frame* frm)
{
    throw gcnew System::NotImplementedException();
}
