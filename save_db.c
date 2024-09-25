#include "in_in.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

Condition save_Database(main_t *ptr[]){
	FILE *fptr = fopen("update.txt","w");
	for(int i=0;i<W_SIZE;i++){
		main_t *temp = ptr[i];
		if(temp == NULL){
			continue;
		}
		sub_t *sub_temp = temp->link; 
		while(temp){
			fprintf(fptr,"#%d;%s;%d",i,temp->s_data,temp->f_count);
			while(sub_temp){
				fprintf(fptr,";%s;%d",sub_temp->f_name,sub_temp->count);
				sub_temp=sub_temp->next;
			}
			fprintf(fptr,"#\n");
			temp=temp->next;
		}
	}
}
