#include "ServerSocket.h"

#pragma warning(disable:4996)


int ServerSocket::ServerThread()
{
	cout << "Starting up TCP server\r\n";

	WSADATA wsaData;

	sockaddr_in local;

	int wsaret = WSAStartup(0x101, &wsaData);

	if (wsaret != 0)
	{
		return 0;
	}

	//Now we populate the sockaddr_in structure
	local.sin_family = AF_INET; //Address family
	local.sin_addr.s_addr = INADDR_ANY; //Wild card IP address
	local.sin_port = htons((u_short)20248); //port to use

	//the socket function creates our SOCKET
	server = socket(AF_INET, SOCK_STREAM, 0);

	//If the socket() function fails we exit
	if (server == INVALID_SOCKET)
	{
		return 0;
	}

	if (bind(server, (sockaddr*)&local, sizeof(local)) != 0)
	{
		return 0;
	}

	if (listen(server, 10) != 0)
	{
		return 0;
	}

	return 0;
}

UINT ServerSocket::acceptClient() {
	//we will need variables to hold the client socket.
	//thus we declare them here.
	SOCKET client;
	sockaddr_in from;
	int fromlen = sizeof(from);
	client = accept(server, (struct sockaddr*) & from, &fromlen);
	cout << "ACCEPTED" << endl;

	char temp[512];
	recv(client, temp, strlen(temp), 0);
	cout << "Message recieved: " << temp << endl;
	closesocket(client);

	closesocket(server);

	//originally this function probably had some use
	//currently this is just for backward compatibility
	//but it is safer to call it as I still believe some
	//implementations use this to terminate use of WS2_32.DLL 
	WSACleanup();

	return 0;
}

