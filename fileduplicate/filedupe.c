#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>



typedef struct dirent dirent;

typedef struct {
  size_t count;
  size_t mass;
} countNmass;

countNmass *calculate_max_size(char *dirname);
countNmass *mallocCM(size_t count, size_t mass);

int main(void){

  countNmass *sizes = calculate_max_size("./test");
  printf("%ld %ld\n", sizes->count, sizes->mass);
  return 0;
}

countNmass *calculate_max_size(char *dirname){
  size_t mass = 0;
  size_t count = 0;

  dirent *dir;
  DIR *target;

  if((target = opendir(dirname)) == NULL){
    perror("failed to open");
  }

  for(size_t i = 0; (dir = readdir(target)) != NULL; i++){
    if(dir->d_name[0] != '.'){
      mass += strlen(dir->d_name) + 1;
      count++;
    }

  }

  return mallocCM(count, mass);
}


countNmass *mallocCM(size_t count, size_t mass){
  countNmass *CM = (countNmass *) malloc(sizeof(countNmass));
  CM->count = count;
  CM->mass = mass;
  return CM;
}
