#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLINE 1001

int main(int argc, char* argv[]){
  
  void filecompare(FILE *, FILE *);

  FILE *fp1;
  FILE *fp2;

  if(argc == 3){
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
  }
  if(fp1 == NULL || fp2 == NULL){
    fprintf(stderr, "%s: can't open one of files tee hee\n", argv[0]);
    exit(1);
  }

  filecompare(fp1, fp2);


  return 0;
}

void filecompare(FILE *f1, FILE *f2){
  char line1[FLINE];
  char line2[FLINE];
  char *lp1;
  char *lp2;
  int comp = 0;
  while(comp == 0 && (lp1 = fgets(line1, FLINE, f1)) != NULL && (lp2 = fgets(line2, FLINE, f2)) != NULL){
    if((comp = strcmp(line1, line2)) != 0){
      printf("%s%s", line1, line2);
    }
  }
  if(lp1 == NULL) printf("file 1 ended at line: %s", line1);
  else if(lp2 == NULL) printf("file 2 ended at line: %s", line2);
  else if(comp == 0) printf("files are identical\n");

}
