#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//CIRCULAR LINKED LIST

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void addMiddle(node **pList);
void traverse(node *pList);
void deleteMiddle(node **pList);
void sumAll(node *pList);
void testCircular(node *pList);

int main(){
    char selectMenu;
    node *list;
    list = NULL;
    do{
        system("cls");
        printf("Nama : Imam Maskuri\n");
        printf("NPM  : 20081010074\n\n");
        printf("CIRCULAR LINKED LIST \n\n");
        printf("1. Add data << in the middle of the list >>\n");
        printf("2. Delete data << in the middle of the list >>\n");
        printf("3. Sum all data <<node traversal>>\n");
        printf("4. Show all data <<node traversal>>\n");
        printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
        fflush(stdin);
        scanf("%c", &selectMenu);

        if (selectMenu == '1')
            addMiddle(&list);
        else if (selectMenu == '2')
            deleteMiddle(&list);
        else if (selectMenu == '3')
            sumAll(list);
        else if (selectMenu == '4'){
            system("cls");
            traverse(list);
            getch();
        }
        else if (selectMenu == '5'){
            testCircular(list);
            getch();
        }
    } while(selectMenu != 'q');
    return 0;
}

//====================================================================================

void addMiddle(node **pList){
    int data_number, insert_after;

    node *newNode;
    node *temp;
    node *pCur;
    system("cls");

    newNode = (node *)malloc(sizeof(node));

    if(newNode != NULL){
        printf("Please Enter Integer Number : ");
        fflush(stdin);
        scanf("%d", &data_number);
        printf("\n");

        newNode->data = data_number;
        if(*pList == NULL){
            *pList = newNode;
            newNode->next = newNode;
        }
        else{
            traverse(*pList);
            printf("\n\nINSERT DATA AFTER NUMBER? : ");
            fflush(stdin);
            scanf("%d", &insert_after);
        
            temp = *pList;
            while(temp->next != *pList){
                if(temp->data == insert_after){
                    pCur = temp->next;
                    temp->next = newNode;
                    newNode->next = pCur;
                    return;
                }
                temp = temp->next;
            }
                
            if(temp->data == insert_after){
                pCur = temp->next;
                temp->next = newNode;
                newNode->next = pCur;
                return;
            }
            printf("\nDATA NOT FOUND!");
            getch();
        }
    }
    else{
        printf("Memory Allocation Failed!");
        getch();
    }
}

//====================================================================================

void deleteMiddle(node **pList){
    int data_target;
    node *pDel, *pCur, *pPre;
    system("cls");

    if(*pList == NULL){
        printf("LIST IS EMPTY!");
        getch();
    }
    else{
        traverse(*pList);
        printf("\n\nDELETE DATA NUMBER? : ");
        fflush(stdin);
        scanf("%d", &data_target);

        pDel = *pList;

        if(pDel->next == *pList && pDel->data == data_target){
            *pList = NULL;
            free(pDel);
        }
        else if(pDel->data == data_target){
            pCur = pDel->next;
            while(pCur->next != *pList){
                pCur = pCur->next;
            }
            *pList = pDel->next;
            pCur->next = *pList;
            free(pDel);
        }
        else{
            pPre = pDel;
            pDel = pDel->next;
            while(pDel->next != *pList){
                if(pDel->data == data_target){
                    pPre->next = pDel->next;
                    free(pDel);
                    return;
                }
                pPre = pDel;
                pDel = pDel->next;
            }
            if(pDel->data == data_target){
                pPre->next = pDel->next;
                free(pDel);
                return;
            }
            printf("\nDATA NOT FOUND!");
            getch();
        }
    }
}

//====================================================================================

void sumAll(node *pList){
    int sum = 0;
    node *temp;

    if(pList == NULL){
        printf("\nLIST IS EMPTY");
        getch();
        return;
    }

    temp = pList;
    while(temp->next != pList){
        sum += temp->data;
        temp = temp->next;
    }
    sum += temp->data;
    printf("\nSUM OF ALL DATA : %d", sum);
    getch();
}

//====================================================================================

void traverse(node *pList){
    node *pWalker;

    pWalker = pList;
    if(pList != NULL){
        while(pWalker->next != pList){
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->next;
        }
        printf("%d -> ", pWalker->data);
    }
    printf("NULL");
}

void testCircular(node *pList){
    node *pWalker;
    int i = 0;

    system("cls");
    pWalker = pList;
    if(pList != NULL){
        while(i < 15){
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->next;
            i++;
        }
    }
    printf("NULL");
}