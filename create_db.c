#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "in_in.h"

Condition Create_database(file_t **head,main_t *ptr[]){
	file_t *file = *head;
	while(file){
		int index=0;
		char buffer[W_SIZE];
		printf("file name %s",file->f_name);
		rewind(file->fptr);
		while(fscanf(file->fptr,"%s",buffer) != EOF)
		{
		//	printf("file pointer %ld ",ftell(file->fptr));
			if(isupper(buffer[0])){
				index=buffer[0]-'A';
			}
			else{
				index=buffer[0]-'a';
			}
			printf("--%s--index->%d\n",buffer,index);
			main_t *node = malloc(sizeof(main_t));
			if(ptr[index] == NULL){
				node->f_count = 1;
				strcpy(node->s_data,buffer);
				node->next = NULL;
				sub_t *subnode = malloc(sizeof(sub_t));
				subnode->count = 1;
				strcpy(subnode->f_name,file->f_name);
				subnode->next = NULL;
				node->link=subnode;
				ptr[index] = node;
				continue;
			}else{
				main_t *temp = ptr[index];
				sub_t *sub_temp = temp->link;
				if(strcmp(temp->s_data,buffer) == 0){
					sub_t *subnode = temp->link;
					if(strcmp(sub_temp->f_name,file->f_name) == 0){
						sub_temp->count++;
					}
				}
				while(temp->next){
					if(strcmp(temp->s_data,buffer) == 0){
						int flag=0;
						while(sub_temp->next){
							if(strcmp(sub_temp->f_name,file->f_name) == 0){
								sub_temp->count++;
								flag=1;
								break;
							}
							sub_temp = sub_temp->next;
						}
						if(flag){
							break;
						}
						if(sub_temp->next == NULL){
							sub_t *subnode = malloc(sizeof(sub_t));
							subnode->count++;
							strcpy(subnode->f_name,file->f_name);
							subnode->next = NULL;
							temp->f_count++;
							sub_temp->next = subnode;
						}
						break;
					}
					temp=temp->next;
				}
				if(temp->next == NULL){
					strcpy(node->s_data,buffer);
					node->next = NULL;
					sub_t *subnode = malloc(sizeof(sub_t));
					subnode->count++;
					strcpy(subnode->f_name,file->f_name);
					subnode->next = NULL;
					node->link=subnode;
					temp->next = node;
					continue;		
				}

			}
		}
		file=file->next;
	}
	return e_suc;
}
