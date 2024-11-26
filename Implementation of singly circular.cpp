#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
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
     printf("Enter the element you want to insert in node\n");
     scanf("%d",&temp->data);
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
    printf("Enter the element you want to insert in node\n");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
    ptr->next=temp;
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
        printf("Enter the element you want to insert in node\n");
        scanf("%d",&temp->data);
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
        printf("Enter the element you want to insert in node\n");
        scanf("%d",&temp->data);
        temp->next=head;
        ptr->next=temp;
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
        printf("The node deleted from the list is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        node *ptr=NULL,*p1=NULL;
        ptr=head;
        p1=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        printf("The node deleted from the list is %d\n",p1->data);
        head=head->next;
        ptr->next=head;
        free(p1);
    }
    return head;
}

node *deleteatlast(node *head)
{
    if(head==NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if(head->next==head)
    {
        node *ptr=NULL;
        ptr=head;
        printf("The node deleted from the list is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        node *p1=NULL,*p2=NULL;
        p1=head;
        while(p1->next!=head)
        {
            p2=p1;
            p1=p1->next;
        }
        printf("The node deleted from the list is %d\n",p1->data);
        p2->next=head;
        free(p1);
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
        printf("Memory Not Allocated\n");
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
        printf("Enter the element you want to insert in node\n");
        scanf("%d",&temp->data);
        temp->next=ptr->next;
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
    else if(head->data==info)
    {
        head=insertatbeg(head);
        return head;
    }
    else
    {
        node *p1=NULL,*p2=NULL;
        p1=head;
        while(p1->data!=info)
        {
            p2=p1;
            p1=p1->next;
        }
        printf("Enter the element you want to insert in node\n");
        scanf("%d",&temp->data);
        temp->next=p2->next;
        p2->next=temp;
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
        printf("List is empty\n");
    }
    else
    {
        node *ptr=NULL,*p2=NULL;
        ptr=head;
        while(ptr->data!=info)
        {
            ptr=ptr->next;
        }
        p2=ptr;
        p2=p2->next;
        if(p2==head)
        {
            head=deleteatbeg(head);
            return head;
        }
        printf("The node deleted from the list is %d\n",p2->data);
        ptr->next=p2->next;
        free(p2);
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
        printf("This is the first node no node is present before this node\n");
    }
    else
    {
        node *ptr=NULL,*p1=NULL,*p2=NULL;
        ptr=head;
        p2=head;
        while(ptr->data!=info)
        {
           p1=ptr;
           ptr=ptr->next;
        }
        while(p2!=p1 && p2->next!=p1)
        {
            p2=p2->next;
        }
        if(p2==p1)
        {
            head=deleteatbeg(head);
            return head;
        }
        printf("The node deleted from the list is %d",p1->data);
        p2->next=p1->next;  
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
       printf(" 1.inseratbeg \n 2.inseratlast \n 3.deleteatbeg \n 4.deleteatlast \n 5.insertafterinfo \n 6.inserbeforeinfo \n 7.deleteafterinfo \n 8.deletebeforeinfo \n 9.display\n");
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
