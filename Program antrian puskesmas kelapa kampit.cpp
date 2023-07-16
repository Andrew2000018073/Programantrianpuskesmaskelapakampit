#include<iostream>
#include<fstream>
#define max 8
#include<stdlib.h>
using namespace std;

struct poliumum{
	string nama;
	string karkes;
	string ttl;
	string alamat;
	string pekerjaan;
	string status;
	int kategori;
	};

class puskes{
	public:
		bool isfull();
		bool isempty();
		enqueue(string, string, string, string, string, string , int);
		penqueue(string, string, int);
		home();
		pasien();
		cetak();
		int repeat();
		simpan();
		dequeue();
		int ambilprioritas();
		string ambildata();
		string ambilsimpan();
	private:
		int nomor=0;
		int Mendesak =50 ;
		int Disabilitas=40;
		int Anak=30;
		int Ibu=20;
		int Umum=10;
		string Simpan[max];
		string Pasien[max];
		int prio[max];
		int rear=0;
		int front=0;
};

bool puskes::isempty(){
	if(rear == 0){
		return true;
	}
	else return false;
}

puskes::dequeue(){
	if(isempty()){
		cout<<"Antrian masih kosong"<<endl;
	}
	else{
		for (int i = 0; i < rear - 1; i++) {
                Pasien[i] = Pasien[i + 1];
                prio[i]=prio[i+1];
                Simpan[i]=Simpan[i+1];
            }
        rear-- ;
	}
}

bool puskes::isfull(){
	if(rear == max){
		return true;
	}
	else return false;
}

int puskes::ambilprioritas(){
	return prio[front];
}

string puskes::ambildata(){
	return Pasien[front];
}

string puskes::ambilsimpan(){
	return Simpan[front];
}

puskes::simpan(){
	system("cls");
	ofstream outfill;
	outfill.open("Datapasien.csv",ios::app);
	if(Simpan[nomor]=="0"){
		nomor++;
		cout<<"Silahkan panggil fungsi sekali lagi"<<endl;
	}
	if(!outfill.fail()){
		outfill<<Simpan[nomor]<<endl;
		nomor++;
		outfill.close();
		cout<<"Data berhasil disimpan";
	}else{
		cout<<endl<<"Tidak dapat menyimpan data"<<endl;
	}
	
}

puskes::cetak(){
	cout<<"\t\tnama\t\tkarkes\t\talamat\t\tttl\t\tpekerjaan\t\tstatus"<<endl;
	for(int i= front; i<rear; i++){
		cout<<Pasien[i]<<endl;
	}
}

puskes::pasien(){
	system("cls");
	struct poliumum pasien;
	cin.ignore();
	cout<<"\tNama \t\t: "; getline(cin, pasien.nama);
	cout<<"\tKartu kesehatan\t: "; getline(cin, pasien.karkes);
	cout<<"\tAlamat \t\t:"; getline(cin, pasien.alamat);
	cout<<"\tTempat tanggal lahir\t:"; getline(cin, pasien.ttl);
	cout<<"\tPekerjaan\t\t:"; getline(cin, pasien.pekerjaan);
	cout<<"\tStatus\t\t:"; getline(cin, pasien.status);
	cin.ignore();
	cout<<"\tKategori pasien"<<endl<<"\t1.Mendesak"<<endl<<"\t2.Disabilitas"<<endl<<"\t3.Anak-anak"<<endl<<"\t4.Ibu Hamil"<<endl<<"\t5.Umum"<<endl;
	cout<<"\tKategori\t:"; cin>>pasien.kategori;
	if(pasien.kategori == 1){
		enqueue(pasien.nama, pasien.karkes, pasien.alamat, pasien.ttl, pasien.pekerjaan, pasien.status , Mendesak);
		Mendesak--;
	}
	else if(pasien.kategori == 2){
		enqueue(pasien.nama, pasien.karkes, pasien.alamat, pasien.ttl, pasien.pekerjaan, pasien.status , Disabilitas);
		Disabilitas--;
	}
	else if(pasien.kategori == 3 ){
		enqueue(pasien.nama, pasien.karkes, pasien.alamat, pasien.ttl, pasien.pekerjaan, pasien.status , Anak);
		Anak--;
	}
	else if(pasien.kategori == 4){
		enqueue(pasien.nama, pasien.karkes, pasien.alamat, pasien.ttl, pasien.pekerjaan, pasien.status , Ibu);
		Ibu--;
	}
	else if(pasien.kategori==5){
		enqueue(pasien.nama, pasien.karkes, pasien.alamat, pasien.ttl, pasien.pekerjaan, pasien.status , Umum);
		Umum--;
	}
	else{
		cout<<"Anda memasukan inputan yang salah pada kategori";
	}
	
}

