#include <stdlib.h>
#include <string.h>

char *get_dir_name(char *path) {
    char *dirname, *token;

    token = strtok(path, "/");
    while(token != NULL) {
        dirname = token;
        token = strtok(NULL, "/");
    }
 
    if(dirname == NULL) {
        return NULL;
    }
    return dirname;
}