#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list{
	int nim;
	char nama[255];
	float ipk;
	struct list *Next;
}LIST;

LIST *Head, *Baru;

void inisialisasi(){
	//Head = new LIST; //cara pertama tanpa malloc
	Head = (LIST*)malloc(sizeof(LIST)); //(cara kedua tapi harus memakai stdlib.h
	Head->Next = NULL;
}


void inputDepan(int NIM, char NAMA[255], float IPK){
		Baru = (LIST*)malloc(sizeof(LIST));
		Baru->nim = NIM;
		strcpy(Baru->nama, NAMA);
		Baru->ipk = IPK;
		Baru->Next = NULL;
	
	if(Head->Next == NULL)	{ // sisip simpul pertama kali
		Head->Next = Baru;
	}else { // sisip depan
		Baru->Next = Head->Next;
		Head->Next = Baru;
	}
}

void inputBelakang(int NIM, char NAMA[255], float IPK){
		Baru = (LIST*)malloc(sizeof(LIST));
		Baru->nim = NIM;
		strcpy(Baru->nama, NAMA);
		Baru->ipk = IPK;
		Baru->Next = NULL;
	
	if(Head->Next == NULL)	{ // sisip simpul pertama kali
		Head->Next = Baru;
	}else { // sisip belakang
		LIST *pNow = Head->Next;
		while(pNow->Next != NULL){
			pNow = pNow->Next;
		}
		pNow->Next = Baru;
	}	
		
}

void inputTengah(int NIM, char NAMA[255], float IPK){
	
}

void tampil(){
	if(Head->Next == NULL)	{ // sisip simpul pertama kali
		printf("Data Kosonh\n");
	}else { // sisip belakang
		LIST *pNow = Head->Next;
		while(pNow->Next != NULL){
			printf("%d %s %.2F", pNow->nim, pNow->nama, pNow->ipk);
			pNow = pNow->Next;
		}
		
	}	
}


int main(){
	int menu;
	int nim;
	char nama[255];
	float ipk;
	
	inisialisasi();
	
	do{
		printf("1. Input Depan\n");
		printf("2. Input Belakang\n");
		printf("3. Input Tengah\n");
		printf("9. Tampil Data \n");
		printf("Pilih Menu : "); scanf("%d", &menu);
		switch(menu){
			case 1:{
				printf("Masukan NIM = "); scanf("%d", &nim);
				printf("Masukan Nama = "); scanf("%s", &nama);
				printf("Masukan IPK = "); scanf("%f", &ipk);
				inputDepan(nim,nama,ipk);
				break;
			}
			case 2:{
				printf("Masukan NIM = "); scanf("%d", &nim);
				printf("Masukan Nama = "); scanf("%s", &nama);
				printf("Masukan IPK = "); scanf("%f", &ipk);
				inputBelakang(nim,nama,ipk);
				break;
			}
			case 3:{
				
				break;
			}
			case 9:{
				
				break;
			}
			case 0:{
				printf("Keluar dari aplikasi \n");
				break;
			}
		}
	}while(menu != 0);
	
	return 0;
}
