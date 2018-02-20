#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link_node {
	struct link_node *next;
	char  data[];
} Node;

typedef struct link_list{
	struct Node *head;
} List;

void create_node(Node **node, char *str)
{

	*node = malloc(sizeof(Node)+strlen(str));
	(*node)->next = NULL;
	strcpy( (*node)->data, str);
}

void push_list_node(List *list, char *data)
{
	Node *curr = NULL;
	Node *pre = NULL;
	Node *new = NULL;


	if(list == NULL){
		printf("[Error] list is empty\n");
		return;
	}else{
		create_node(&new, data);
		curr = list->head;

		while(curr != NULL){
			pre = curr;
			curr = curr->next;
		}
		pre->next = new;
	}
}

int remove_node(List *list, char *target)
{
	Node **curr = &list->head;
	Node *pre = list->head;

	while(strcmp((*curr)->data, target) ){
		printf("In %s, compareing the string of %s\n",__func__, (*curr)->data);
		pre = *curr;
		curr =&(* curr)->next;
		
		if(*curr == NULL)
			return -1;
	}


		*curr = pre->next;
	
	printf("In %s, will remove %s node\n",__func__,(*curr)->data);	
	free(*curr);
}

Node *find_node(List *list, char *target)
{
	Node *curr = list->head;

	while(strcmp(curr->data, target)){
		curr = curr->next;
		if(curr == NULL)
			return NULL;
		
	}
	printf("find node contain %s\n",curr->data);
	return curr;
	
}


void destroy_list(List *list)
{
	Node *curr = list->head;
	Node *next = NULL;

	while(curr){
		next = curr->next;
		free(curr);
		curr = next;
	}
}

int main (void)
{
	char *mydata = "Linux TED";
	Node *my_node = NULL;
	
	create_node(&my_node, mydata);
	List my_list = {.head = my_node};

	printf("%s the head  node is %p\n",__func__,my_node);	
	//printf("my data is %s\n",my_list->data);
	
	push_list_node(&my_list, "my_seconde_node");
	push_list_node(&my_list, "my_third_node");
	push_list_node(&my_list, "my_fourth_node");
	
	printf("my node data is %s\n",my_node->next->next->next->data);
	find_node(&my_list, "my_third_node");

	if(remove_node(&my_list,"my_third_node") == -1)
		printf("no this string to remove\n");
	if(find_node(&my_list, "m") == NULL )
		printf("no node be found\n");
	
	destroy_list(&my_list);
}



