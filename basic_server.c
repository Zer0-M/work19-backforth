#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  printf("recreating well known-pipe\n");
  while(1){
    char data[BUFFER_SIZE];
    int bytesr=read(from_client,data,BUFFER_SIZE);
    printf("%d\n",bytesr);
    printf("The client says %s",data);
    char response[strlen(data)];
    /*for(int i=0;i<bytesr;i++){
      if((int)data[i]+13>26){
	response[i]=(char)((int)(data[i])-26+13);
      }
      else{
	response[i]=(char)((int)(data[i])+13);
      }
    }*/
    strcpy(response,data);
    write(to_client,response,strlen(response));
  }
}
