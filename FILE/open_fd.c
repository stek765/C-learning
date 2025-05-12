#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h> // Include errno.h for accessing errno

#define BUFFER 200

int main(int argc, char *argv[]) {
    
    char sost[] = "Coglione"; // No need to specify array size
    
    int fd = open("newfile.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRUSR);
    if (fd == -1) {
        perror("Error"); // Print error message
    } else {
        printf("File opened successfully.\n");
        
        ssize_t bytes_written = write(fd, sost, sizeof(sost) - 1); // Write content without null terminator
        if (bytes_written == -1) {
            perror("Write error"); // Print write error message
        } else {
            printf("Bytes written: %zd\n", bytes_written);
        }
        
        close(fd); // Don't forget to close the file descriptor
    }
    
    return 0;
}
