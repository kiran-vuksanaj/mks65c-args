#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  printf("> ");
  char buf[128];
  fgets(buf,128,stdin);
  char *args[64];
  char *cur = buf;
  unsigned short i = 0;
  while(*cur != '\0') {
    args[i++] = strsep(&cur," \t\n");
  }
  unsigned short j;
  for(j = 0; j <= i; j++){
    if(args[j] == NULL) printf("NULL PTR\n");
    else                printf("[%s]\n",args[j]);
  }
}
