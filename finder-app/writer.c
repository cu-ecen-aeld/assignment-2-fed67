#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char* argv[]) {


    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Error function must have <file-path> and <text> as given arguments");
        closelog();
        exit(1);
    }

    char* path = argv[1];
    char* data = argv[2];
    
    //printf("path %s\n", path);
    //printf("data %s\n", data);

    FILE *myfile = fopen(path, "w");


    if(myfile == NULL) {
        syslog(LOG_ERR, "Error message: %i", errno );
        closelog();
        exit(1);
    }

    fputs(data, myfile);

    syslog(LOG_DEBUG, "Writing %s to %s", data, path);


    fclose(myfile);
    closelog();

    return 0;
}