#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_USE_NO_WARNINGS
#pragma once
#include"stdio.h";
#include "stdint.h"
#include "Winsock2.h";
#include "Ws2tcpip.h"
#define max 30
#pragma comment(lib,"ws2_32.lib") //Winsock Library
WSADATA wsa;
SOCKET s;
struct sockaddr_in server;

char* message;
typedef char* str;
void Socket_Init(char* ip_server, u_short port);
void Socket_Server_Init(u_short port);
int Socket_Send(char* data, uint16_t size);
int Socket_Recv(char* src, uint16_t size); 
void Get_Data_AWS(char* data, int size);
void Put_Data_AWS(char* content);
int stringfind(str strsrc, str strfind);
int status(str strsrc, str strfind,char arr[],char key);
int stringLen(char* string);
int atoint(int* string);
void Get_Img_AWS(char*imgName);
int Get_Content_Length(char* name);