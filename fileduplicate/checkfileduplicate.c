#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

typedef struct dirent dirent;

typedef {
  char d_name[256];
  unsigned char d_type;
} small_dirent;

dirent *allocate_dirents(char *dirname, dirent *entries, size_t size);

int main(void){

  //dirent *entries;

  size_t count = 0;
  dirent *entry;
  DIR *target;
  if((target = opendir("./test")) == NULL)
      perror("failed at opendir()");

  while((entry = readdir(target)) != NULL){
    if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) count++;
    printf("%s\n", entry->d_name);
  }





  printf("%ld\n", count);

  return 0;
}


size_t calculate_max_size(char *dirname){
  size_t mass = 0;
  size_t count;

  dirent *dir;
  DIR *target;

  if((target = opendir(dirname)) == NULL){
    perror("failed to open %s", dirname);
  }

  for(count = 0; (dir = readdir(target)) != NULL; count++){
    mass += strlen(dir->d_name) + 1;
  }
  
}



dirent *allocate_dirents(char *dirname, small_dirent *entries, size_t size){
  dirent *dir;
  DIR *target;

  small_dirent *small_entries = (small_dirent *) malloc(sizeof(small_dirent) * size);
  small_dirent *ep = entries;

  if((target = opendir("./test")) == NULL)
      perror("failed at opendir()");


  for(size_t i = 0; (dir = readdir(target)) != NULL && i < size; i++){
    printf("%s\n", dir->d_name);
    ep->d_type = dir->d_type;
    strcpy(ep->d_name, dir->d_name);
  }

}
