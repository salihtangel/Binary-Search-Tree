#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100
struct list_node {
	char name[MAX_STR_SIZE];
	char file_names[MAX_STR_SIZE][MAX_STR_SIZE];
	int file_count;
	int output_txt_directory_flag;	/*to find which directory are you printing*/
	struct list_node* previous;
	struct list_node* next;
};

typedef struct list_node node;

int count(node* head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

int find(char *name, node* head) {
	int ret = -1;
	int index = 0;
	while (head) {
		if (strncmp(head->name, name, MAX_STR_SIZE - 1) == 0) {
			return index;
		}
		index++;
		head = head->next;
	}
	return ret;
}

node* get_by_index(int index, node* head) {
	int counter = count(head);
	int i = 0;
	if (index < 0 || index > counter) {
		return NULL;
	}
	for (i = 0; i <= index; i++) {
		if (i == index) {
			return head;
		}
		head = head->next;
	}
	return head;
}

int add_file(int index, char *file, node* head) {
	int ret = -1;
	node *current = get_by_index(index, head);
	if (current == NULL) {
		return ret;
	}
	strncpy(current->file_names[current->file_count++],
		file,
		MAX_STR_SIZE -1);
}

node* remove_first(node* head) {
	head = head->next;
	free(head->previous);
	head->previous = NULL;
	return head;
}

int remove_last(node* head) {
	while (head) {
		if (head->next->next == NULL) {
			free(head->next);
			head->next = NULL;
			return 0;
		}
		head = head->next;
	}
	return -1;
}

node* remove_at_index(int index, node* head) {
	node* current;
	if (index == 0) {
		return remove_first(head);
	} else if (index < 0) {
		return head;
	}
	current = get_by_index(index, head);
	if (current == NULL) {
		return head;
	}
	current->previous->next = current->next;
	if (current->next != NULL) {
		current->next->previous = current->previous;
	}
	free(current);
	return head;
}

node* add_first(char* name, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	strncpy(new_node->name, name, MAX_STR_SIZE-1);
	new_node->next = head;
	if (head != NULL) {
		head->previous = new_node;
	}
	head = new_node;
	return head;
}

void add_after(char* name, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	/*new_node->name = name;*/
	new_node->next = head->next;
	new_node->previous = head;
	new_node->next->previous = new_node;
	head->next = new_node;
}

void add_last(char* name, node* current) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	while (current) {
		if (current->next == NULL) {
			current->next = new_node;
			strncpy(new_node->name, name, MAX_STR_SIZE-1);
			new_node->previous = current;
			return;
		}
		current = current->next;
	}
}

void print_list(node* current) {
//ASIL BASILMASI GEREKN KISIM BURASI AMA SEG VERIYODU DIYE ATLADIN BAK
#if 0
	node *temp;
	temp=current;
	FILE * fp;	/*buraya output.txt acilacak */
	int i;
	int flag=0;
	temp->output_txt_directory_flag=-1;
	printf("%d",temp->output_txt_directory_flag);
	fp=fopen("output.txt","w");
	//fprintf(fp,"%s",temp->name);
	while(temp){
		if(flag==0){
			while(temp->output_txt_directory_flag == -1){
			fprintf(fp,"->%s\n", temp->name);
			temp=temp->next;
			flag=1;
			}
		}
		else{
			if(temp!= current)	//hata olabilir
			{
				temp=temp->previous;
			}
			fprintf(fp,"->%s\n", temp->name);
			for (i = 0; i < temp->file_count; ++i) {
				fprintf(fp,"\t%s\n", temp->file_names[i]);
			}
			temp=temp->next;
			temp->output_txt_directory_flag=-1;
			temp=current;		//-1ler gecmeyebilir
			flag=0;
		}
	}

#endif
		FILE *fp;
		fp = fopen("output.txt","w");
		while (current) {
		int i;
		fprintf(fp,"->%s\n", current->name);
		for (i = 0; i < current->file_count; ++i) {
			fprintf(fp,"\t%s\n", current->file_names[i]);
		}
		current = current->next;
	}
		//fclose(fp);
}

void print_list_from_tail(node* current) {
	current = get_by_index(count(current) - 1, current);
	printf("TAIL: ");
	while (current) {
		/*printf("%s %d", current->name, current->age);*/
		printf(" <- ");
		current = current->previous;
	}
	printf("\b\b\b\b :HEAD\n");
}

void print_list_backwards(node* current) {
	printf("TAIL: ");
	while (current) {
		/*printf("%s %d", current->name, current->age);*/
		printf(" <- ");
		current = current->previous;
	}
	printf("\b\b\b\b :HEAD\n");
}

int main(void) {
	node* head = NULL;
	node* tail = NULL;
	int add_head = 0;
	int number;
	unsigned int age = 0;

	FILE *fp;
	char text[MAX_STR_SIZE];
	char token_backup[MAX_STR_SIZE];
	char *token;

	fp = fopen("files.txt", "r");
	if (fp == NULL) {
		printf("file could not opened");
		return -1;
	}
	while (fgets(text, MAX_STR_SIZE, fp) != NULL) {
		char *p = NULL;
		text[strcspn(text, "\n")] = 0;
		p = strrchr(text, '/');
		token = strtok (text, "/");
		while (token != NULL) {
			/*printf("token=%s\n", token);*/
			if (add_head == 0) {
				head = add_first(token, head);
				add_head = 1;
			} else if (strcmp(token, p+1) == 0) {
				int index = find(token_backup, head);
				add_file(index, token, head);
			} else {
				int index = find(token, head);
				if (index == -1) {
					add_last(token, head);
				}
			}
			strncpy(token_backup, token, MAX_STR_SIZE - 1);
			token = strtok (NULL, "/");
		}
	}
	fclose(fp);

	print_list(head);
	return 0;
}
