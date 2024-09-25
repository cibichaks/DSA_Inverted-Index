#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"in_in.h"

Condition Display_Database(main_t *ptr[]){
	for(int i=0 ; i<W_SIZE ; i++){
		if(ptr[i] == NULL){
			continue;
		}
		main_t *temp = ptr[i];
		while(temp){
			printf("%s\tprecent in\t%d file those are : ",temp->s_data,temp->f_count);
			sub_t *sub_temp = temp->link;
			while(sub_temp){
				printf("\t%s in %d times",sub_temp->f_name,sub_temp->count);
				sub_temp=sub_temp->next;
			}
			printf("\n");
			temp=temp->next;
		}
	}		
}

