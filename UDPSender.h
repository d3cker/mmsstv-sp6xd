#ifndef UDPSenderH
#define UDPSenderH

#include <winsock2.h>
#include <ws2tcpip.h>
#include <System.hpp>

#pragma comment(lib, "ws2_32.lib")

class UDPSender {
private:
    SOCKET udpSocket;
    bool initialized;

public:
    __fastcall UDPSender();
    __fastcall ~UDPSender();

    bool __fastcall SendPacket(const char* ipAddress, int port, const char* data, int dataLength);
    bool __fastcall IsInitialized() { return initialized; }
};

#endif
