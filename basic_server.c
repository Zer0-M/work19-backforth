#include "pipe_networking.h"

char * encryptstring(char * str){
  char *encrypted=malloc(sizeof(char));
  
  if(strlen(str)==0){
    return " ";
  }
  for(int i=0;i<strlen(str);i++){
    if((int)(str[i])>110 || ((int)(str[i])>77&&(int)(str[i])<97)){
      encrypted[i]=(char)((int)str[i]-13);
    }
    else{
      encrypted[i]=(char)((int)str[i]+13);
    }
  }
  return encrypted;
}
static void sighandler(int sig_no) {
    if (sig_no == SIGINT){
      remove("s2c");
      printf("\nPipe Removed\n");
      exit(1);
    }
}
int main() {
  signal(SIGINT,sighandler);

  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );
    char * data=calloc(BUFFER_SIZE,sizeof(char));
    while(read(from_client,data,BUFFER_SIZE)){
      char * response=encryptstring(data);
      write(to_client,response,strlen(response)+1);
      printf("The client says %s\n",data);
      fflush(stdout);
      data=calloc(BUFFER_SIZE,sizeof(char));
    }
  }
}
