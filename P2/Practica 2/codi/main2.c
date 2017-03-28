#include<stdio.h>
#include "calculator.h"
#include "counter.h"

int main(int argc, char *argv[]){
	int i;
	char temp;
	printf("------------------------\n");
	for(i=1;i<argc;i++){
		printf("Argument %i: %s\n", i, argv[i]);
		if(argv[i][0]=='-'){
			printf("-");
			temp=argv[i][1];
			switch(temp){
			case 'e':
				printf(" Euclidean distance: %f\n", euclideanDistance(atoi(argv[i+1]),atoi(argv[i+2]),atoi(argv[i+3]),atoi(argv[i+4])));
				i+=4;
				break;
			case 'm':
				printf(" Manhattan distance: %f\n", manhattanDistance(atoi(argv[i+1]),atoi(argv[i+2]),atoi(argv[i+3]),atoi(argv[i+4])));
				i+=4;
				break;
			case 'w':
				printf(" Number of words: %d\n", countWords(argv[i+1]));
				i+=1;
				break;
			case 'o':
				printf(" Number of occurrences: %d\n", countOccurrences(argv[i+1],argv[i+2][0]));
				i+=2;
				break;
			default:
				printf(" Not a valid option\n");
				break;
			}
		}
	}
	printf("------------------------\n");
	return 0;
}
