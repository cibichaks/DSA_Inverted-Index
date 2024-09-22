#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "in_in.h"

Condition validate_file(file_t *files,char argv){
	int count =0;
	while(argv[count] != NULL){
		printf("%s\n",argv[count]);
		count++;
	}
}
