/*PROGRAM BINER_DESIMAL*/
// Konversi biner ke desimal dan sebaliknya
#include<stdio.h>
#include<math.h>

int DesimalBiner(int A[]);
int BinerDesimal(int A[]);


main()
{
	/*DEKLARASI*/
	int pilih, a, n, i, A[100], hasil;											//n, i, m pencacah & A[] array, input nilai, penentu posisi
	char opsi;																	//variabel mengulang program

	/*DESKRIPSI*/
	do
	{
		do
		{
			system("cls");														//membersihkan layar
			a=0;																//sebagai syarat program
			printf("PROGRAM Biner dan Decimal\n");								//judul program
			printf("\nMenu : ");
			printf("\n1 : Konversi decimal ke biner");
			printf("\n2 : Konversi biner ke decimal");
			printf("\nPilihan : "); scanf("%i", &pilih);						//masukkan untuk pilih case
			
			switch (pilih)
			{
				case 1 :
					DesimalBiner(A);											//pemanggilan fungsi DesimalBiner(A)
					break;
				case 2 :
					hasil=BinerDesimal(A);										//pemanggilan fungsi BinerDesimal(A) dengan disimpan di variabel hasil 
					if(a==-1)
					{
						printf("Masukkan Anda Salah");
					}
					else
					{
						printf("Hasil : %i", hasil);								//menampilkan hasil 
					}
					break;
				default :
					printf("\nMasukkan Anda Salah");							//peringatan
					a=1;														//syarat mengulang program (Error)
					break;	
			}
		}
		while(a==1);															//kondisi terpenuhi akan mengulang
		
		printf("\n\nUlangi[Y/T]? "); scanf("%s", &opsi);
	}
	while(opsi=='Y'||opsi=='y');												//'y' jika ingin mengulang program
}
	
	
int DesimalBiner(int A[])														//fungsi DesimalBiner(int A[])
{
	/*DEKLARASI*/
	int n, i, batas;															//n masukan, i pencacah, batas syarat inputan
	
	/*DESKRIPSI*/
	printf("\n\n>> 1 Konversi decimal ke biner");
	printf("\n\nMasukkan bilangan decimal? ");
	scanf("%i", &n);															//masukkan nilai
	i=0;
	while (n>0)																//untuk mengisi nilai
	{
		if(n%2==1)
		{
			A[i]=1;
		}
		else
		{
			A[i]=0;
		}
		n=div(n,2);
		i++;
		batas=i;
	}
	
	for(i=batas-1; i>=0; i--) 												//for untuk menampilkan biner
	{
		printf("%i", A[i]);													//penampilan biner
	}
}

int BinerDesimal(int A[])														//fungsi BinerDesimal(int A[])
{
	/*DEKLARASI*/
	int n, sisa, hasil = 0, pangkat=0;											//n masukkan, sisa untuk menyimpan sisa pembagian, hasil untuk total, pangkat untuk pengalinya
	
	/*DESKRIPSI*/
	printf("\n\n>> 2 Konversi biner ke decimal");
	printf("\n\nMasukkan bilangan biner? ");
	scanf("%i", &n);
	
	while(n>0)																	//akan berhenti jika n telah kurang dari sama dengan 0
	{
		sisa=n%2;																//rumus Biner
		hasil=hasil+sisa*pow(2,pangkat);
		n=div(n,10);
		pangkat++;
	}
	return hasil;																//mengembalikan nilai hasil
}
