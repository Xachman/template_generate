#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "template.h"

char* getFilePath(int argc, char **argv);

int main(int argc, char **argv) {
    char filepath[4096];
    strcpy(filepath, getFilePath(argc, argv));
    Template tmp = NewTemplate(filepath);

    printf("%s", tmp.filepath);

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