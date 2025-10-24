#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main() 
{
    char **env = environ;
    char *path = getenv("PATH");

	printf("%s", path);
    return 0;
}