#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

char ** parse_args(char *line) {
  unsigned short i;
  unsigned short ary_size = 4;
  char **args = malloc(ary_size * sizeof(char *));
  char *cur = line;
  i = 0;
  while(*cur != '\0') {
    args[i++] = strsep(&cur," \t\n");
    if(i >= ary_size) {
      ary_size *= 2;
      args = realloc(args,ary_size * sizeof(char *));
    }
  }
  args[i] = NULL;
  return args;
}

int main(){
  printf("> ");
  char buf[128];
  fgets(buf,128,stdin);
  char **args = parse_args(buf);
  execvp(args[0],args);
  free(args);
}
