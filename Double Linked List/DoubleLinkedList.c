#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

void addFront(node **head);
void addLast(node **head);
void addMiddle(node **head);
void traverse(node *head);
void traverse2(node *head);
void deleteFront(node **head);
void deleteLast(node **head);
void deleteMiddle(node **head);
void sumAll(node *head);

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
        printf("9. Show all data from tail to head\n\n");
        printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
        fflush(stdin);
        scanf("%c", &selectMenu);

        if (selectMenu == '1')
            addFront(&head);
        else if (selectMenu == '2')
            addLast(&head);
        else if (selectMenu == '3')
            addMiddle(&head);
        else if (selectMenu == '4')
            deleteFront(&head);
        else if (selectMenu == '5')
            deleteLast(&head);
        else if (selectMenu == '6')
            deleteMiddle(&head);
        else if (selectMenu == '7')
            sumAll(head);
        else if (selectMenu == '8'){
            traverse(head);
            getch();
        }
        else if (selectMenu == '9'){
            traverse2(head);
            getch();
        }
} while(selectMenu != 'q');
    return 0;
}

void addFront(node **pHead){
    int data_number;
    node *newNode;
    
    system("cls");
    printf("Please Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);
    
    newNode = (node *)malloc(sizeof(node));
    
    if(newNode != NULL){
        newNode->data = data_number;
        if(*pHead == NULL){
            newNode->left = NULL;
            newNode->right = NULL;
            *pHead = newNode;
        } 
        else {
            newNode->left = NULL;
            newNode->right = *pHead;
            (*pHead)->left = newNode;
            *pHead = newNode;
        }
    } 
    else {
        printf("Memory Allocation Failed");
        getch();
    }
}

//==========================================================================
void addLast(node **pHead){
    int data_number;
    node *newNode;
    node *temp;
    
    system("cls");
    printf("Please Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);
    
    newNode = (node *)malloc(sizeof(node));
    
    if(newNode != NULL){
        newNode->data = data_number;
        if(*pHead == NULL){
            newNode->left = NULL;
            newNode->right = NULL;
            *pHead = newNode;
        } else {
            temp = *pHead;
            while(temp->right != NULL){
                temp = temp->right;
            }
            temp->right = newNode;
            newNode->left = temp;
            newNode->right = NULL;
        }
    }
    else {
        printf("Memory Allocation Failed");
        getch();
    }
}

//==========================================================================

void addMiddle(node **pHead){
    int data_number, insert_after;

    node *newNode;
    node *temp;
    node *pCur;
    
    if(*pHead == NULL){
        printf("\nLIST IS EMPTY");
        getch();
        return;
    }

    system("cls");
    traverse(*pHead);
    printf("\n\nINSERT DATA AFTER NUMBER? : ");
    fflush(stdin);
    scanf("%d", &insert_after);
    printf("Please Enter Integer Number : ");
    fflush(stdin);
    scanf("%d", &data_number);
    
    newNode = (node *)malloc(sizeof(node));
    
    pCur = *pHead;
    while(pCur != NULL && pCur->data != insert_after){
        pCur = pCur->right;
    }

    if(pCur == NULL){
        printf("\nDATA NOT FOUND");
        getch();
    }
    else if(newNode == NULL){
        printf("\nMEMORY ALLOCATION FAILED");
        getch();
    }
    else {
        newNode->data = data_number;
        //if insert after the last node
        if(pCur->right == NULL){
            pCur->right = newNode;
            newNode->left = pCur;
            newNode->right = NULL;
        }
        else {
            newNode->left = pCur;
            newNode->right = pCur->right;
            pCur->right->left = newNode;
            pCur->right = newNode;
        }
    }
}

//==========================================================================

void deleteFront(node **pHead){
    node *pDel;

    if(*pHead == NULL){
        printf("LIST IS EMPTY");
        getch();
    }
    else if((*pHead)->right == NULL){
        pDel = *pHead;
        *pHead = NULL;
        free(pDel);
    }
    else {
        pDel = *pHead;
        *pHead = pDel->right;
        (*pHead)->left = NULL;
        free(pDel);
    }
}

//==========================================================================

void deleteLast(node **pHead){
    node *pDel;
    node *pCur;

    if(*pHead == NULL){
        printf("LIST IS EMPTY");
        getch();
    }
    else if((*pHead)->right == NULL){
        pDel = *pHead;
        *pHead = NULL;
        free(pDel);
    }
    else {
        pDel = *pHead;
        while(pDel->right != NULL){
            pCur = pDel;
            pDel = pDel->right;
        }
        pCur->right = NULL;
        free(pDel);
    }
}

//==========================================================================

void deleteMiddle(node **pHead){
    int delete_number;
    node *pDel;
    node *pCur;

    if(*pHead == NULL){
        printf("\nLIST IS EMPTY");
        getch();
        return;
    }

    system("cls");
    traverse(*pHead);
    printf("\n\nDELETE NUMBER? : ");
    fflush(stdin);
    scanf("%d", &delete_number);

    pDel = *pHead;
    while(pDel != NULL && pDel->data != delete_number){
        pCur = pDel;
        pDel = pDel->right;
    }

    if(pDel == NULL){
        printf("\nDATA NOT FOUND");
        getch();
    }
    else if(pDel->right == NULL && pDel->left == NULL){
        *pHead = NULL;
        free(pDel);
    }
    else if(pDel == *pHead){
        *pHead = pDel->right;
        (*pHead)->left = NULL;
        free(pDel);
    }
    else {
        //if delete the last node
        if(pDel->right == NULL){
            pCur->right = NULL;
            free(pDel);
        }
        else {
            pCur->right = pDel->right;
            pDel->right->left = pCur;
            free(pDel);
        }
    }
}

//==========================================================================

void sumAll(node *pHead){
    int sum = 0;
    node *pCur;

    pCur = pHead;
    while(pCur != NULL){
        sum += pCur->data;
        pCur = pCur->right;
    }
    printf("SUM OF ALL DATA : %d", sum);
    getch();
}

//==========================================================================

void traverse(node *head){
    node *pWalker;
    pWalker = head;

    system("cls");
    while(pWalker != NULL){
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->right;
    }
    printf("NULL");
}

//==========================================================================

void traverse2(node *head){
    node *pCur, *pTail;
    system("cls");

    if(head == NULL){
        printf("NULL");
        return;
    }

    pCur = head;
    while(pCur != NULL){
        pTail = pCur;
        pCur = pCur->right;
    }

    printf("NULL <- ");
    while(pTail != NULL){
        if(pTail->left == NULL){
            printf("%d", pTail->data);
        }
        else {
            printf("%d <- ", pTail->data);
        }
        pTail = pTail->left;
    }
}