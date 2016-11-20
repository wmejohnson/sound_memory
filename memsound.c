//wm johnson
//reads bytes from memory and writes them into a wav file
//10 25 16

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "make_wav.h"

int main(int argc, char ** argv){

	int DEBUG = 1;	
	int length = 3;
	int bit_depth = 16;
	int sample_rate = 44100;
	char * out_file = "out.wav";
	int c;
	
	/**
	arguments:
		-l length of file in seconds (default 30)
		-b bit depth (default 16)
	 	-s sample rate (default 44100)
		-o output file name (default out.wav)	
		-h print a help thingy
	**/

	while (( c = getopt(argc, argv, "l:b:s:o:")) != -1){
	
		switch(c){
			case 'l':
				length=atoi(optarg);
				break;
			case 'b':
				bit_depth=atoi(optarg);
				break;
			case 's':
				sample_rate=atoi(optarg);
				break;
			case 'o':
				out_file=optarg;
				break;
			case 'h':
				printf("help\n");
				exit(1);
				break;
		}
	}
	
	printf("Sample Rate: %i, Bit Depth: %i, File Name: %s, Length: %i\n", sample_rate, bit_depth, out_file, length);

	//allocate the memory of the size we need
	short int * x; 
	x = malloc(sample_rate*length*sizeof(short int));
	if(x==NULL){
		printf("malloc error");
		exit(1);
	}

	if(DEBUG){
		printf("malloc'd\n");
		printf("%X\n", x);
	}

	write_wav(out_file, sample_rate*length, x, sample_rate);

	//close the file 
	free(x);

	if(DEBUG){
		printf("were done!\n");
	}

	return(1);
}