puskes::enqueue(string nama, string karkes, string alamat, string ttl, string pekerjaan, string status , int kategori){
	if(isfull())cout<<"Antrian penuh"<<endl;
	else{
		if(isempty()){
			Pasien[0]="\t\t"+nama+"\t\t"+karkes+"\t\t"+alamat+"\t\t"+ttl+"\t\t"+pekerjaan+"\t\t"+status;
			Simpan[0]=nama+";"+karkes+";"+alamat+";"+ttl+";"+pekerjaan+";"+status;
			prio[0]=kategori;
			rear++;
		}
		else{
			int tempat = 0;
			while (prio[tempat]>kategori){tempat++;}
			if(rear!=tempat)
			for(int i=rear-1; i>=tempat; i--){
			prio[i+1]= prio[i];
			Pasien[i+1]= Pasien[i];	
			Simpan[i+1]= Simpan[i];
			}
			
			
			prio[tempat]=kategori;
			Pasien[tempat]= "\t\t"+nama+"\t\t"+karkes+"\t\t"+alamat+"\t\t"+ttl+"\t\t"+pekerjaan+"\t\t"+status;
			Simpan[tempat]=nama+";"+karkes+";"+alamat+";"+ttl+";"+pekerjaan+";"+status;
			rear++;	
		}
	}
}

puskes::penqueue(string data, string simpan, int kategori){
	if(isfull())cout<<"Antrian penuh"<<endl;
	else{
		if(isempty()){
			Pasien[0]=data;
			Simpan[0]=simpan;
			prio[0]=kategori;
			rear++;
		}
		else{
			int tempat = 0;
			while (prio[tempat]>kategori){tempat++;}
			if(rear!=tempat)
			for(int i=rear-1; i>=tempat; i--){
			prio[i+1]= prio[i];
			Pasien[i+1]= Pasien[i];	
			Simpan[i+1]= Simpan[i];
			}
			
			
			prio[tempat]=kategori;
			Pasien[tempat]= data;
			Simpan[tempat]=simpan;
			rear++;	
		}
	}
}

main(){
	string ambil;
	int prio;
	string simpan;
	puskes x;
	puskes z;
	home :
	system("cls");
	cout<<"\t---------------------------------------------"<<endl;
	cout<<"\t---------PUSKESMAS KELAPA KAMPIT-------------"<<endl;
	cout<<"\t---------------------------------------------"<<endl;
	char c;
	cout<<"\t1. Masukan antrian"<<endl;
	cout<<"\t2. Hapus antrian"<<endl;
	cout<<"\t3. Tampilkan antrian"<<endl;
	cout<<"\t4. Simpan ke file"<<endl;
	cout<<"\t5. Pisah antrian"<<endl;
	cout<<"\t6. Tampilkan antrian yang telah dipisah "<<endl;
	cout<<"\t7. Hapus antrian yang telah dipisah "<<endl;
	cout<<"\tMasukan input sesuai dengan nomor: ";cin>>c;
	switch(c){
		case'1':
			x.pasien();
			break;
		case'2':
			x.dequeue();
			break;
		case'3':
			x.cetak();
			break;
		case'4':
			x.simpan();
			break;
		case'5':
			prio = x.ambilprioritas();
			ambil = x.ambildata();
			simpan = x.ambilsimpan();
			x.dequeue();
			z.penqueue(ambil,simpan,prio);
			break;
		case'6':
			z.cetak();
			break;
		case'7':
			z.dequeue();
			break;
		default:
			cout<<"\tAnda memasukan inputan yang salah";
	}
	char y;
	cout<<"\tKembali kepada home(y/n): ";cin>>y;
	switch(y){
		case 'y':
			goto home;
			break;
		case 'Y':
			goto home;
			break;
		case'n':
			return 0;
		case'N':
			return 0;
	}
}
