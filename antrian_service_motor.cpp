#include <iostream>
#define MAX 5
 
using namespace std;
 
    string nama,pass;
struct Antrian {
    int head,tail,data[MAX];
    string motor[MAX];
}Queue;

int isFull(){
    return Queue.tail==MAX;
}
int isEmpty(){
    return Queue.tail==0;
}
void reset(){
    Queue.head=Queue.tail=0;
    cout<<"\n\t Antrian Clear ";
}
void show(){
    if(isEmpty()){
        cout<<" \tAntriannya Kosong"<<endl;
    }else{
        cout<<"\n\t Daftar Antrian : \n";
        for(int i=Queue.head; i<Queue.tail;i++)
        cout<<"\t|"<<Queue.motor[i]<<"|\n"; 
    }
}

void Masuk(){
    if(isFull()){
        cout<<"\t Antrian Penuh"<<endl;
    }else{
        cout<<"\n\t Masukkan Nomor Plat Motor Anda  :";cin>>Queue.motor[Queue.tail];
        cout<<"\n\t Kode Antrian  :"<<Queue.motor[Queue.tail]<<" Masuk Antrian"<<endl;
        Queue.tail++;
    }
}
void pop(){
    if(isEmpty()){
        cout<<"\t Antrian kosong"<<endl;
    }else{
        cout<<"\n\t Antrian :"<<Queue.motor[Queue.head]<<" Silahkan"<<endl;
        for(int i=Queue.head; i<Queue.tail;i++)
        Queue.motor[i]=Queue.motor[i+1];
        Queue.tail--;
    }
}

void login(){
    
    cout<<" \t Username"<<endl;
    cin>>nama;
    cout<<"\t Password"<<endl;
    cin>>pass;


    if(nama=="admin"){
        if(pass == "admin"){
            cout<<"\t Login success"<<endl;
        }
    }else if(nama!="admin"){
        if(pass!="admin"){
        cout<<"\t Login gagal !"<<endl;
        
        login();
        }
    }else if(pass!="admin"){
        if(nama!="admin"){
        cout<<"\t Login gagal !"<<endl;
        }
    }
}

void checkLogin(){
    if(nama=="admin"){
        if(pass == "admin"){
            cout<<"\t login success"<<endl;
        }
    }else if(nama!="admin"){
        if(pass!="admin"){
        cout<<"\t Login gagal !"<<endl;
        
        login();
        }
    }else if(pass!="admin"){
        if(nama!="admin"){
        cout<<"\t Login gagal !"<<endl;
        login();
        }
    }
}

void user(){
    int pilih;
    do{
        cout<<"\t Menu User \n"<<endl;
        cout<<"\t 1. Antri"<<endl;
        cout<<"\t 2. List Antrian"<<endl;
        cout<<"\t 3. Keluar"<<endl;
        cout<<"\t Pilih Aksi :";cin>>pilih;
        switch(pilih){
            case 1:
            Masuk();
            break;
            
            case 2:
            show();
            break;
            
            case 3:
            cout<<"\n\t terima kasih \n";
            break;
        };
    }while(pilih!=3);
}

void admin(){
    int choose;
    login();
    checkLogin();
    do{
        cout<<"\t Menu Admin"<<endl;
        cout<<"\t 1. Pop Data"<<endl;
        cout<<"\t 2. Show List Antrian"<<endl;
        cout<<"\t 3. Clear Antrian"<<endl;
        cout<<"\t 4. Exit \n"<<endl;
        cout<<"\t Pilih Aksi :";cin>>choose;

        switch(choose){
            case 1:
            pop();
            break;
            case 2:
            show();
            break;

            case 3:
            reset();
            break;
            case 4:
            cout<<"TQ"<<endl;
        }
    }while(choose!=4);
}

int main(){
    int menu;
    do{
        cout<<"\t Main Menu Service Motor \n "<<endl;
        cout<<"\t 1. User Menu"<<endl;
        cout<<"\t 2. Admin Menu"<<endl;
        cout<<"\t 3. Exit Program \n"<<endl;
        cout<<"Menu yang dipilih    : ";cin>>menu;

        switch (menu)
        {
        case 1:
            user();
            break;
        case 2:
        admin();
        break;
        case3:
        cout<<"Terima Kasih"<<endl;
        }
    }while(menu!=3);
}