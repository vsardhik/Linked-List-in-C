#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *pre;
    int data;
    struct node *next;
}node;

node *insertatbeg(node *head)
{
    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if(head==NULL)
    {
        printf("Enter the value you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=temp;
        temp->next=temp;
        head=temp;
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        printf("Enter the value you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=ptr;
        temp->next=head;
        head->pre=temp;
        ptr->next=temp;
        head=temp;
    }
    return head;
}


node *insertatlast(node *head)
{
    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if(head==NULL)
    {
        printf("Enter the value you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=temp;
        temp->next=temp;
        head=temp;
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        printf("Enter the value you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=ptr;
        temp->next=head;
        ptr->next=temp;
        head->pre=temp;
    }
    return head; 
}


node *deleteatbeg(node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==head)
    {
        node *ptr=NULL;
        ptr=head;
        printf("The element deleted from the list is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        printf("The element deleted from the list is %d\n",ptr->data);
        head=head->next;
        head->pre=ptr->pre;
        ptr->pre->next=head;
        free(ptr);
    }
    return head;
}


node *deleteatlast(node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==head)
    {
        node *ptr=NULL;
        ptr=head;
        printf("The element deleted from the list is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        printf("The element deleted from the list is %d\n",ptr->data);
        ptr->pre->next=head;
        head->pre=ptr->pre;
        free(ptr);
    }
    return head;
} 


node *insertafterinfo(node *head)
{
    node *temp=NULL;
    int info;
    printf("Enter the data after which you want to insert a node\n");
    scanf("%d",&info);
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not Allocated\n");
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        while(ptr->data!=info)
        {
            ptr=ptr->next;
        }
        if(ptr->next==head)
        {
            head=insertatlast(head);
            return head;
        }
        printf("Enter the data you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=ptr;
        temp->next=ptr->next;
        temp->next->pre=temp;
        ptr->next=temp;
    }
    return head;
}



node *insertbeforeinfo(node *head)
{
    node *temp=NULL;
    int info;
    printf("Enter the data before which you want to insert a node\n");
    scanf("%d",&info);
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not Allocated\n");
    }
    else
    {
        node *ptr=NULL;
        ptr=head;
        if(head->data==info)
        {
            head=insertatbeg(head);
            return head;
        }
        while(ptr->data!=info)
        {
            ptr=ptr->next;
        }
        printf("Enter the data you want to insert\n");
        scanf("%d",&temp->data);
        temp->pre=ptr->pre;
        temp->next=ptr;
        temp->pre->next=temp;
        ptr->pre=temp;
    }
    return head;
}


node *deleteafterinfo(node *head)
{
    int info;
    printf("Enter the data after which you want to delete a node\n");
    scanf("%d",&info);
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        node *ptr=NULL,*p1=NULL;
        ptr=head;
        while(ptr->data!=info)
        {
            ptr=ptr->next;
        }
        p1=ptr;
        p1=p1->next;
        if(ptr->next==head)
        {
            head=deleteatbeg(head);
            return head;
        }
        printf("The node deleted from the list is %d\n",p1->data);
        ptr->next=p1->next;
        p1->next->pre=ptr;
        free(p1);
    }
    return head;
}



node *deletebeforeinfo(node *head)
{
    int info;
    printf("Enter the data before which you want to delete a node\n");
    scanf("%d",&info);
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(head->data==info)
    {
        head=deleteatlast(head);
        return head;
    }
    else
    {
        node *ptr=NULL,*p1=NULL;
        ptr=head;
        while(ptr->data!=info)
        {
            ptr=ptr->next;
        }
        p1=ptr;
        p1=p1->pre;
        printf("The node deleted from the list is %d\n",p1->data);
        ptr->pre=p1->pre;
        p1->pre->next=ptr;
        free(p1);
    }
    return head;
}


void display(node *head)
{
    node *ptr=NULL;
    ptr=head;
    while(ptr->next!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}




int main()
{
    node *head=NULL;
    char ch;
    int choice;
    do
    {
       printf("Operations you can perform are\n");
       printf(" 1.insertatbeg \n 2.insertatlast \n 3.deleteatbeg \n 4.deleteatlast \n 5.insertafterinfo \n 6.insertbeforeinfo \n 7.deleteafterinfo \n 8.deletebeforeinfo \n 9.display\n");
       printf("Enter the choice for the operation you want to perform\n");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:
        head=insertatbeg(head);
        break;

        case 2:
        head=insertatlast(head);
        break;

        case 3:
        head=deleteatbeg(head);
        break;

        case 4:
        head=deleteatlast(head);
        break;

        case 5:
        head=insertafterinfo(head);
        break;

        case 6:
        head=insertbeforeinfo(head);
        break;

        case 7:
        head=deleteafterinfo(head);
        break;

        case 8:
        head=deletebeforeinfo(head);
        break;

        case 9:
        display(head);
        break;

        default:
        printf("Invalid Choice\n");
       }
       printf("Do you want to continue Y or N...\n");
       scanf(" %c",&ch);
    } while (ch=='y' || ch=='Y');
    return 0;
}
