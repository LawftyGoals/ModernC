

#define FLINE 1001

int main(void){
  
  void filecompare(FILE *, FILE *);

  char *targetline;
  
  FILE *fp1;
  FILE *fp2;

  fp1 = fopen("test1.txt", "r");
  fp2 = fopen("test2.txt", "r");




  return 0;
}

void filecompare(FILE *f1, FILE *f2){
  char line1[FLINE];
  char line2[FILNE];
  int comp = 0;
  while(comp == 0 && fgets(line1, FLINE, f1) != NULL && fgets(line2, FLINE, f2) != NULL){
    if((comp = strcmp(line1, line2)) == 0)
      continue;




