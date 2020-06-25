#include <iostream>
#include <list>
#include <windows.h>
using namespace std;


list <int> list1; 
int choose;

void show(){
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Content of List: "<<endl;
    cout<<"---------------------------"<<endl;

    for(list<int>::iterator i=list1.begin(); i!= list1.end(); ++i)
       cout<<*i<<" ";

    cout<<endl;
    cout<<"---------------------------"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void push_front(){
    int num;
    cout<<"Add num to the head: ";
    cin>>num;
    list1.push_front(num);
}

void push_back(){
    int num;
    cout<<"Add num to the tail: ";
    cin>>num;
    list1.push_back(num);
}

void pop_front(){
    cout<<"Delete the head num";
    Sleep(2000);
    list1.pop_front();
}

void pop_back(){
    cout<<"Delete the tail num";
    Sleep(2000);
    list1.pop_back();
}

void size(){
    cout<<"Amount of nums in list: "<<list1.size();
    Sleep(2000);
}

void max_size(){
    cout<<"Max num limit: "<<list1.max_size();
    Sleep(5000);
}

void empty(){
    cout<<"Empty?";
    if (list1.empty()==1) cout<<"TRUE"; else cout<<"FALSE";
    Sleep(2000);
}

void remove(){
    int num;
    cout<<"Delete all num that equals with: ";
    cin>>num;
    list1.remove(num);
}

void sort(){
    cout<<"List sort";
    list1.sort();
    Sleep(2000);
}

void reverse(){
    cout<<"Reversed list sort";
    list1.reverse();
    Sleep(2000);
}

void exit(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Exit";
    Sleep(2000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}


int main(){
    do{
        show();

        cout << " Main Menu:"<<endl;
        cout << "---------------------------"<<endl;
        cout << "1.  push_front"<<endl;
        cout << "2.  push_back"<<endl;
        cout << "3.  pop_front"<<endl;
        cout << "4.  pop_back"<<endl;
        cout << "5.  size"<<endl;
        cout << "6.  max_size"<<endl;
        cout << "7.  empty"<<endl;
        cout << "8.  remove"<<endl;
        cout << "9.  sort"<<endl;
        cout << "10. reverse"<<endl;
        cout << "11. exit"<<endl;
        cout << "---------------------------"<<endl;
        cout << "choose: ";
        cin >> choose;

            switch (choose){
                case 1:  push_front(); break;
                case 2:  push_back();  break;
                case 3:  pop_front();  break;
                case 4:  pop_back();   break;
                case 5:  size();       break;
                case 6:  max_size();   break;
                case 7:  empty();      break;
                case 8:  remove();     break;
                case 9:  sort();       break;
                case 10: reverse();    break;
                case 11: exit();       break;

                default:
                cout<<"Error";
                Sleep(2000);
                break;
            }

    }while(choose!=11);
        return 0;
}
