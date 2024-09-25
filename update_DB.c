#include<stdio.h>
#include<stdlib.h>
#include"in_in.h"

Condition  Update_Database(main_t *ptr[]){
	FILE *fptr = fopen("update.txt","r");
	char buffer[200];
	while(fscanf(fptr,"%s",buffer) != Eof){
		char* temp_string = strtok(buffer,"#;");
		
