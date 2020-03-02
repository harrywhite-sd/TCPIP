#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <WinSock2.h>
using namespace std;

class ClientSocket {
public:
	static ClientSocket& getInstance()
	{
		static ClientSocket    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

	int ClientThread(const char* ipAddress, UINT16 portNumber);
	UINT sendMsg();

private:
	ClientSocket() {}
	ClientSocket(ClientSocket const&) = delete;
	void operator=(ClientSocket const&) = delete;

	SOCKET               SendingSocket;
	// Server/receiver address
	SOCKADDR_IN          ServerAddr, ThisSenderInfo;
};

#endif