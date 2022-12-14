#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 5

//=========================================================

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

//=========================================================

struct queue{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

//=========================================================

queue createQueue(void);
int enqueue(int data, queue *myQueue);
node *createNode(void);
void dequeue(queue *myQueue);
int queueFront(queue myQueue);
int queueRear(queue myQueue);
int queueCount(queue myQueue);
void emptyQueue(queue *myQueue);
void displayQueue(queue myQueue);

//=========================================================

int main(){
    int choice, num, success;
    queue myQueue;

    myQueue = createQueue();

    do{
        system("cls");
        printf("Nama : Imam Maskuri \n");
        printf("NPM  : 20081010074 \n\n");
        printf("=========== QUEUE ===========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Queue Front\n");
        printf("4. Queue Rear\n");
        printf("5. Queue Count\n");
        printf("6. Destroy\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                printf("======= ENQUEUE INPUT =======\n\n");
                printf("Enter Number : ");
                scanf("%d", &num);
                success = enqueue(num, &myQueue);
                if(success == 1){
                    printf("Enqueue Success!\n");
                }else{
                    printf("Enqueue Failed!\n");
                }
                getch();
                break;

            case 2:
                system("cls");
                printf("======= DEQUEUE =======\n\n");
                dequeue(&myQueue);
                break;

            case 3:
                system("cls");
                printf("======= QUEUE FRONT =======\n\n");
                num = queueFront(myQueue);
                if(num != -1){
                    printf("Queue Front : %d\n", num);
                }
                getch();
                break;

            case 4:
                system("cls");
                printf("======= QUEUE REAR =======\n\n");
                num = queueRear(myQueue);
                if(num != -1){
                    printf("Queue Rear : %d\n", num);
                }
                getch();
                break;

            case 5:
                system("cls");
                printf("======= QUEUE COUNT =======\n\n");
                num = queueCount(myQueue);
                printf("Queue Count : %d\n", num);
                getch();
                break;

            case 6:
                system("cls");
                printf("======= DESTROY QUEUE =======\n\n");
                emptyQueue(&myQueue);
                printf("Queue Destroyed!\n");
                getch();
                break;

            case 7:
                system("cls");
                displayQueue(myQueue);
                getch();
                break;

            case 8:
                printf("Thank You!\n");
                getch();
                break;

            default:
                printf("Invalid Choice!\n");
                getch();
        }


    }while(choice != 8);

    
}

//=========================================================

queue createQueue(void){
    queue myQueue;
    myQueue.count = 0;
    myQueue.front = NULL;
    myQueue.rear = NULL;
    return myQueue;
}

//=========================================================

int enqueue(int data, queue *myQueue){
    int success = 0;
    if(myQueue->count >= MAX){
        printf("Queue is full!\n");
        getch();
    }
    else{
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        if(myQueue->front == NULL){
            myQueue->front = newNode;
        }
        else{
            myQueue->rear->next = newNode;
        }
        myQueue->rear = newNode;
        myQueue->count++;
        success = 1;
    }
    return success;
}

//=========================================================

node *createNode(void){
    node *newNode = (node*)malloc(sizeof(node));
    return newNode;
}

//=========================================================

void dequeue(queue *myQueue){
    int dequeue;

    if(myQueue->count == 0){
        printf("Queue is empty cannot dequeue!\n");
    }
    else{
        node *deletePtr = myQueue->front;
        dequeue = deletePtr->data;
        myQueue->front = myQueue->front->next;
        free(deletePtr);
        myQueue->count--;
        printf("Element %d is dequeued!\n", dequeue);
    }
    getch();
}

//=========================================================

int queueFront(queue myQueue){
    int front = -1;
    if(myQueue.count == 0){
        printf("Queue is empty!\n");
    }
    else{
        front = myQueue.front->data;
    }
    return front;
}

//=========================================================

int queueRear(queue myQueue){
    int rear = -1;
    if(myQueue.count == 0){
        printf("Queue is empty!\n");
    }
    else{
        rear = myQueue.rear->data;
    }
    return rear;
}

//=========================================================

int queueCount(queue myQueue){
    return myQueue.count;
}

//=========================================================

void emptyQueue(queue *myQueue){
    node *deletePtr;

    while(myQueue->count != 0){
        deletePtr = myQueue->front;
        myQueue->front = myQueue->front->next;
        free(deletePtr);
        myQueue->count--;
    }
    myQueue->front = NULL;
    myQueue->rear = NULL;
    myQueue->count = 0;
}

//=========================================================

void displayQueue(queue myQueue){
    node *temp = myQueue.front;

    printf("====== Queue Elements ======\n\n");
    if(myQueue.count == 0){
        printf("Queue is empty cannot display!");
    }
    else{
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}