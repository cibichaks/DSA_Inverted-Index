#define W_SIZE 26
#define F_SIZE 30
#include<stdio.h>
typedef enum {
	e_fail,
	e_suc
}Condition;
typedef struct  sub_t{
	int count;
	char f_name[F_SIZE];
	struct sub_t *next;
}sub_t;
typedef struct node{
	int f_count;
	char s_data[W_SIZE];
	struct node *next;
	sub_t* link;
}main_t;



typedef struct fileinfo{
	FILE *fptr;
	char f_name[F_SIZE];
	struct fileinfo *next;
}file_t;

Condition validate_file(file_t **head,char *argv[]);

Condition Create_database(file_t **head,main_t *ptr[]);

Condition Display_Database(main_t *ptr[]);
Condition save_Database(main_t *ptr[]);
Condition Update_Database(main_t *ptr[]);
