#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <WinSock2.h>

using namespace std;

class ServerSocket {
public:
	static ServerSocket& getInstance()
	{
		static ServerSocket    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

	int ServerThread();
	UINT acceptClient();

private:
	ServerSocket() {}
	ServerSocket(ServerSocket const&) = delete;
	void operator=(ServerSocket const&) = delete;

	SOCKET server;
};

#endif