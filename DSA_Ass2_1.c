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
void swap()
{
    int m,n;
    struct node *t,*r,*prev1,*prev2;
    printf("Enter Two Elements to Be Swapped :");
    scanf("%d%d",&n,&m);
    if(start==NULL)
        printf("\nList Is Empty");
    else if(n==m)
    {
        printf("\nSwapping Not Possible for single element\n");
    }
    else
    {
        t=start;
        r=start;
        while(t->data!=n)
        {
            prev1=t;
            t=t->next;
            if(t==NULL)
            {
                printf("\nUnable to Swap due to less Data Available\n");
                return;
            }
        }
        while(r->data!=m)
        {
            prev2=r;
            r=r->next;
            if(r==NULL)
            {
                printf("\nUnable to swap due to less Data Available\n");
                return;
            }
        }
        prev1->next=t->next;
        prev2->next=r->next;
        r->next=prev1->next;
        prev1->next=r;
        t->next=prev2->next;
        prev2->next=t;
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
    printf("\n2.Swap Links");
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
            swap();
            break;
        case 3:
            view_list();
            break;
        case 4:
            exit(0);
        }
    }

}


