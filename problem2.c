#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------------
// The block of code between the two commented borders is where your solution goes.
typedef struct node node;

struct node{
	int data; // The data stored in this node of Linked list.
	int id; // The id of this node, which is used to uniquely determine this node in the array A.
	struct node *next; // Pointer to the next node in the Linked list.
};
//for printing the node
void printList(node *head){
	node *curr = head;
	int len = 0;
	//calculating the length
	while(curr!=NULL){
		len++;
		curr = curr->next;
	}
	curr = head;
	printf("%d ",len );
	while(curr!=NULL){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
int leng(node *nod)
{
	int count=0;
	while(nod!=NULL)
	{
		count=count+1;
		nod=nod->next;
	}
	return(count);
}
node* findCommonList(node *head1, node *head2){
	int i,h1,h2,diff=0;
	node *temp1=head1;
	node *temp2=head2;
	h1=leng(head1);
	h2=leng(head2);
	if(h1>h2)
	{
		diff=h1-h2;
		for(i=0;i<diff;i++)
		{
			if(temp1==NULL)
			{
				return NULL;
			}
			temp1=temp1->next;
		}
	}
	else if(h2>h1)
	{
		diff=h2-h1;
		for(i=0;i<diff;i++)
		{
			if(temp2==NULL)
			{
				return NULL;
			}
			temp2=temp2->next;
		}
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->id==temp2->id)
		{
			return(temp1);
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return NULL;
}
//------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	struct node **head1 = malloc(sizeof(struct node*));
	struct node **head2 = malloc(sizeof(struct node*));
	char tmp = 'a';
	int val;
	int t;
	scanf("%d\n", &t);
	int *a = malloc(sizeof(int)*t);
	int i = 0;
	do
	{
		scanf("%d%c", &val, &tmp);
		a[i++] = val;
	} while (i < t);
	struct node *curr = *head1;
	struct node *prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head1 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	curr = *head2;
	prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head2 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	node* commonNode = findCommonList(*head1, *head2);
	printList(commonNode);
	return 0;
}