#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link_node {
//	struct link_list *head;
	struct link_node *next;
	char  data[];
} Node;
typedef struct link_list{
	struct Node *head;
} List;

void create_node(Node **list, char *str)
{

	*list = malloc(sizeof(Node)+strlen(str));
	(*list)->next = NULL;
	strcpy( (*list)->data, str);
}

void push_list_node(List *list, char *data)
{
	Node *curr = NULL;
	Node *pre = NULL;
	Node *new = NULL;
	create_node(&new, data);

	if(list == NULL){
		printf("[Error] list is empty\n");
		return;
	}else{
		curr = list->head;
		while(curr != NULL){
			pre = curr;
			curr = curr->next;
		}
		pre->next = new;
	}
}

void remove_node(List *list, Node *target)
{
	Node *curr = NULL;
	Node *pre = NULL;
	
	curr = list;
	while((curr != target) && curr){
		pre = curr;
		curr = curr->next;
	}

	if(pre)
		pre->next = target->next;
	else
		list->head = target->next;

}
void destroy_list(Node **list)
{
	Node *curr = NULL;
	while(*list){
		curr = *list;
		*list=(*list)->next;
		free(curr);
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

	destroy_list(&my_node);
}



