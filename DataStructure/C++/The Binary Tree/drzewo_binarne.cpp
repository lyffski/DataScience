#include <iostream>
#include <windows.h>
using namespace std;


int choose;
int *root;

void gotoxy(int x, int y){
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int data[16];
bool empty[16];


void show_tree(){ // copied from website 
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    gotoxy(40,1); if (empty[1]==true) cout<<"_"; else cout<<data[1];
    gotoxy(20,4); if (empty[2]==true) cout<<"_"; else cout<<data[2];
    gotoxy(60,4); if (empty[3]==true) cout<<"_"; else cout<<data[3];
    gotoxy(10,6); if (empty[4]==true) cout<<"_"; else cout<<data[4];
    gotoxy(30,6); if (empty[5]==true) cout<<"_"; else cout<<data[5];
    gotoxy(50,6); if (empty[6]==true) cout<<"_"; else cout<<data[6];
    gotoxy(70,6); if (empty[7]==true) cout<<"_"; else cout<<data[7];
    gotoxy(5,10); if (empty[8]==true) cout<<"_"; else cout<<data[8];
    gotoxy(15,10); if (empty[9]==true) cout<<"_"; else cout<<data[9];
    gotoxy(25,10); if (empty[10]==true) cout<<"_"; else cout<<data[10];
    gotoxy(35,10); if (empty[11]==true) cout<<"_"; else cout<<data[11];
    gotoxy(45,10); if (empty[12]==true) cout<<"_"; else cout<<data[12];
    gotoxy(55,10); if (empty[13]==true) cout<<"_"; else cout<<data[13];
    gotoxy(65,10); if (empty[14]==true) cout<<"_"; else cout<<data[14];
    gotoxy(75,10); if (empty[15]==true) cout<<"_"; else cout<<data[15];
    cout<<endl<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}


void add(){
    int num;
    cout<<"Jaka liczbe dodac do drzewa: ";
    cin>>num;

    //tree empty
    if (empty[1]==true){
        root=&data[1];
        *root=num;
        empty[1]=false;
    }
    else{ //tree empty
        bool know_place=false;
        int node=1;

        while (know_place==false){
            if (empty[node]==true){
                know_place=true;
                data[node]=num;
                empty[node]=false;

            }
            else if(num<data[node]){
                //left
                node=2*node;
            }
            else{
                //right
                node=2*node+1;
            }
            if(node>15){
                cout<<"require bigger tree";
                Sleep(3000);
                know_place=true;
            }
        }
    }

}

void find(){
    int num;
    cout<<"Num to find: ";
    cin>>num;

    bool found=false;
    int node=1;

        while (found==false){
            if(num==data[node]){
                cout<<"Found in node Nr: "<<node;
                Sleep(3000);

                found=true;
            }
            else if(num<data[node]){
                //left
                node=2*node;
            }
            else{
                //right
                node=2*node+1;
            }
            if(node>15){
                cout<<"404";
                Sleep(3000);
                found=true;
            }
        }
}



int main()
{
    for (int i=1; i<=15; i++){
        empty[i]=true;
    }
    root=NULL;

    do{
        show_tree();
        cout<<"   EMULATOR DRZEWA BINARNEGO "<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. ADD"<<endl;
        cout<<"2. FIND"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"choose: ";
            cin>>choose;
            cout<<endl;

        switch(choose){
            case 1: add(); break;
            case 2: find(); break;
        }
    }while (choose!=3);


    return 0;
}
