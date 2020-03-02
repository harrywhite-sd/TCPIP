#include "ClientSocket.h"
#include "ServerSocket.h"


DWORD WINAPI t1(LPVOID lpParam) {
	ServerSocket::getInstance().acceptClient();
	return 0;
}

DWORD WINAPI t2(LPVOID lpParam) {
	ClientSocket::getInstance().sendMsg();
	return 0;
}

int main(int argc, char** argv)

{
	ServerSocket::getInstance().ServerThread();
	ClientSocket::getInstance().ClientThread("127.0.0.1", 20248);
	
	DWORD threadID1, threadID2;
	HANDLE h1 = CreateThread(NULL, 0, t1, 0, 0, &threadID1);
	HANDLE h2 = CreateThread(NULL, 0, t2, 0, 0, &threadID2);

	WaitForSingleObject(h1, INFINITE);


	getchar();
}