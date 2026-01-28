#include <stdio.h>
#include <stdlib.h>
#define IMPORT __declspec(dllimport)

IMPORT unsigned char create(const char* path, const char* name, const unsigned char* data, size_t dataLength);

int main()
{
    unsigned char success = create("", "test.txt", "thisisatestmessage", 19);
    if(!success)
        return 1;
    else printf("%d\n", success);
    printf("test");
    scanf("%s");
    return 0;
}