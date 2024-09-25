#include<stdio.h>
#include "in_in.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("ATTENTION: %s <file_names> example--> file.txt\n", argv[0]);
		return -1;
	}
	main_t *ptr[W_SIZE] = {NULL};
	file_t *head = NULL;
	if(validate_file(&head, argv)){
		printf("INFO : Validations are completed\n");
	}
	else{
		printf("ERROR : there is no valid File");
		return e_fail;
	}
	int choice = 0;
	int flag = 0;
	while(choice != 5){
		printf("\n1) Create Database\n2) Display Database\n3) Update Database\n4) Search in Database\n5) save and Exit\n6) Update Database\n   Enter your Choice :");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1 :
				if(Create_database(&head,ptr)){
					flag=1;
					printf("Success : Database created for the following files : ");
					while(head){
						printf("%s ",head->f_name);
						head=head->next;
					}
				}
				break;
			case 2 :

				if(flag){
					Display_Database(ptr);
				}
				else{
					printf("ERROR : Database is empty/\n");
				}
				break;
			case 3 :
				Update_database(ptr);
				break;
			case 5:
				save_Database(ptr);
				break;
		}
	}
}

