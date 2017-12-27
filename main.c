#include <stdio.h>

#include "template.h"

int main() {

    Template tmp = NewTemplate("/test/path");

    printf("%s", tmp.filepath);

    return 0;
}