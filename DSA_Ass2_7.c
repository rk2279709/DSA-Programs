
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

void pallindrome(struct node *start)
{
    struct node *p,*q,*r,*s,*start1,*prev;
        if(start==NULL)
    {
        printf("\nList is Empty\n");
        return start;
    }
    else
    {
    p=start;
    q=start;
    while(q!=NULL&&q->next!=NULL)
    {
        prev=p;
        p=p->next;
        q=q->next->next;
    }
    start1=p;
    prev->next=NULL;

    //Reversing
    r=NULL;
    q=NULL;
    s=start1;
    while(s!=NULL)
    {
        r=q;
        q=s;
        s=s->next;
        q->next=r;
    }
    start1=q;
    printf("List 1\n");
    view_list(start);
    printf("List 2\n");
    view_list(start1);

    //Checking Pallendrome
    p=start;
    q=start1;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data!=q->data)
        {
            printf("\nNot Pallindrome\n");
            return;
        }
        p=p->next;
        q=q->next;
    }
    printf("\nPallindrome\n");
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

int main()
{
    int choice;
    printf("1.Insert_node");
    printf("\n2.Check Pallindrome");
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
            pallindrome(start);
            break;
        case 3:
            view_list(start);
            break;
        case 4:
            exit(0);
        }
    }
}
