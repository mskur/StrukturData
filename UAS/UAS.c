#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAX 5

struct nodeKhitan{
    int nomorAntrian;
    int idKhitan;
    int usiaPeserta;
    char namaPeserta[50];
    char alamatPeserta[50];
    char jenisKhitan[50];

    struct nodeKhitan *next;
};
typedef struct nodeKhitan nodeKhitan;

struct queueKhitan{
    int count;
    nodeKhitan *front;
    nodeKhitan *rear;
};
typedef struct queueKhitan queueKhitan;

//================================================================================================
queueKhitan createQueueKhitan(void);
nodeKhitan *createNode(void);
int ambilAntrianKhitan(queueKhitan *myQueue, int nomorAntrian);
int panggilAntrianKhitan(queueKhitan *myQueue, int idKhitan, nodeKhitan **pHead);
void tampilkanAntrianKhitan(queueKhitan myQueue);
int destroyQueueKhitan(queueKhitan *myQueue);
void tampilkanDataPesertaKhitan(nodeKhitan *pHead);


int main(){
    int nomorAntrian = 0, idKhitan = 1000;
    char pilihMenu;

    queueKhitan myQueue;
    myQueue = createQueueKhitan();
    nodeKhitan *pHead = NULL;

    do{
        fflush(stdin);
        system("cls");
        printf("====== PROGRAM ANTRIAN KHITAN DENGAN DATA PESERTA KHITAN =====\n\n");
        printf("1. Ambil Antrian Khitan\n");
        printf("2. Panggil Antrian Khitan\n");
        printf("3. Tampilkan Antrian Khitan\n");
        printf("4. Hapus Semua Antrian Khitan\n");
        printf("5. Tampilkan Data Peserta Khitan\n");
        printf("q. Keluar\n");
        printf("\nPilih Menu : ");
        scanf("%c", &pilihMenu);

        switch(pilihMenu){
            case '1':
                nomorAntrian = ambilAntrianKhitan(&myQueue, nomorAntrian);
                break;

            case '2':
                idKhitan = panggilAntrianKhitan(&myQueue, idKhitan, &pHead);
                break;

            case '3':
                tampilkanAntrianKhitan(myQueue);
                break;

            case '4':
                nomorAntrian = destroyQueueKhitan(&myQueue);
                break;

            case '5':
                tampilkanDataPesertaKhitan(pHead);
                break;

            case 'q':
                printf("Terima Kasih Telah Menggunakan Program Ini\n");
                break;

            default:
                printf("Pilihan Menu Tidak Tersedia\n");
                getch();
                break;
        }
    } while(pilihMenu != 'q');
}


//================================================================================================

queueKhitan createQueueKhitan(void){
    queueKhitan myQueue;
    myQueue.count = 0;
    myQueue.front = NULL;
    myQueue.rear = NULL;
    return myQueue;
}

//================================================================================================

nodeKhitan *createNode(void){
    nodeKhitan *newNode = (nodeKhitan* )malloc(sizeof(nodeKhitan));
    return newNode;
}

//================================================================================================
