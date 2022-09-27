#pragma once
#using <System.dll>

// PARA CONSTRUIR: HABILITAR COMPATIBILIDAD CON Common Language Runtime (/clr)

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;

ref class Serial
{
private:
    bool _continue;
    SerialPort^ _serialPort;

public:
    Serial();
    ~Serial();
    bool OpenPort();
    String^ ReadLine();
    char Read();
    void ReadChars(unsigned char *buf, int len);
    int Available();
    void WriteLine(String^ text);
    void WriteBytes(array<unsigned char>^ bytes);
    void Write(unsigned char *input, int len);
    void SetPortName(String^ portName);
    void SetPortBaudRate(Int32 defaultPortBaudRate);
    void SetPortParity(Parity defaultPortParity);
    void SetPortDataBits(Int32 defaultPortDataBits);
    void SetPortStopBits(StopBits defaultPortStopBits);
    void SetPortHandshake(Handshake defaultPortHandshake);
};