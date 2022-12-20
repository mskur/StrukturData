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
