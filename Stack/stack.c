#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 5

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

struct stack
{   
    int count;
    struct node *top;
};
typedef struct stack stack;

stack createStack(void);
node *createNode(int);
int push(int data, stack *head);
int stackTop(stack head);
void display(stack head);
int pop(stack *head);
int numberOfElements(stack head);
int searchElement(int data, stack head);
void destroyStack(stack *head);
int sumAllElements(stack head);
int isStackEmpty(stack head);
int isStackFull(stack head);

int main(void){
    char choice;
    int num, success;
    stack head;
    head = createStack();

    do{
        system("cls");
        printf("Nama : Imam Maskuri\n");
        printf("NPM  : 20081010074\n");
        printf("\n-----STACK MENU-----\n");
        printf("\n1. Push Element");
        printf("\n2. Top Element");
        printf("\n3. Display Stack");
        printf("\n4. Pop Element");
        printf("\n5. Count of Stack");
        printf("\n6. Search Element");
        printf("\n7. Destroy Stack");
        printf("\n8. Sum all Element");
        printf("\n9. is Stack Empty");
        printf("\n0. is Stack Full");
        printf("\n\nEnter your choice: ");
        scanf("%c",&choice);

        switch(choice){
            case '1':
                system("cls");
                printf("===== PUSH ELEMENT =====\n");
                printf("\nEnter the number to be pushed: ");
                scanf("%d", &num);

                if(isStackFull(head) == 1){
                    printf("\nStack is full. Cannot push element.");
                }
                else{
                    success = push(num, &head);
                    if(success){
                        printf("\nElement pushed successfully.");
                    }
                    else{
                        printf("\nElement could not be pushed.");
                    }
                }
                getch();
                break;
                
            case '2':
                if(isStackEmpty(head) == 1){
                    printf("\nStack is empty. Cannot display top element.");
                }
                else{
                    num = stackTop(head);
                    printf("\nTop element of stack is: %d", num);
                }
                getch();
                break;

            case '3':
                if(isStackEmpty(head) == 1){
                    printf("\nStack is empty. Cannot display elements.");
                    getch();
                }
                else{
                    printf("\n===== DISPLAY STACK =====\n");
                    display(head);
                    getch();
                }
                break;
            
            case '4':
                if(isStackEmpty(head) == 1){
                    printf("\nStack is empty. Cannot pop element.");
                    getch();
                }
                else{
                    num = pop(&head);
                    if(num != -1){
                        printf("\nElement %d popped successfully.", num);
                    }
                    else{
                        printf("\nElement could not be popped.");
                    }
                }
                getch();
                break;

            case '5':
                num = numberOfElements(head);
                printf("\nCount of elements in stack is: %d", num);
                getch();
                break;

            case '6':
                if(isStackEmpty(head) == 1){
                    printf("\nStack is empty. Cannot search element.");
                }
                else{
                    printf("\nEnter the element to be searched: ");
                    scanf("%d", &num);
                    success = searchElement(num, head);
                    if(success){
                        printf("\nElement found in position %d", success);
                    }
                    else{
                        printf("\nElement not found in stack.");
                    }
                }
                getch();
                break;
            
            case '7':
                destroyStack(&head);
                printf("\nStack destroyed");
                getch();
                break;

            case '8':
                if(isStackEmpty(head) == 1){
                    printf("\nStack is empty. Cannot sum elements.");
                }
                else{
                    num = sumAllElements(head);
                    printf("\nSum of all elements in stack is: %d", num);
                }
                getch();
                break;
            
            case '9':
                success = isStackEmpty(head);
                if(success == 1){
                    printf("\nStack is EMPTY");
                }
                else{
                    printf("\nStack is NOT EMPTY");
                }
                getch();
                break;

            case '0':
                success = isStackFull(head);
                if(success == 1){
                    printf("\nStack is FULL");
                }
                else{
                    printf("\nStack is NOT FULL");
                }
                getch();
                break;

        }
    } while(choice != 'q');
}

//===============================================================================================

node *createNode(int data){
    node *newPtr;
    newPtr = (node *)malloc(sizeof(node));
    return (newPtr);
}

//===============================================================================================


stack createStack(void){
    stack head;
    head.count = 0;
    head.top = NULL;
    return head;
}

//===============================================================================================


int push(int data, stack *head){
    node *newPtr;
    int success;
    newPtr = (node *)malloc(sizeof(node));

    newPtr->data = data;
    newPtr->next = head->top;
    head->top = newPtr;
    head->count = head->count + 1;
    success = 1;
    return(success);
}

//===============================================================================================


int stackTop(stack head){
    int atas;
    atas = head.top->data;
    return (atas);
}

//===============================================================================================

void display(stack head){
    system("cls");
    node *temp;
    temp = head.top;
    printf("stack element(s) from top to bottom : \n");

    printf("\n\t+---+ top");

    if(head.count==0){
        printf("\n\tNULL\n");
    }
    else{
        while(temp){
            printf("\n\t| %d |", temp->data);
            temp = temp->next;
        }
    }

    printf("\n\t+---+ bottom");
}

//===============================================================================================

int numberOfElements(stack head){
    int count;
    count = head.count;
    return (count);
}

//===============================================================================================


int pop(stack *head){
    node *temp;
    int num;
    if(head->top == NULL){
        return -1;
    }
    else{
        temp = head->top;
        num = temp->data;
        head->top = temp->next;
        free(temp);
        head->count = head->count - 1;
        return(num);
    }
}

//===============================================================================================

int searchElement(int data, stack head){
    node *temp;
    int pos = 1;
    temp = head.top;
    while(temp){
        if(temp->data == data){
            return pos;
        }
        else{
            temp = temp->next;
            pos++;
        }
    }
    return 0;
}

//===============================================================================================

void destroyStack(stack *head){
    node *temp;
    while(head->top){
        temp = head->top;
        head->top = temp->next;
        free(temp);
    }
    head->count = 0;
}

//===============================================================================================

int sumAllElements(stack head){
    node *temp;
    int sum = 0;
    temp = head.top;
    while(temp){
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

//===============================================================================================

int isStackEmpty(stack head){
    if(head.top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//===============================================================================================

int isStackFull(stack head){
    if (head.count == MAX){
        return 1;
    }
    else{
        return 0;
    }
}
