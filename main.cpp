#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 2048

void docat(char *file);

int main(int argc, char* argv[]){
	if(argc == 1){//no failes sugested
		while(1){
			char readbuf[BUF_SIZE];
			read(STDIN_FILENO, readbuf, sizeof(readbuf));
			write(STDOUT_FILENO, readbuf, strlen(readbuf));
		}
	}

	else if(argc > 1){
		int i;
		for(i = 1;i < argc; i++){
			docat(argv[i]);
		}
	}
	return 0;

/*	if(argc != 2) {//must one file
		printf("useage: mycat [filename]\n");
		return 1;
	}*/
	//FILE *fp;
	//char *filename;
	//filename = (char*)malloc(sizeof(char) * strlen(argv[1]));
	//strcpy(filename,argv[1]);
	////printf("filename: %s\n",filename);

	//fp = fopen(filename,"r");
	//if(!fp){
	//	printf("not exist %s\n",filename);
	//	return 1;
	//}

	//char buf[BUF_SIZE];

	//while(fgets(buf, sizeof(buf), fp)){
	//	printf("%s",buf);
	//}

	//return 0;
}

void docat(char *file){
    int fd;

    fd = open(file, O_RDONLY);
    if(fd < 0){
        //fprintf(stderr, "not exist %s\n",file);
		perror(file);
		exit(1);
    }   

    char buf[BUF_SIZE];

    while(read(fd, buf, sizeof(buf)) > 0){
    	write(STDOUT_FILENO, buf, strlen(buf));
    }   
	close(fd);
}
