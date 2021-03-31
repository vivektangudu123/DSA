#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void q1(struct node **head,int pos,int val)
{
    int count=0;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *ji=*head;
    struct node *temp=NULL;
    new->data=val;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    if(pos==0)
    {
        new->next=*head;
        *head=new;
        return;
    }
    while(count!=pos-1)
    {
        ji=ji->next;
        count=count+1;
    }
    temp=ji->next;
    ji->next=new;
    new->next=temp;
    return;
}
void q2(struct node** head, int pos)
{
    struct node *temp = *head, *prev;
    int count=0;
    if (temp != NULL && pos == 0) {
        *head= temp->next; 
        free(temp); 
        return;
    }
 
    while (temp != NULL && count!=pos) {
        prev = temp;
        temp = temp->next;
        count=count+1;
    }
   
    prev->next = temp->next;
    free(temp); 
}
void q3(struct node *head,int pos,int val)
{
    int count=0;
    while(count!=pos)
    {
        head=head->next;
        count=count+1;        
    }
    head->data=val;
    return;
}
void q4(struct node *head)
{
    int temp=head->data;
    while(head->next!=NULL)
    {
        if(temp<head->data)
        {
            temp=head->data;
        }
        head=head->next;
    }
    if(temp<head->data)
    {
        temp=head->data;
    }
    printf("%d\n",temp);
}
void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
int main()
{
    int a,i=0;
    struct node *head=NULL;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        int t,k,v;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d",&k,&v);
            q1(&head,k,v);
        }
        else if(t==2)
        {
            scanf("%d",&k);
            q2(&head,k);
        }
        else if(t==3)
        {
            scanf("%d%d",&k,&v);
            q3(head,k,v);
        }
        else if(t==4)
        {
            q4(head);
        }
    }
}
