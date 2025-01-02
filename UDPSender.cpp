#include "UDPSender.h"
#pragma hdrstop

#include <Vcl.Dialogs.hpp>

__fastcall UDPSender::UDPSender() {
    initialized = false;

    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        ShowMessage("Failed to initialize Winsock");
        return;
    }

    // Create UDP socket
    udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpSocket == INVALID_SOCKET) {
        ShowMessage("Failed to create socket");
        WSACleanup();
        return;
    }

    initialized = true;
}

__fastcall UDPSender::~UDPSender() {
    if (initialized) {
        closesocket(udpSocket);
        WSACleanup();
    }
}

bool __fastcall UDPSender::SendPacket(const char* ipAddress, int port, const char* data, int dataLength) {
    if (!initialized) {
        ShowMessage("UDP Sender not properly initialized");
        return false;
    }

    try {
        // Set up the address structure
        sockaddr_in receiverAddr;
        receiverAddr.sin_family = AF_INET;
        receiverAddr.sin_port = htons(port);

        // Convert IP address from string to binary form
        if (inet_pton(AF_INET, ipAddress, &receiverAddr.sin_addr) != 1) {
            ShowMessage("Invalid IP address format");
            return false;
        }

        // Send the data
        int bytesSent = sendto(udpSocket,
                              data,
                              dataLength,
                              0,
                              (struct sockaddr*)&receiverAddr,
                              sizeof(receiverAddr));

        if (bytesSent == SOCKET_ERROR) {
            ShowMessage("Failed to send data");
            return false;
        }

        return true;
    }
    catch (...) {
        ShowMessage("Error occurred while sending UDP packet");
        return false;
    }
}
