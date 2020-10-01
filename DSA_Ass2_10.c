#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node* Create_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->next=NULL;
    return n;
}
void insert(struct node **start)
{
    struct node *t,*p;
    t=Create_node();
    printf("Enter Data :");
    scanf("%d",&t->data);
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

int check_sort(struct node *head)
{
struct node *p;
p=head;
while(p->next!=NULL)
{
    if(p->data>p->next->data)
    {
        return 0;
    }
    p=p->next;
}
return 1;
}

void sort(struct node **head)
{
    int temp;
    struct node *p,*q;
    for(p=(*head);p->next!=NULL;p=p->next)
    {
        for(q=p->next;q->next!=NULL;q=q->next)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }

}
}

void merge_sort(struct node *head1,struct node *head2)
{
    struct node *last,*p,*q,*head3;
    p=head1;
    q=head2;
    if(check_sort(head1)&&check_sort(head2))
    {
        printf("\nList Are Not Sorted\n");
        return;
    }
    else
    {
        if(p->data<q->data)
        {
            last=p;
            head3=p;
             p=p->next;
               last->next=NULL;

        }
        else
        {
            last=q;
            head3=q;
            q=q->next;
                last->next=q;
        }
        while(p!=NULL&& q!=NULL)
        {
            if(p->data<q->data)
            {
               last->next=p;
               last=p;
               p=p->next;
               last->next=NULL;

            }
            else
            {
                last->next=q;
                last=q;
                q=q->next;
                last->next=q;
            }
        }
        if(p==NULL)
            last->next=q;
        else
            last->next=p;
    }
    view_list(head3);
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
    printf("1.Insert_node_List1");
    printf("\n2.Insert_node_list2");
    printf("\n3.Sort List 1 ");
    printf("\n4.Sort list 2 ");
    printf("\n5.View List 1");
    printf("\n6.View List 2");
    printf("\n7.Merge_sort");
    printf("\n8.Exit\n");
    while(1)
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert(&start1);
            break;
        case 2:
            insert(&start2);
            break;
        case 3:
            sort(&start1);
            break;
        case 4:
            sort(&start2);
            break;
        case 5:
            view_list(start1);
            break;
        case 6:
            view_list(start2);
            break;
        case 7:
            merge_sort(start1,start2);
            break;
        case 8:
            exit(0);
        }
    }
}
