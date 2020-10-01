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

int count()
{
    int c=0;
    struct node *t;
    if(start==NULL)
        return 0;
    else
    {
        t=start;
        while(t!=NULL)
        {
            t=t->next;
            c++;
        }
        return c;
    }
}

void find_nth()
{
    int c=count(start),n,m;
    printf("\nEnter Nth Node From Last :");
    scanf("%d",&n);

    m=c-n;
    if(start==NULL||m<0)
        printf("\nNode Not Available\n");
    else
    {
    struct node *t;
    t=start;
    for(int i=0;i<n-1;i++)
    {
        t=t->next;
    }
    printf("Third Node From Last :%d",t->data);
    }
}

void delete_ll()
{
free(start);
}

void view_list()
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
    printf("\n2.Find nth");
    printf("\n3.View List");
    printf("\n4.Exit\n");
    while(1)
    {
        printf("\nEnter Your Choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            find_nth();
            break;
        case 3:
            view_list();
            break;
        case 4:
            exit(0);
        }
    }
}
