#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#define SOCKET_ERROR -1

int main()

{
//////////Create a socket////////////////////////

//Create a SOCKET object called m_socket.

int m_socket;



// Call the socket function and return its value to the m_socket variable.

// For this application, use the Internet address family, streaming sockets, and the TCP/IP protocol.

// using AF_INET family, TCP socket type and protocol of the AF_INET - IPv4

m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);



// Check for errors to ensure that the socket is a valid socket.

if (m_socket < 0)

{

    printf("Server: Error at socket()\n");

    return 0;

}

else

{

    printf("Server: socket() is OK!\n");

}



////////////////bind//////////////////////////////

// Create a sockaddr_in object and set its values.

struct sockaddr_in service;



// AF_INET is the Internet address family.

service.sin_family = AF_INET;

// "127.0.0.1" is the local IP address to which the socket will be bound.


service.sin_addr.s_addr = inet_addr("0.0.0.0");//htonl(ANY);


// 55555 is the port number to which the socket will be bound.

// using the htons for big-endian

service.sin_port = htons(555);



// Call the bind function, passing the created socket and the sockaddr_in structure as parameters.

// Check for general errors.

if (bind(m_socket, (struct sockaddr*)&service, sizeof(service)) < 0)

{

    printf("Server: bind() failed\n");

    close(m_socket);

    return 0;

}

else

{

    printf("Server: bind() is OK!\n");

}



// Call the listen function, passing the created socket and the maximum number of allowed

// connections to accept as parameters. Check for general errors.

if (listen(m_socket, 2) < 0)
{
    printf("Server: listen(): Error listening on socket\n");
    return 0;
}

else

{

    printf("Server: listen() is OK, I'm waiting for connections...\n");

}



// Create a temporary SOCKET object called AcceptSocket for accepting connections.

//client details
int AcceptSocket;


// Create a continuous loop that checks for connections requests. If a connection

// request occurs, call the accept function to handle the request.

printf("Server: Waiting for a client to connect...\n");

printf("***Hint: Server is ready...run your client program...***\n");

// Do some verification...
int con_num = 0;
while (1)

{

    //AcceptSocket = SOCKET_ERROR;


      //while (AcceptSocket == SOCKET_ERROR)

       //{

        AcceptSocket = accept(m_socket, NULL, NULL);
        con_num ++;
        /*if(con_num >= 5){
            printf("Connections Have Exceeded Limit\n");
            close(AcceptSocket);
            close(m_socket);
            break;
        }*/
        printf("Server: Client Connected! ON \nAddress : %d and Port : %d\n",service.sin_addr.s_addr,ntohs(service.sin_port));
        //printf("here");
        //m_socket = AcceptSocket;
        //send file
        //char fil[]= "../client.c";
        char fil[]= "testfile.html";
        char file[100]={0};
        //char fil[100];
        //fil = (char *)malloc(sizeof(char)*50);
        printf("\n\nEnter the name of the file : ");
        //memset(fil,0,100);
       // fgets(fil,100,stdin);

        //scanf("%[^\n]s",fil);
        int i;
        for(i=0; i<strlen(fil);i++){
            if(fil[i] != '\n'){
                file[i] = fil[i];
            }
            else
                break;
        }
        printf("\nThe File name is : \"%s\"\n",file);

        char *msgbuf;//buffer to hold file content
        FILE *fp;
        fp = fopen(file,"rb");
        unsigned long filelen;
        int b_sent;

        if(fp ==  NULL){

            printf("could Not open File\n");
            return 0;
        }
        //find length
        fseek(fp,0,SEEK_END);//go to end of file
        filelen = ftell(fp);
        fseek(fp,0,SEEK_SET);//go back to the beginning of the file

        //msgbuf = (char *)malloc(sizeof(fil));
        //sprintf(msgbuf,"%s",fil);
        printf("Sending File Name : ");
        b_sent = send(AcceptSocket,fil,sizeof(fil),0);
        if(b_sent == 0){
            printf("error!!\nFile name was not sent!!\n");
            return 0;
        }
        else{
            printf("Sent\n",b_sent);
            //free(msgbuf);
        }


        printf("\nFile size : %d\n",filelen);

        msgbuf = (char *)malloc(sizeof(filelen)*3);
        memset(msgbuf,0,sizeof(msgbuf));
        sprintf(msgbuf,"%d",filelen);
        printf("Sending File size : ");
        b_sent = send(AcceptSocket,msgbuf,sizeof(msgbuf),0);
        if(b_sent == 0){
            printf("error!!\nFile size was not sent!!\n");
            return 0;
        }
        else{
            printf("Sent\n",b_sent);
            free(msgbuf);
        }

        msgbuf = (char *)malloc(filelen);
        memset(msgbuf,0,sizeof(msgbuf));
        //fread(msgbuf,filelen,1,fp);
        //fwrite(msgbuf,sizeof(msgbuf),1,fp);


        printf("Sending file : %s\n\n",fil);
        b_sent = 0;
        while(b_sent < filelen){
                fread(msgbuf,sizeof(msgbuf),1,fp);
            b_sent += send(AcceptSocket,msgbuf,sizeof(msgbuf),0);
        }


        if(b_sent <= 0){
            printf("File was not sent!!\n");
            return 0;
        }
        else{
            printf("%d bytes were sent\n",b_sent);
        }

        //if(1)
        //{
            //char res;

            /*if (kbhit())
               {
                    res = getchar();
                   if (res == 'e'){
                        close(AcceptSocket);
                        close(m_socket);
                        return 0;
                   }

               }*/

                   // printf("Connection Terminated !!");
                    printf("Client Connection Terminated !!\n");
                    close(AcceptSocket);
                    //close(m_socket);
                   // return 0;
               //}
       // }
       //}



   // else, accept the connection...

   // When the client connection has been accepted, transfer control from the

   // temporary socket to the original socket and stop checking for new connections.



}



return 0;

}
