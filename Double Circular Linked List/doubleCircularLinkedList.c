#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//CIRCULAR DOUBLY LINKED LIST
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

void insertAtFirst(node **pHead);
void insertAtLast(node **pHead);
void insertAtMiddle(node **pHead);
void deleteAtFirst(node **pHead);
void deleteAtLast(node **pHead);
void deleteAtMiddle(node **pHead);
void sumAllData(node *pHead);
void traverse(node *pHead);
void traverseReverse(node *pHead);


int main(){
    char selectMenu;
    node *head;
    head = NULL;

    do{
        system("cls");
        printf("Nama : Imam Maskuri\n");
        printf("NPM  : 20081010074\n\n");
        printf("LINKED LIST DEMO - CODE SKELETON: \n\n");
        printf("1. Add data << in beginning of the list >>\n");
        printf("2. Add data << in the end of the list >>\n");
        printf("3. Add data << in the middle of the list >>\n");
        printf("4. Delete data << in beginning of the list >>\n");
        printf("5. Delete data << in the end of the list >>\n");
        printf("6. Delete data << in the middle of the list >>\n");
        printf("7. Sum all data <<node traversal>>\n");
        printf("8. Show all data <<node traversal>>\n");
        printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
        fflush(stdin);
        scanf("%c", &selectMenu);

        if (selectMenu == '1')
            insertAtFirst(&head);
        else if (selectMenu == '2')
            insertAtLast(&head);
        else if (selectMenu == '3')
            insertAtMiddle(&head);
        else if (selectMenu == '4')
            deleteAtFirst(&head);
        else if (selectMenu == '5')
            deleteAtLast(&head);
        else if (selectMenu == '6')
            deleteAtMiddle(&head);
        else if (selectMenu == '7')
            sumAllData(head);
        else if (selectMenu == '8'){
            traverse(head);
            getch();
        }
        else if (selectMenu == '9'){
            traverseReverse(head);
            getch();
        }
    } while(selectMenu != 'q');
    return 0;
}


//====================================================================================

void insertAtFirst(node **pHead){
    node *newNode;
    int data_number;

    system("cls");
    printf("Please Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);

    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL){
        printf("Memory Allocation Failed!");
        getch();
        return;
    }
    else{
        newNode->data = data_number;
        if (*pHead == NULL){
            newNode->next = newNode;
            newNode->prev = newNode;
            *pHead = newNode;
        }
        else{
            newNode->next = *pHead;
            newNode->prev = (*pHead)->prev;
            (*pHead)->prev->next = newNode;
            (*pHead)->prev = newNode;
            *pHead = newNode;
        }
    }
}

//====================================================================================

void insertAtLast(node **pHead){
    node *newNode, *temp;
    int data_number;

    system("cls");
    printf("Please Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);

    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL){
        printf("Memory Allocation Failed!");
        getch();
        return;
    }
    else{
        newNode->data = data_number;
        if (*pHead == NULL){
            newNode->next = newNode;
            newNode->prev = newNode;
            *pHead = newNode;
        }
        else{
            newNode->next = *pHead;
            newNode->prev = (*pHead)->prev;
            (*pHead)->prev->next = newNode;
            (*pHead)->prev = newNode;
        }
    }
}

//====================================================================================

void insertAtMiddle(node **pHead){
    node *newNode, *temp;
    int data_number, insert_after;

    if(*pHead == NULL){
        printf("\nList is Empty!");
        getch();
        return;
    }

    system("cls");
    traverse(*pHead);
    printf("\n\nPlease Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);

    printf("Insert After Number? : ");
    fflush(stdin);
    scanf("%d", &insert_after);

    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL){
        printf("Memory Allocation Failed!");
        getch();
        return;
    }
    else{
        newNode->data = data_number;
        if (*pHead == NULL){
            newNode->next = newNode;
            newNode->prev = newNode;
            *pHead = newNode;
        }
        else{
            temp = *pHead;
            while(temp->data != insert_after){
                temp = temp->next;
                if (temp == *pHead){
                    printf("Data Not Found!");
                    getch();
                    return;
                }
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
}

//====================================================================================

void deleteAtFirst(node **pHead){
    node *pDel;

    if (*pHead == NULL){
        printf("\nList is Empty!");
        getch();
        return;
    }
    else{
        pDel = *pHead;
        if (pDel->next == pDel){
            *pHead = NULL;
            free(pDel);
        }
        else{
            pDel->prev->next = pDel->next;
            pDel->next->prev = pDel->prev;
            *pHead = pDel->next;
            free(pDel);
        }
    }
}

//====================================================================================

void deleteAtLast(node **pHead){
    node *pDel, *temp;

    if (*pHead == NULL){
        printf("\nList is Empty!");
        getch();
        return;
    }
    else{
        pDel = *pHead;
        if (pDel->next == pDel){
            *pHead = NULL;
            free(pDel);
        }
        else{
            temp = pDel->prev;
            temp->prev->next = pDel;
            pDel->prev = temp->prev;
            free(temp);
        }
    }
}

//====================================================================================

void deleteAtMiddle(node **pHead){
    node *pDel, *temp;
    int delete_number;

    if (*pHead == NULL){
        printf("\nList is Empty!");
        getch();
        return;
    }

    system("cls");
    traverse(*pHead);
    printf("\n\nDelete Number? : ");
    fflush(stdin);
    scanf("%d", &delete_number);

    pDel = *pHead;
    if (pDel->next == pDel && pDel->data == delete_number){
        *pHead = NULL;
        free(pDel);
    }
    else if(pDel->data == delete_number){
        pDel->prev->next = pDel->next;
        pDel->next->prev = pDel->prev;
        *pHead = pDel->next;
        free(pDel);
    }
    else{
        while(pDel->data != delete_number){
            pDel = pDel->next;
            if (pDel == *pHead){
                printf("Data Not Found!");
                getch();
                return;
            }
        }
        pDel->prev->next = pDel->next;
        pDel->next->prev = pDel->prev;
        free(pDel);
    }
}

//====================================================================================

void sumAllData(node *pHead){
    node *pCur;
    int sum = 0;

    if (pHead == NULL){
        printf("\nList is Empty!");
        getch();
        return;
    }
    else{
        pCur = pHead;
        do{
            sum += pCur->data;
            pCur = pCur->next;
        } while(pCur != pHead);
        printf("\nSum of All Data is %d", sum);
        getch();
    }
}

//====================================================================================

void traverse(node *pHead){
    node *temp;
    temp = pHead;
    system("cls");

    if (temp == NULL){
        printf("NULL");
    }
    else{
        while(temp->next != pHead){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> ", temp->data);
        printf("NULL");
    }
}

//====================================================================================

void traverseReverse(node *pHead){
    node *temp;
    temp = pHead;
    system("cls");

    if (temp == NULL){
        printf("NULL");
    }
    else{
        while(temp->prev != pHead){
            printf("%d -> ", temp->data);
            temp = temp->prev;
        }
        printf("%d -> ", temp->data);
        printf("NULL");
    }
}

