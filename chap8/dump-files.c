#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

enum {buff_max = 32,};

int main (int argc, char *argv[argc + 1]){
  int ret = EXIT_FAILURE;
  char buffer[buff_max] = {};

  if(strcmp(argv[1], "-n") == 0 && argc > 2){

    size_t ln = 0;
    for (int i = 2; i < argc; ++i) {
      FILE* instream = fopen(argv[i], "r");
      if(instream) {
        while (fgets(buffer, buff_max, instream)) {
          fprintf(stdout, "%3zu - %s", ln, buffer);
          ++ln;
        }
        fclose(instream);
        ret = EXIT_SUCCESS;
      } else {
        fprintf(stderr, "Could not open %s: ", argv[i]);
        perror(0);
        errno=0;
      }
    }
  }
  else{

    for (int i = 1; i < argc; ++i) {
      FILE* instream = fopen(argv[i], "r");
      if(instream) {
        while (fgets(buffer, buff_max, instream)) {
          fputs(buffer, stdout);
        }
        fclose(instream);
        ret = EXIT_SUCCESS;
      } else {
        fprintf(stderr, "Could not open %s: ", argv[i]);
        perror(0);
        errno=0;
      }
    }
  }
  if(argc < 2){

    while((fgets(buffer, buff_max, stdin)) != NULL){
      fputs(buffer, stdout);
    }

    ret = EXIT_SUCCESS;
  }

  return ret;
}

