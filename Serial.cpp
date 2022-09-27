#include "Serial.hpp"

Serial::Serial()
{
    _serialPort = gcnew SerialPort();
    _continue = false;
    _serialPort->ReadTimeout = 10000;
    //_serialPort->WriteTimeout = 500;
}
Serial::~Serial() {
    _serialPort->Close();
}
bool Serial::OpenPort() {
    try {
        _serialPort->Open();
        _continue = true;
        return true;
    }
    catch(Exception^ e){
        return false;

    }
    
}
void Serial::Write(unsigned char *input, int len) {
    if (_continue)
    {
        array<Byte>^ result = gcnew array<Byte>(len);
        for (int i = 0; i < len; i++)
        {
            result[i] = input[i];
        }
        _serialPort->Write(result, 0 , len);
        delete result;
    }
}

void Serial::WriteBytes(array<unsigned char>^ bytes) {
    if (_continue)
    {
        _serialPort->Write(bytes, 0, bytes->Length);
    }
}

void Serial::WriteLine(String^ text)
{
    if (_continue)
    {
        _serialPort->WriteLine(text);
    }
}

String^ Serial::ReadLine()
{
    if (_continue)
    {
        try
        {
            String^ message = _serialPort->ReadLine();
            //Console::WriteLine(message);
            return message;
        }
        catch (TimeoutException^) {}
    }
}

int Serial::Available() { return _serialPort->BytesToRead; }

void Serial::ReadChars(unsigned char* buf, int len)
{
    if (_continue)
    {
        try
        {
            //array<wchar_t>^ result = gcnew array<wchar_t>(len);
            //_serialPort->Read(result, 0, len);
            for (int i = 0; i < len; i++)
            {
                //buf[i] = result[i];
                buf[i] = (unsigned char)_serialPort->ReadByte();
            }
        }
        catch (TimeoutException^) {}
    }
}

char Serial::Read()
{
    if (_continue)
    {
        try
        {
            int ch = _serialPort->ReadChar();
            //Console::WriteLine(ch);
            return (char)ch;
        }
        catch (TimeoutException^) {}
    }
}

void Serial::SetPortName(String^ portName)
{
    _serialPort->PortName = portName;
}

void Serial::SetPortBaudRate(Int32 defaultPortBaudRate)
{
    _serialPort->BaudRate = defaultPortBaudRate;
}

void Serial::SetPortParity(Parity defaultPortParity)
{
    _serialPort->Parity = defaultPortParity;
}

void Serial::SetPortDataBits(Int32 defaultPortDataBits)
{
    _serialPort->DataBits = defaultPortDataBits;
}

void Serial::SetPortStopBits(StopBits defaultPortStopBits)
{
    _serialPort->StopBits = defaultPortStopBits;
}

void Serial::SetPortHandshake(Handshake defaultPortHandshake)
{
    _serialPort->Handshake = defaultPortHandshake;
}