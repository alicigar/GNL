#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;
    int is_first_call = 1;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open the file.\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] == '\n')
            printf("Empty line: \"\\n\"\n");
        else
            printf("Line read: %s", line);
        free(line);
        is_first_call = 0;
    }
    if (is_first_call && line == NULL)
        printf("The file is empty.\n");

    close(fd);
    return (0);
}
