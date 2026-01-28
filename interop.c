#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXPORT __declspec(dllexport)

/** 
Creates a file with the corresponding data, name, path
@param path the path file will be created
@param name the name of the file
@param data the data payload of the file
@param dataLength the length of data
*/
EXPORT unsigned char create(const char* path, const char* name, const unsigned char* data, size_t dataLength)
{
    size_t size[2] = {strlen(path), strlen(name)};
    char* combinedPath = (char*)malloc(size[0]+size[1]+2);
    if(!combinedPath)
    {
        perror("allowcation error");
        return 1;
    }

    if(*path == '\0')
    {
        strcpy(combinedPath, ".\\");
        size[0]++;
    }
    else 
    {
        strcpy(combinedPath, path);
        combinedPath[size[0]]='\\';
    }

    strcpy(combinedPath+size[0]+1, name);

    FILE* file = fopen(combinedPath, "wb");

    if(!file)
    {
        perror("error opening fstream");
        return 1;
    }
    if(!fwrite(data, dataLength, 1, file))
    {
        perror("failed to write data");
        return 1;
    }

    fclose(file);
    free(combinedPath);

    return 0;
} 