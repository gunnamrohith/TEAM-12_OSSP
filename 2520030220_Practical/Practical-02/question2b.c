#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    int fd;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        write(2, "Usage: ./cat_custom <filename>\n", 31);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "Cannot open file\n", 17);
        exit(1);
    }

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(1, buffer, bytes_read);
    }

    close(fd);
    return 0;
}