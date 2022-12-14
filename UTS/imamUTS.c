#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//CIRCULAR LINKED LIST
struct nodeMahasiswa{
    char namaMhs[100];
    char jenisKelamin[1];
    struct nodeMahasiswa *next;
};
typedef struct nodeMahasiswa nodeMahasiswa;

void addMidMahasiswa(nodeMahasiswa **pList);
void deleteMahasiswa(nodeMahasiswa **pList);
void traverseMahasiswa(nodeMahasiswa *pList);
void traverseMhsPria(nodeMahasiswa *pList);
void traverseMhsWanita(nodeMahasiswa *pList);

int main(){
    char selectMenu;
    nodeMahasiswa *listMahasiswa;
    listMahasiswa = NULL;
    do{
        system("cls");
        printf("Nama  : Imam Maskuri\n");
        printf("NPM   : 20081010074\n");
        printf("Kelas : Struktur Data A \n\n");
        printf("CIRCULAR LINKED LIST \n");
        printf("DEFAULT NAMA CINDY ADALAH 'Cindy' MOHON SAMAKAN BESAR KECILNYA \n\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus Mahasiswa\n");
        printf("3. Tampilkan Mahasiswa\n");
        printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
        fflush(stdin);
        scanf("%c", &selectMenu);

        if(selectMenu == '1'){
            fflush(stdin);
            addMidMahasiswa(&listMahasiswa);
        }
        else if(selectMenu == '2'){
            fflush(stdin);
            deleteMahasiswa(&listMahasiswa);
        }
        else if(selectMenu == '3'){
            fflush(stdin);
            system("cls");
            printf("DATA YANG AKAN DILIHAT");
            printf("\n1. Semua Data");
            printf("\n2. Data Pria");
            printf("\n3. Data Wanita");
            printf("\nMasukkan pilihan : ");
            scanf("%c", &selectMenu);
            if(selectMenu == '1'){
                traverseMahasiswa(listMahasiswa);
                getch();
            }
            else if(selectMenu == '2'){
                traverseMhsPria(listMahasiswa);
                getch();
            }
            else if(selectMenu == '3'){
                traverseMhsWanita(listMahasiswa);
                getch();
            }
        }
    }while (selectMenu != 'q');
}

//======================================================================================================

