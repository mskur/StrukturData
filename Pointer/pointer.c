#include<stdio.h>
#include<stdlib.h>

int main(){
    //TRANSACTION WITH POINTER
    double saldoAndi = 500000;
    double *ptrSaldoAndi = &saldoAndi;
    int pilih; 
    double transferDana, tarikSaldo, depositSaldo, noRekTujuan;

    do{
        system("cls");
        printf("Nama : Imam Maskuri \n");
        printf("NPM : 20081010074 \n\n");


        printf("Menu BANK ANDI \n");
        printf("1. Cek Saldo \n");
        printf("2. Transfer Dana \n");
        printf("3. Tarik Dana \n");
        printf("4. Deposit Dana \n");
        printf("5. Keluar \n");
        printf("Pilih Menu : ");
        scanf("%d", &pilih);

        switch(pilih){
            case 1:
                printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                system("pause");
                break;

            case 2:
                printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                printf("Masukkan Nomor Rekening Tujuan : ");
                scanf("%lf", &noRekTujuan);
                double *ptrRekTujuan = &noRekTujuan; 

                printf("Masukkan Jumlah Transfer : Rp");
                scanf("%lf", &transferDana);
                double *ptrTransfer = &transferDana;
                
                if(*ptrSaldoAndi < *ptrTransfer){
                    printf("Saldo Andi Tidak Mencukupi \n");
                    system("pause");
                }
                else{
                    *ptrSaldoAndi -= *ptrTransfer;
                    printf("Transfer Berhasil Sejumlah : Rp%.lf ke nomor rekening : %.lf \n", *ptrTransfer, *ptrRekTujuan);
                    printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                    system("pause");
                }
                break;
            
            case 3:
                printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                printf("Masukkan Jumlah Penarikan : Rp");
                scanf("%lf", &tarikSaldo);
                double *ptrTarikSaldo = &tarikSaldo;
                
                if(*ptrSaldoAndi < *ptrTarikSaldo){
                    printf("Saldo Andi Tidak Mencukupi \n");
                    system("pause");
                }
                else{
                    *ptrSaldoAndi -= *ptrTarikSaldo;
                    printf("Saldo Berhasil Ditarik : Rp%.lf \n", *ptrTarikSaldo); 
                    printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                    system("pause");
                }
                break;

            case 4:
                printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                printf("Masukkan Jumlah Deposit : Rp");
                scanf("%lf", &depositSaldo);
                double *ptrDepositSaldo = &depositSaldo;
                *ptrSaldoAndi += *ptrDepositSaldo;
                printf("Saldo Berhasil Ditambahkan : Rp%.lf \n", *ptrDepositSaldo);
                printf("Saldo Andi : Rp%.lf \n", *ptrSaldoAndi);
                system("pause");
                break;
            
            case 5:
                printf("Terimakasih Telah Menggunakan Layanan Kami \n");
                return 0;

            default:
                printf("Pilihan Anda Salah! \n");
                system("pause");
                break;
        }

    }while(pilih != 0);
    
}