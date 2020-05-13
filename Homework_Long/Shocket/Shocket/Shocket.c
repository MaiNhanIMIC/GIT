#define _CRT_USE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "stdio.h"

void Socket_Init(char* ip_server, u_short port)
{
	printf("Initialising Winsock...\r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d\r\n", WSAGetLastError());
		return 1;
	}

	printf(" Initialized.\r\n");

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
	printf("Initializing Winsock... \r\n");
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
void Put_Data_AWS(char* content)
{
	//char* data_put = "PUT /helloWorld.txt HTTP/1.1\r\nContent-Length:%dHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\n\r\n%s";
	char data[1024];
	char temp[1024];
	memset(data, 0, 1024);
	memset(temp, 0, 1024);
	Socket_Init("52.219.128.223", 80);
	Socket_Send(data, 1024);
	Socket_Recv(temp, 1024);
	sprintf(data, "PUT /helloWorld.txt HTTP/1.1\r\nContent-Length: %d\r\nHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\n\r\n%s", stringLen(content), content);
	printf("%s", temp);
	printf("%s\r\n", data);
}

int stringfind(str strsrc, str strfind)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < stringLen(strsrc) - stringLen(strfind); i++)
	{
		for (j = 0; j < stringLen(strfind); j++)
		{
			if (strsrc[i + j] != strfind[j]) break;
		}
		if (j == stringLen(strfind)) break;
	}
	if (i == stringLen(strsrc) - stringLen(strfind)) return -1;
	return i + stringLen(strfind);
}

int state(str strsrc, str strfind, char arr[])
{
	int i = 0;
	int j = 0;
	int index = 0;
	for (i = stringfind(strsrc, strfind); strsrc[i] != ' '; i++)
	{
		arr[j++] = strsrc[i];
		index = j;
	}
	while (index < max)
	{
		arr[index] = 0;
		index++;
	}
	return 0;
	if (strsrc[i] == ' ') return -1;
}
int stringLen(char* string)
{
	int len = 0;
	while (string[len++] != 0);
	return len - 1;
}
