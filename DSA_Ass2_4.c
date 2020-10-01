#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node* Create_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->next=NULL;
    return n;
}
void insert()
{
    struct node *t,*p;
    t=Create_node();
    printf("Enter Data :");
    scanf("%d",&t->data);
    if(start==NULL)
    {
    start=t;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}

void reverse_set(struct node *head)
{
    int size;
    printf("Enter size of Group :");
    scanf("%d",&size);
struct node *p,*q,*r;
int c=1;
q=NULL;
r=NULL;
p=head;
while(p!=NULL)
{
    if(c==size)
    {
        c=0;
        r=NULL;
        q=NULL;
    }
    r=q;
    q=p;
    p=p->next;
    q->next=r;
}
head=q;
view_list(head);
}

void view_list(struct node *start)
{
    struct node *t;
    if(start==NULL)
        printf("\nList Is Empty\n");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d\n",t->data);
            t=t->next;
        }
    }
}
int main()
{
    int choice;
    printf("1.Insert_node");
    printf("\n2.Reverse");
    printf("\n3.View List");
    printf("\n4.Exit\n");
    while(1)
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            reverse_set(start);
            break;
        case 3:
            view_list(start);
            break;
        case 4:
            exit(0);
        }
    }
}
