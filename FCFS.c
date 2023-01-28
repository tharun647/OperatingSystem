#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    
    char source_file[] = "source.txt";
  
    char dest_file[] = "destination.txt";
    
    char buffer[1024];
  
    int source_fd;
    
    int dest_fd;
  
    int bytes_read;

    
    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    dest_fd = open(dest_file, O_CREAT | O_RDWR, 0644);
    if (dest_fd == -1) {
        perror("Error creating destination file");
        return 1;
    }

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(source_fd);
    close(dest_fd);

    return 0;
}


