#define W_SIZE 26
#define F_SIZE 30

typedef enum {
	e_fail,
	e_suc
}Condition;

typedef struct node{
	int count;
	char s_data[WORD];
	main_t *next;
	sub_t *link;
}main_t;

typedef struct  subnode{
	int count;
	char f_name[F_SIZE];
	sub_t *next;
}sub_t;

typedef struct fileinfo{
	char f_name[F_SIZE];
	file_t *next;
}file_t;

Condition validate_file(file_t *files,char argv);