void addMidMahasiswa(nodeMahasiswa **pList){
    nodeMahasiswa *pNew, *pTemp, *pCur, *pWalker, *pWalker2;
    char insert_after[100];

    pNew = (nodeMahasiswa *)malloc(sizeof(nodeMahasiswa));

    system("cls");
    printf("===== INPUT DATA MAHASISWA =====\n\n");
    printf("Masukkan nama : ");
    fflush(stdin);
    gets(pNew->namaMhs);
    printf("Jenis Kelamin (P/L) : ");
    fflush(stdin);
    gets(pNew->jenisKelamin);

    if(*pList == NULL){
        *pList = pNew;
        pNew->next = pNew;
    }
    else{
        fflush(stdin);
        printf("\n");
        traverseMahasiswa(*pList);
        printf("\n\nMasukkan nama baru setelah nama : ");
        fflush(stdin);
        gets(insert_after);

        fflush(stdin);
        pTemp = *pList;
        while(pTemp->next != *pList){
            if(strcmp(pTemp->namaMhs, insert_after) == 0){
                if((strcmp(pNew->namaMhs, "Cindy") == 0) && (strcmp(pTemp->jenisKelamin, "L") == 0)){
                    printf("Cindy tidak mau bersebelahan dengan pria");
                    getch();
                    return;
                }
                else if((strcmp(pNew->namaMhs, "Cindy") == 0) && (strcmp(pTemp->next->jenisKelamin, "L") == 0)){
                    printf("Cindy tidak mau bersebelahan dengan pria");
                    getch();
                    return;
                }
                else if((strcmp(pTemp->next->namaMhs, "Cindy") == 0) && (strcmp(pNew->jenisKelamin, "L") == 0)){
                    printf("Data pria tidak boleh bersebelahan dengan Cindy!");
                    getch();
                    return;
                }
                else if((strcmp(pNew->jenisKelamin, "L") == 0 ) && (strcmp(pTemp->namaMhs, "Cindy") == 0)){
                    printf("Data pria tidak boleh bersebelahan dengan Cindy!");
                    getch();
                    return;
                }
                else{
                    pCur = pTemp->next;
                    pTemp->next = pNew;
                    pNew->next = pCur;
                    return;
                }
            }
            pTemp = pTemp->next;
        }

        if(strcmp(pTemp->namaMhs, insert_after) == 0){
            if((strcmp(pNew->namaMhs, "Cindy") == 0) && (strcmp(pTemp->jenisKelamin, "L") == 0)){
                printf("Cindy tidak mau bersebelahan dengan pria");
                getch();
                return;
            }
            else if((strcmp(pNew->namaMhs, "Cindy") == 0) && (strcmp(pTemp->next->jenisKelamin, "L") == 0)){
                printf("Cindy tidak mau bersebelahan dengan pria");
                getch();
                return;
            }
            else if((strcmp(pTemp->next->namaMhs, "Cindy") == 0) && (strcmp(pNew->jenisKelamin, "L") == 0)){
                printf("Data pria tidak boleh bersebelahan dengan Cindy!");
                getch();
                return;
            }
            else if((strcmp(pNew->jenisKelamin, "L") == 0 ) && (strcmp(pTemp->namaMhs, "Cindy") == 0)){
                printf("Data pria tidak boleh bersebelahan dengan Cindy!");
                getch();
                return;
            }
            else{
                pCur = pTemp->next;
                pTemp->next = pNew;
                pNew->next = pCur;
                return;
            }
        }
        printf("Data tidak ditemukan");
        getch();
    }
}

//======================================================================================================

