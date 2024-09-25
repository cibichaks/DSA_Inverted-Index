#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "in_in.h"

Condition validate_file(file_t **head,char *argv[]){
	int count =1;
	while(argv[count]){
		if(strstr(argv[count],".txt") == NULL){ // checking file  extention .txt or not 
			printf("ATTENTION : %s is not a txt file, for this tool txt file is needed\n",argv[count]);
			count++;//Before ignoring the file Everytime We are increment count for get nxt file 
			continue;
		}
		FILE *fptr=fopen(argv[count],"r");
		if(fptr == NULL){ // checking for current directry or not
			printf("ATTENTION : %s Can't locate the file in current Directry \n",argv[count]);
			count++;
			continue;
		}

		fseek(fptr,0,SEEK_END);
		if(ftell(fptr) == 0){ //checking for empty file or not
			printf("ATTENTION : %s is a empty file can't process this file\n",argv[count]);
			count++;
			continue;
		}
		if(*head == NULL){
			file_t *node = malloc(sizeof(file_t)); // Adding valid files to a files list
			node->fptr = fptr;
			strcpy(node->f_name,argv[count]);
			node->next = NULL;
			*head=node;
			count++;
			continue;
		}
		file_t *temp = *head;
		int flag = 0;
		while(temp && temp->next){  //checking Duplicate file
			if(strcmp(argv[count],temp->f_name) != 0){
				temp=temp->next;
			}
		else{
				printf("ATTENTION : find %s file as find duplicate so ignored\n",argv[count]);
				flag=1;
				break;
			}
		}
		if(flag){
			count++;
			continue;
		}
		file_t *node = malloc(sizeof(file_t)); // Adding valid files to a files list
		node->fptr = fptr;
		strcpy(node->f_name,argv[count]);
		node->next = NULL;
		temp->next = node;
		count++;
	}
	if(*head == NULL){
		return e_fail;
	}
	
	return e_suc;
}
