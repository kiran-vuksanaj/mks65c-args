#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(){
  printf("> ");
  char buf[128];
  unsigned short i,j;
  fgets(buf,128,stdin);
  char *args[64];
  char *cur = buf;
  i = 0;
  while(*cur != '\0') {
    args[i++] = strsep(&cur," \t\n");
  }
  args[i] = NULL;
  // for(j = 0; j <= i; j++){
  //   if(args[j] == NULL) printf("NULL PTR\n");
  //   else                printf("[%s]\n",args[j]);
  // }
  execvp(args[0],args);
}
