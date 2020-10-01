
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
void fwd_print(struct node *start)
{
    if(start==NULL)
        return;
    else
    {
        printf("%d\n",start->data);
        fwd_print(start->next);
    }
}
void reverse_print(struct node *start)
{
    if(start==NULL)
        return;
    else
    {
        reverse_print(start->next);
        printf("%d\n",start->data);
    }
}

int main()
{
    int choice;
    printf("1.Insert_node");
    printf("\n2.Forward Print");
    printf("\n3.Reverse Print");
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
            fwd_print(start);
            break;
        case 3:
            reverse_print(start);
            break;
        case 4:
            exit(0);
        }
    }
}
