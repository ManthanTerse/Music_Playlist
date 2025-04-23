#include <stdio.h>
#include <stdlib.h>

struct node {
    char data[15];
    struct node *next;
};

struct node *newnode, *temp, *head = 0;

void create() {
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Song Name: ");
        scanf("%s", newnode->data);
        newnode->next = 0;

        if (head == 0) {
            head = temp = newnode;
            newnode -> next = head;
        } else {
            temp->next = newnode;
            newnode -> next = head;
            temp = newnode;
        }
        
        printf("Do you want to continue (0/1)? : ");
        scanf("%d", &choice);
    }
}

void display() {
    if (head == 0) {
        printf("List is empty\n");
        return;
    } else {
        temp = head;
        printf("Playlist:\n");
    do {
        printf("%s -> ", temp->data);
        temp = temp->next;
    } 
    while (temp != head);
    printf("(back to start)\n");
    }
}


void insert() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Song Name to be Inserted: ");
    scanf("%s", newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void del_pos() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    

    temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
    } else {
        struct node *prev = 0;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    int ch;
    while (1) {
        printf("1. Create\t2.Insert\t3.Delete\t4.Display\t5.Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                del_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}