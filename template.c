#include <string.h>

#include "template.h"

Template NewTemplate(char filepath[]) {
    Template tmp;
    strcpy(tmp.name, "name");
    strcpy(tmp.filepath, filepath);
    return tmp;
}