void deleteMahasiswa(nodeMahasiswa **pList){
    char nama_target[100];
    nodeMahasiswa *pDel, *pCur, *pPre;
    system("cls");

    if (*pList == NULL){
        printf("Data kosong");
        getch();
    }
    else{
        printf("===== DELETE DATA MAHASISWA =====\n\n");
        traverseMahasiswa(*pList);
        printf("\nMasukkan nama yang akan dihapus : ");
        fflush(stdin);
        gets(nama_target);

        pDel = *pList;

        if(pDel->next == *pList && (strcmp(pDel->namaMhs, nama_target) == 0)){
            *pList = NULL;
            free(pDel);
        }
        else if(strcmp(pDel->namaMhs, nama_target) == 0){
            pCur = pDel->next;
            while(pCur->next != *pList){
                pCur = pCur->next;
            }
            *pList = pDel->next;
            pCur->next = *pList;
            free(pDel);

            if((strcmp(pCur->jenisKelamin, "L") == 0) && (strcmp(pCur->next->namaMhs, "Cindy") == 0)){
                pDel = pCur->next;
                pCur->next = pDel->next;
                *pList = pCur->next;
                free(pDel);
                printf("Cindy tidak mau bersebelahan dengan pria maka Cindy dihapus");
                getch();
                return;
            }
        }
        else{
            pPre = pDel;
            pDel = pDel->next;
            while(pDel->next != *pList){
                if(strcmp(pDel->namaMhs, nama_target) == 0){
                    pPre->next = pDel->next;
                    free(pDel);
                    if((strcmp(pPre->jenisKelamin, "L") == 0) && (strcmp(pPre->next->namaMhs, "Cindy") == 0)){
                        pDel = pPre->next;
                        pPre->next = pDel->next;
                        free(pDel);
                        printf("Cindy tidak mau bersebelahan dengan pria maka Cindy dihapus");
                        getch();
                        return;
                    }
                    else if(strcmp(pPre->namaMhs, "Cindy") == 0 && strcmp(pPre->next->jenisKelamin, "L") == 0){
                        //GET DATA BEFORE CINDY
                        pDel = *pList;
                        pPre = pDel;
                        pDel = pDel->next;
                        while(strcmp(pDel->namaMhs, "Cindy") != 0){
                            if(strcmp(pDel->namaMhs, "Cindy") == 0){
                                pPre->next = pDel->next;
                                free(pDel);
                                return;
                            }
                            pPre = pDel;
                            pDel = pDel->next;
                        }
                        pPre->next = pDel->next;
                        free(pDel);
                        printf("Cindy tidak mau bersebelahan dengan pria maka Cindy dihapus");
                        getch();
                        return;
                    }
                    else{
                        return;
                    }
                }
                pPre = pDel;
                pDel = pDel->next;
            }
            if(strcmp(pDel->namaMhs, nama_target) == 0){
                pPre->next = pDel->next;
                free(pDel);
                if((strcmp(pPre->jenisKelamin, "L") == 0) && (strcmp(pPre->next->namaMhs, "Cindy") == 0)){
                    pDel = pPre->next;
                    pPre->next = pDel->next;
                    free(pDel);
                    printf("Cindy tidak mau bersebelahan dengan pria maka Cindy dihapus");
                    getch();
                    return;
                }
                else if(strcmp(pPre->namaMhs, "Cindy") == 0 && strcmp(pPre->next->jenisKelamin, "L") == 0){
                    pDel = *pList;
                    pPre = pDel;
                    pDel = pDel->next;
                    while(strcmp(pDel->namaMhs, "Cindy") != 0){
                        if(strcmp(pDel->namaMhs, "Cindy") == 0){
                            pPre->next = pDel->next;
                            free(pDel);
                            return;
                        }
                        pPre = pDel;
                        pDel = pDel->next;
                    }
                    pPre->next = pDel->next;
                    free(pDel);
                    printf("Cindy tidak mau bersebelahan dengan pria maka Cindy dihapus");
                    getch();
                    return;
                }
                else{
                    return;
                }
            }
            printf("Data tidak ditemukan");
            getch();
        }
    }
}

//======================================================================================================

void traverseMahasiswa(nodeMahasiswa *pList){
    nodeMahasiswa *pWalker;

    system("cls");
    printf("===== TRAVERSE SEMUA DATA MAHASISWA =====\n\n");

    pWalker = pList;
    if(pList != NULL){
        while(pWalker->next != pList){
            printf("%s -> ", pWalker->namaMhs);
            pWalker = pWalker->next;
        }
        printf("%s -> ", pWalker->namaMhs);
    }
    printf("NULL");
}

//======================================================================================================

void traverseMhsPria(nodeMahasiswa *pList){
    nodeMahasiswa *pWalker;

    system("cls");
    printf("===== DATA MAHASISWA PRIA =====\n\n");

    pWalker = pList;
    if(pList != NULL){
        while(pWalker->next != pList){
            if(strcmp(pWalker->jenisKelamin, "L") == 0){
                printf("%s -> ", pWalker->namaMhs);
            }
            pWalker = pWalker->next;
        }
        if(strcmp(pWalker->jenisKelamin, "L") == 0){
            printf("%s -> ", pWalker->namaMhs);
        }
    }
    printf("NULL");
}

//======================================================================================================

void traverseMhsWanita(nodeMahasiswa *pList){
    nodeMahasiswa *pWalker;

    system("cls");
    printf("===== DATA MAHASISWA WANITA =====\n\n");

    pWalker = pList;
    if(pList != NULL){
        while(pWalker->next != pList){
            if(strcmp(pWalker->jenisKelamin, "P") == 0){
                printf("%s -> ", pWalker->namaMhs);
            }
            pWalker = pWalker->next;
        }
        if(strcmp(pWalker->jenisKelamin, "P") == 0){
            printf("%s -> ", pWalker->namaMhs);
        }
    }
    printf("NULL");
}