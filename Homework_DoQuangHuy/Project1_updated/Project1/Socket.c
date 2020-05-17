#include "Socket.h"
#include "stdio.h"

void Socket_Init(char* ip_server, u_short port)
{
	printf("Initialising Winsock...\r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d\r\n", WSAGetLastError());
		return 1;
	}

	printf(" Initialised.\r\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d\r\n", WSAGetLastError());
	}

	printf(" Socket created.\r\n");

	server.sin_addr.s_addr = inet_addr(ip_server);

	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(s, (struct sockaddr*) & server, sizeof(server)), 0)
	{
		printf("connect error\r\n");
		return 1;
	}

	printf("Connected\r\n");
}

void Socket_Server_Init(u_short port)
{
	printf("Initialising Winsock... \r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : % d \r\n", WSAGetLastError());
		return 1;
	}

	printf(" Initialised.\r\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : % d", WSAGetLastError());
	}

	printf(" Socket created.\r\n");

	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	bind(s, (struct sockaddr*) & server, sizeof(struct sockaddr));

	listen(s, 5);

	struct sockaddr_in dest;
	socklen_t socksize = sizeof(struct sockaddr_in);
	int consocket = accept(s, (struct sockaddr*) & dest, &socksize);
	char* msg = "Hello World !\r\n";
	while (consocket)
	{
		printf("Incoming connection from %s - sending welcome\r\n", inet_ntoa(dest.sin_addr));
		send(consocket, msg, strlen(msg), 0);
		close(consocket);
		consocket = accept(s, (struct sockaddr*) & dest, &socksize);
	}
}

int Socket_Send(char* data, uint16_t size)
{
	return send(s, data, size, 0);
}

int Socket_Recv(char* src, uint16_t size)
{
	return recv(s, src, size, 0);
}

void Get_Data_AWS(char* data, int size)
{
	char* data_send = "GET /helloWorld.txt HTTP/1.1\r\nHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\n\r\n";
	memset(data, 0, size);
	Socket_Init("52.219.128.223", 80);
	Socket_Send(data_send, stringLen(data_send));
	Socket_Recv(data, size);
	printf("%s", data);
}

int stringLen(char* string)
{
	int len = 0;
	while (string[len++] != 0);
	return len - 1;
}

typedef char* string;

int strngFind(string stringSrc, string stringFind)
{
	int i = 0;
	for (i = 0; i < stringLen(stringSrc) - stringLen(stringFind); i++)
	{
		int j = 0;
		for (j = 0; j < stringLen(stringFind); j++)
		{
			if (stringFind[j] != stringSrc[i + j])break;
		}
		if (j == stringLen(stringFind))break;
	}
	if (i == stringLen(stringSrc) - stringLen(stringFind))return -1;
	return i;
}

char status(int index, char* buff, int strlen)
{
	int i = index + strlen;
	/*printf("%c", buff[i]);*/
	while (buff[i] != '\n')
	{
		printf("%c", buff[i]);
		i++;
	}
	return 0;
}