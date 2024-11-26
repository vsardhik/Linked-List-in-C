#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sn;

sn* insertAtBeg(sn *head) {
    sn *temp = (sn*)malloc(sizeof(sn));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }
    printf("Enter the element to insert at beginning: ");
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
    return head;
}

sn* insertAtLast(sn *head) {
    sn *temp = (sn*)malloc(sizeof(sn));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }
    printf("Enter the element to insert at last: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        sn *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void display(sn *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    sn *temp = head;
    printf("The elements in the list are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

sn* insertAtMiddle(sn *head) {
    sn *temp = (sn*)malloc(sizeof(sn));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }
    int pos, i = 1;
    printf("Enter the element to insert: ");
    scanf("%d", &temp->data);
    printf("Enter the position to insert at (starting from 1): ");
    scanf("%d", &pos);
    if (pos == 1) {
        temp->next = head;
        head = temp;
        return head;
    }
    sn *ptr = head;
    while (i < pos - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
    } else {
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}

sn* insertAfterNode(sn *head) {
    int key;
    printf("Enter the element after which to insert: ");
    scanf("%d", &key);
    sn *ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Node with element %d not found\n", key);
        return head;
    }
    sn *temp = (sn*)malloc(sizeof(sn));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &temp->data);
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

sn* insertBeforeNode(sn *head) {
    int key;
    printf("Enter the element before which to insert: ");
    scanf("%d", &key);
    if (head == NULL || head->data == key) {
        return insertAtBeg(head);
    }
    sn *ptr = head;
    while (ptr->next != NULL && ptr->next->data != key) {
        ptr = ptr->next;
    }
    if (ptr->next == NULL) {
        printf("Node with element %d not found\n", key);
        return head;
    }
    sn *temp = (sn*)malloc(sizeof(sn));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &temp->data);
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

sn* insertAtParticularNode(sn *head) {
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos == 1) {
        return insertAtBeg(head);
    }
    return insertAtMiddle(head);
}

int main() {
    sn *head = NULL;
    int choice;
    char ch;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Display\n");
        printf("4. Insert at Middle\n");
        printf("5. Insert After Node\n");
        printf("6. Insert Before Node\n");
        printf("7. Insert at Particular Node\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = insertAtBeg(head);
                break;
            case 2:
                head = insertAtLast(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head = insertAtMiddle(head);
                break;
            case 5:
                head = insertAfterNode(head);
                break;
            case 6:
                head = insertBeforeNode(head);
                break;
            case 7:
                head = insertAtParticularNode(head);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}

