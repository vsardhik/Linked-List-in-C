#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* pre;
    int data;
    struct node* next;
}node;

node* insertatbeg(node* head)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if (head == NULL)
    {
        printf("Enter the element you want to insert\n");
        scanf("%d", &temp->data);
        temp->pre = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        printf("Enter the element you want to insert\n");
        scanf("%d", &temp->data);
        temp->pre = NULL;
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    return head;
}

node* insertatlast(node* head)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if (head == NULL)
    {
        printf("Enter the element you want to insert\n");
        scanf("%d", &temp->data);
        temp->pre = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        node* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("Enter the element you want to insert\n");
        scanf("%d", &temp->data);
        temp->pre = ptr;
        temp->next = NULL;
        ptr->next = temp;
    }
    return head;
}

node* deleteatbeg(node* head)
{
    node* ptr;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        printf("The node deleted from the beginning is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        printf("The element deleted from the node is %d\n",ptr->data);
        head=head->next;
        head->pre=NULL;
        free(ptr);
    }
    return head;
}

node* deleteatlast(node* head)
{
    node* ptr;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head->next==NULL)
    { 
        ptr=head;
        printf("The node deleted from the list is %d\n",ptr->data);
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->pre->next=NULL;
        printf("The node deleted from the list is %d\n",ptr->data);
        free(ptr);
    }
    return head;
}

void display(node* head)
{
  while(head)
  {
    printf("%d ",head->data);
    head=head->next;
  }
}


node* insertafterinfo(node* head)
{
    node *temp = NULL, *ptr = NULL;
    int info;
    temp = (node*)malloc(sizeof(node));
    printf("Enter the data after which you want to insert a node\n");
    scanf("%d", &info);
    if (temp == NULL)
    {
        printf("Memory not Allocated\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL && ptr->data != info)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            head = insertatlast(head);
            return head;
        }
        printf("Enter the element you want to insert in list\n");
        scanf("%d", &temp->data);
        temp->pre = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
        temp->next->pre = temp;
    }
    return head;
}



node* insertbeforeinfo(node* head)
{
    node *temp = NULL, *p1 = NULL, *p2 = NULL;
    int info;
    temp = (node*)malloc(sizeof(node));
    printf("Enter the data before which you want to insert a node\n");
    scanf("%d", &info);
    if (temp == NULL)
    {
        printf("Memory not Allocated\n");
    }
    else if (head->data == info)
    {
        head = insertatbeg(head);
        return head;
    }
    else
    {
        p1 = head;
        while (p1 != NULL && p1->data != info)
        {
            p2 = p1;
            p1 = p1->next;
        }
        if (p1 == NULL)  // info not found in the list
        {
            printf("Node with data %d not found\n", info);
            free(temp);  // Free allocated memory if not used
            return head;
        }
        printf("Enter the element you want to insert in list\n");
        scanf("%d", &temp->data);
        temp->pre = p2;
        temp->next = p1;
        p2->next = temp;
        p1->pre = temp;
    }
    return head;
}



node *deleteafterinfo(node *head)
{
    int info;
    printf("Enter the data after which you want to delete a element\n");
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
        if(ptr->next==NULL)
        {
            printf("No node exists after this node so deletion is not possible\n");
            return head;
        }
        p1=ptr;
        p1=p1->next;
        if(p1->next==NULL)
        {
            head=deleteatlast(head);
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
    printf("Enter the data before which you want to delete a element\n");
    scanf("%d",&info);
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(head->data==info)
    {
        printf("No node exists before this node so deletion is not possible\n");
        return head;
    }
    else
    {
        node *ptr=NULL,*p1=NULL;
        ptr=head;
        while(ptr->data!=info)
        {
            p1=ptr;
            ptr=ptr->next;
        }
        printf("The node deleted from the list is %d\n",p1->data);
        p1->pre->next=ptr;
        ptr->pre=p1->pre;
        free(p1);
    }
    return head;
}


int main()
{
    node* head=NULL;
    int choice;
    char ch;
    do
    {
        printf("The operations you can perform on doubly linked list\n");
        printf(" 1.insertatbeg \n 2.insertatlast \n 3.deleteatbeg \n 4.deleteatlast \n 5.display \n 6.insertafterinfo \n 7.insertbeforeinfo \n 8.deleteafterinfo \n 9.deletebeforeinfo\n");
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
            display(head);
            break;

            case 6:
            head=insertafterinfo(head);
            break;

            case 7:
            head=insertbeforeinfo(head);
            break;

            case 8:
            head=deleteafterinfo(head);
            break;

            case 9:
            head=deletebeforeinfo(head);
            break;

            default:
            printf("Invalid Choice\n");
        }
        printf("Do you want to continue Y or N...\n");
        scanf(" %c",&ch);
    } while (ch=='y' || ch=='Y');
    return 0;
}
