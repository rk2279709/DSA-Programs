
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

void find_loop()
{
    int flag=0;
    struct node *p,*q;
    p=start;
    q=start;
    while(p!=NULL&&q!=NULL)
    {
            p=p->next;
            q=q->next->next;
            if(p==q)
            {
                printf("\nLOOP EXISTs\n");
                flag==1;
                break;
            }
    }
    if(flag==0)
    {
        printf("\nNo Loop Exist\n");
        return;
    }
    else
    {
        p=start;
        while(p!=q)
        {
            p=p->next;
            q=q->next->next;
        }
        printf("\nIntersection point data = %d\n",p->data);

        while(p->next!=q)
            p=p->next;
        p->next=q;
    }
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
    printf("\n2.Find loop");
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
            find_loop();
            break;
        case 3:
            view_list();
            break;
        case 4:
            exit(0);
        }
    }
}
