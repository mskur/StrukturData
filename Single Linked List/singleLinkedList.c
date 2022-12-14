//load the library that use in application
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//*******************************************
//structure of the node
//node contains data and 'pointer next'
struct node {
	//data
	int data;
	//pointer next
    struct node *next;
};
//make an alias for 'struct node' to -> 'node'
typedef struct node node;

//*******************************************

//list of function
//register name function
void addFront(node **head);
void addLast(node **head);
void addMiddle(node **head);
void traverse(node *head);
void deleteMiddle(node **head);
void deleteFront(node **head);
void deleteLast(node **head);
void sumAll(node *head);


//********************************************
//THE MAIN PROGRAM

int main()
{
  //menu option
  char selectMenu;
  
  //initialize *Head of linked list
  node *head;
  head = NULL;
  
  //loop the app menu with do-while
  do{
    
    //clear screen terminal/cmd
    //use system("clear"); for linux systems
    system("cls");
    
    //app menu 
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
	printf("8. Show all data <<node traversal>>\n\n");
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
  } while (selectMenu != 'q');
  
}

//========================================================

void addFront(node **pHead){
  int data_number;
  node *pNew;

  system("cls");
  fflush(stdin); //for clean/flush mememory buffer before input process
  
  //input process
  printf("Please Enter Integer Number : ");
  fflush(stdin);
  scanf("%d", &data_number);
  
  //create node with memory allocation - malloc -
  //it make the apps more dynamic
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){ // if null -> cannot get memory slot in RAM/computer memory
  		//assign data to new node
		pNew->data = data_number;
		//add node to linked list
		pNew->next = *pHead;
		*pHead = pNew;
  }
  else{
      printf("ERR: NOT ENOUGH MEMORY");
      getch();
  }
}

//========================================================

void addLast(node **pHead){
  int data_number;
  node *pNew, *pTemp;

  system("cls");
  fflush(stdin); //for clean/flush mememory buffer before input process
  
  //input process
  printf("Please Enter Integer Number : ");
  fflush(stdin);
  scanf("%d", &data_number);
  
  //create node with memory allocation - malloc -
  //it make the apps more dynamic
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){ // if null -> cannot get memory slot in RAM/computer memory
  		//assign data to new node
    pNew->data = data_number;
    //add node to linked list
    pNew->next = NULL;
    
    //if linked list is empty
    if (*pHead == NULL){
      *pHead = pNew;
    }
    else{
      //traverse to the last node
      pTemp = *pHead;
      while (pTemp->next != NULL){
        pTemp = pTemp->next;
      }
      //add new node to the last node
      pTemp->next = pNew;
    }
  }
  else{
      printf("ERR: NOT ENOUGH MEMORY");
      getch();
  }
}

//========================================================

void addMiddle(node **head){
  int insert_after, data_number;
  node *pNew, *pCur;

  system("cls");
  
  //call Tranverse Function
  //to get data snapshot
  traverse(*head);
  
  printf("\n\nINSERT DATA AFTER NUMBER? : ");
  fflush(stdin);
  scanf("%d", &insert_after);
  printf("\nNEW DATA : ");
  fflush(stdin);
  scanf("%d", &data_number);

  //initialize pointer current (pCur)
  //pCur job is find target data
  pCur = *head;
  
  //search data
  while (pCur != NULL && pCur -> data != insert_after) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
  	//check if data found or not
     printf("\nDATA NOT FOUND");
     getch();
  }
  else if (pNew == NULL){
  	//check if memory alocation request is succes
     printf("\nERR: NOT ENOUGH MEMORY!");
     getch();
  }
  else{
  	
  	//assignment data to new node
     pNew->data = data_number;
    
    //insert new node to linked list
    pNew->next = pCur->next;
    pCur->next = pNew;
  }
}

//========================================================

void deleteFront(node **pHead){
  node *pTemp, *pCur;

  system("cls");
  pCur = *pHead;
  
  //check if linked list is empty
  if (*pHead == NULL){
    printf("ERR: LINKED LIST IS EMPTY");
    getch();
  }
  else if(pCur->next == NULL){
    free(pCur);
    *pHead = NULL;
  }
  else{
    //delete first node
    pTemp = *pHead;
    *pHead = pTemp->next;
    free(pTemp);
  }
}

//========================================================

void deleteLast(node **pHead){
  node *pTemp, *pCur;

  system("cls");
  pCur = *pHead;
  //check if linked list is empty
  if (*pHead == NULL){
    printf("ERR: LINKED LIST IS EMPTY");
    getch();
  }
  else if(pCur->next == NULL){
    free(pCur);
    *pHead = NULL;
  }
  else{
    //delete last node
    while (pCur->next != NULL){
      pTemp = pCur;
      pCur = pCur->next;
    }
    pTemp->next = NULL;
    free(pCur);
  }
}

//========================================================

void deleteMiddle(node **head)
{
  int data_target;
  node *pCur, *pPre;

  system("cls");
  
  //call Traverse Function
  traverse(*head);
  printf("\nDATA THAT WILL BE DELETED ? : ");
  fflush(stdin);
  scanf("%d", &data_target);

  pPre = NULL;
  pCur = *head;
  
  //searching data target
  while (pCur != NULL && pCur -> data != data_target) {
    pPre = pCur;
    pCur = pCur -> next;
  }

  if (pCur == NULL){
     printf("\nDATA NOT FOUND !");
     getch();
  }
  else
    if(pCur == *head){
      *head = pCur->next;
      free(pCur);
    }
    else{
      pPre->next = pCur->next;
      free(pCur);
    }
}

//========================================================

void traverse(node *head){
   //traverse linked list
	node *pWalker;

    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d->", pWalker -> data);
   	pWalker = pWalker -> next;
	}
   printf("NULL");
}

//========================================================

void sumAll(node *head){
  int sum = 0;
  node *pWalker;

  system("cls");
  pWalker = head;
  while (pWalker != NULL){
    sum += pWalker -> data;
    pWalker = pWalker -> next;
  }
  printf("SUM OF ALL DATA : %d", sum);
  getch();
}