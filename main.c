#include <stdio.h>
#include "main.h"

// testing for function library
int main(void) {
FILE* fp = fopen("text.txt","r");
Node* p;
Node* Lines = GetFileLines(fp);
fclose(fp);
PrintList(Lines);
return 0;
}
