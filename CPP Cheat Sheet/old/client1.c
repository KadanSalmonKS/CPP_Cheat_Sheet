// A sample of client program

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
#define INVALID_SOCKET -1



    int main(int argc, char *argv[])

    {


    //if(argc < 3)
    //{
      //      printf("\nUsage: \"%s\" [ip address] [port]\n",argv[0]);
      //      return 0;
    //}


        // Create a socket.

        int m_socket;

        m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);



        if (m_socket == INVALID_SOCKET)

        {

            printf("Client: socket() - Error at socket()\n");


            return 0;

        }

        else

           printf("Client: socket() is OK.\n");



        // Connect to a server.

      struct  sockaddr_in clientService;



        clientService.sin_family = AF_INET;

        clientService.sin_addr.s_addr = inet_addr("127.0.0.1");//inet_addr(argv[1]);

        clientService.sin_port = htons(555);//htons(atoi(argv[2]));



        if (connect(m_socket, (struct sockaddr*)&clientService, sizeof(clientService)) == SOCKET_ERROR)

        {

            printf("Client: connect() - Failed to connect.\n");


            return 0;

        }
        printf("Client is  connected to %s on port %s.\n",argv[1],argv[2]);


        // Send and receive data.

        //int bytesSent;

        int i=0,bytesC,bytesRecv = SOCKET_ERROR;

        // Be careful with the array bound, provide some checking mechanism

        //char sendbuf[200] = "Client: Sending some test string to server...";

        char *recvbuf,filename[100]={0};
        unsigned long filelen;


        //bytesSent = send(m_socket, sendbuf, strlen(sendbuf), 0);

        //printf("Client: send() - Bytes Sent: %ld\n", bytesSent);
        recvbuf = (char *)malloc(sizeof(char)*50);
        memset(recvbuf,0,sizeof(recvbuf));
        int by = recv(m_socket, recvbuf, sizeof(recvbuf), 0);
        if(by == 0){
            printf("\n\nCould Not open file\n\n");
            close(m_socket);
            return 0;
        }
        strcpy(filename,recvbuf);
        printf("file name is %s\n",filename);
        free(recvbuf);


        recvbuf = (char *)malloc(sizeof(filelen)*2);
        memset(recvbuf,0,sizeof(recvbuf));
        recv(m_socket, recvbuf, sizeof(recvbuf), 0);
        filelen = atoi(recvbuf);
        int len_in_kb = filelen/1024;
        printf("file size is %d Kilo-bytes\n",len_in_kb);
        free(recvbuf);
//while(1)
//{
        recvbuf = (char *)malloc(filelen);
        memset(recvbuf,0,sizeof(recvbuf));
        bytesRecv = 0;

        printf("Downloading....\n\n",recvbuf);
        FILE *fp = fopen(filename,"wb");
        //fwrite(filename,sizeof(filename),1,fp);



        //printf("Bytes Downloaded : ");
        while(bytesRecv < filelen){
            bytesRecv += recv(m_socket,recvbuf, sizeof(recvbuf), 0);
            //printf("%s",recvbuf);
            //sprintf(recvbuf,"%s",recvbuf);
            fwrite(recvbuf,sizeof(recvbuf),1,fp);
            //fprintf(fp,recvbuf);


        }
        printf("Bytes Downloaded : %d Kb\n",len_in_kb);
        fclose(fp);
        close(m_socket);
        //printf("Data : %s",recvbuf);



            //memset(sendbuf,0,sizeof(sendbuf));

            //if(1)
            //{
                      // i=0;
                       //scanf("%c",&sendbuf[i]);

                      // while(sendbuf[i] != '\n'){
                       //          i++;
                       //          scanf("%c",&sendbuf[i]);
                       //          }
                       //          send(m_socket, sendbuf, strlen(sendbuf), 0);
                       //}











            //if (strcmp(recvbuf,".")==0)

           // {
                //close(m_socket);
                //printf("Client: Connection Closed.\n");

               // return 0;

            //}

           // else

             //   printf("Client: recv() is OK.\n");



            if (bytesRecv < 0)

                return 0;

            //else

              //  printf("Client: Bytes received - %ld.\n", bytesRecv);

        //}


        return 0;

    }
