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

int ambilAntrianKhitan(queueKhitan *myQueue, int nomorAntrian){
    system("cls");
    printf("======= AMBIL ANTRIAN KHITAN =======\n\n");
    if(myQueue->count == MAX){
        printf("Antrian Penuh Datang Lagi Besok\n");
    } 
    else {
        nomorAntrian++;
        nodeKhitan *newNode = createNode();
        newNode->nomorAntrian = nomorAntrian;

        fflush(stdin);
        printf("Masukkan Nama Peserta : ");
        gets(newNode->namaPeserta);
        printf("Nomor Antrian Anda : %d\n", newNode->nomorAntrian);
        newNode->next = NULL;

        if(myQueue->front == NULL){
            myQueue->front = newNode;
        } 
        else {
            myQueue->rear->next = newNode;
        }
        myQueue->rear = newNode;
        myQueue->count++;
        printf("\nAntrian Berhasil Dibuat\n");
    }
    getch();
    return nomorAntrian;
}

//================================================================================================

int panggilAntrianKhitan(queueKhitan *myQueue, int idKhitan, nodeKhitan **pHead){
    system("cls");
    int jenisKhitan;

    printf("======= PANGGIL ANTRIAN KHITAN =======\n\n");
    if(myQueue->count == 0){
        printf("Antrian Kosong\n");
    } 
    else {
        nodeKhitan *delAntrian = myQueue->front;
        myQueue->front = myQueue->front->next;
        myQueue->count--;
        printf("Antrian %d Telah Dipanggil\n", delAntrian->nomorAntrian);
        printf("Nama Peserta : %s\n", delAntrian->namaPeserta);

        //INSERT DATA PESERTA KHITAN TO LINKED LIST
        idKhitan++;
        nodeKhitan *newNode = createNode();
        newNode->idKhitan = idKhitan;
        strcpy(newNode->namaPeserta, delAntrian->namaPeserta);

        printf("\n\n======= DATA PESERTA KHITAN =======\n\n");
        printf("Masukkan Usia Peserta : ");
        scanf("%d", &newNode->usiaPeserta);
        printf("Alamat Peserta        : ");
        fflush(stdin);
        gets(newNode->alamatPeserta);

        do{
            printf("\n== Masukkan Jenis Khitan ==\n");
            printf("1. Khitan Laser\n");
            printf("2. Khitan Gunting\n");
            printf("3. Khitan Bambu\n");
            printf("Pilih Jenis Khitan    : ");
            scanf("%d", &jenisKhitan);
            if(jenisKhitan == 1){
                strcpy(newNode->jenisKhitan, "Khitan Laser");
            }
            else if(jenisKhitan == 2){
                strcpy(newNode->jenisKhitan, "Khitan Gunting");
            }
            else if(jenisKhitan == 3){
                strcpy(newNode->jenisKhitan, "Khitan Bambu");
            }
            else {
                printf("Jenis Khitan Tidak Tersedia\n");
            }
        } while(jenisKhitan < 1 || jenisKhitan > 3);

        newNode->next = NULL;
        if(*pHead == NULL){
            *pHead = newNode;
        } 
        else {
            nodeKhitan *pWalker = *pHead;
            while(pWalker->next != NULL){
                pWalker = pWalker->next;
            }
            pWalker->next = newNode;
        }

        free(delAntrian);
        printf("\nData Peserta Khitan Berhasil Ditambahkan\n");
    }
    getch();
    return idKhitan;
}

//================================================================================================

int destroyQueueKhitan(queueKhitan *myQueue){
    nodeKhitan *pWalker = myQueue->front;
    while(pWalker != NULL){
        nodeKhitan *temp = pWalker;
        pWalker = pWalker->next;
        free(temp);
    }
    myQueue->front = NULL;
    myQueue->rear = NULL;
    myQueue->count = 0;
    system("cls");
    printf("======= HAPUS ANTRIAN KHITAN =======\n\n");
    printf("Antrian Berhasil Dihapus\n");
    getch();
    return 0;
}

//================================================================================================
void tampilkanAntrianKhitan(queueKhitan myQueue){
    system("cls");
    printf("======= TAMPILKAN ANTRIAN KHITAN =======\n\n");

    if(myQueue.count == 0){
        printf("Antrian Kosong\n");
    } 
    else {
        nodeKhitan *pWalker = myQueue.front;

        while(pWalker != NULL){
            printf("%d -> %s\n", pWalker->nomorAntrian, pWalker->namaPeserta);
            pWalker = pWalker->next;
        }
    }
    getch();
}

//================================================================================================

void tampilkanDataPesertaKhitan(nodeKhitan *pHead){
    system("cls");
    printf("======= TAMPILKAN DATA PESERTA KHITAN =======\n\n");

    if(pHead == NULL){
        printf("Data Peserta Khitan Kosong\n");
    } 
    else {
        nodeKhitan *pWalker = pHead;

        while(pWalker != NULL){
            printf("ID Khitan          : %d\n", pWalker->idKhitan);
            printf("Nama Peserta       : %s\n", pWalker->namaPeserta);
            printf("Usia Peserta       : %d\n", pWalker->usiaPeserta);
            printf("Alamat Peserta     : %s\n", pWalker->alamatPeserta);
            printf("Jenis Khitan       : %s\n", pWalker->jenisKhitan);
            printf("============================================\n");
            pWalker = pWalker->next;
        }
    }
    getch();
}
