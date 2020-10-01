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
void insert(struct node **start,int val)
{
    struct node *t,*p;
    t=Create_node();
    t->data=val;
    if(*start==NULL)
    {
    *start=t;
    }
    else
    {
        p=(*start);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}

void seperate()
{
  struct node *head=NULL,*p,*temp,*q;
   q=start;
    p=start;
    temp=NULL;
  while(p!=NULL)
  {
    if(p->data%2!=0&&p==start)
    {
        temp=start;
        start=start->next;
        p=start;
        insert(&head,temp->data);
        free(temp);
        temp=NULL;
    }
    else if(p->data%2!=0)
    {
       temp=p;
       q->next=p->next;
       p=p->next;
       insert(&head,temp->data);
       free(temp);
       temp=NULL;
    }
    else{
    q=p;
    p=p->next;
    }
  }
  p=start;
  while(p->next!=NULL)
  {
      p=p->next;
  }
  p->next=head;
  head=NULL;
  printf("After Seperating Even And Odd\n");
  view_list(&start);
}

void view_list(struct node **start)
{
    struct node *t;
    if(*start==NULL)
        printf("\nList Is Empty\n");
    else
    {
    t=(*start);
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
    }
}

int main()
{
    int choice,n;
    printf("1.Insert_node");
    printf("\n2.Seperate");
    printf("\n3.View List");
    printf("\n4.Exit\n");
    while(1)
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter Data :");
            scanf("%d",&n);
            insert(&start,n);
            break;
        case 2:
            seperate();
            break;
        case 3:
            view_list(&start);
            break;
        case 4:
            exit(0);
        }
    }
}


