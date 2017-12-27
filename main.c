#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "template.h"

char* getFilePath(int argc, char **argv);
void getDefinitions(int argc, char **argv, char **defs);

int main(int argc, char **argv) {
    char filepath[4096];
    strcpy(filepath, getFilePath(argc, argv));
    char *defs[argc];
    getDefinitions(argc, argv, defs);
    Template tmp = NewTemplate(filepath);

    printf("%s\n", tmp.filepath);
    printf("%s\n", defs[0]);
    printf("%s\n", defs[1]);

    return 0;
}

char* getFilePath(int argc, char **argv) {
    for( int i=0; i < argc; i++) {
        if(strcmp(argv[i], "-f") == 0) {
            if((argc - 1) > i) {
                return argv[i+1];
            }
            printf("%s\n", "No file path in arguments");
            exit(1);
        }
    }
}

void getDefinitions(int argc, char **argv, char **defs) {
    int count = 0;
    
    printf("%d", sizeof(defs));
    for( int i=0; i < argc; i++) {
        if(strcmp(argv[i], "-d") == 0) {
            if((argc - 1) > i) {
                printf("%d", count);
                defs[count] = malloc(sizeof argv[i+1]);
                strcpy (defs[count], argv[i+1]);
                count++;
            }
        }
    }
}