#include <iostream>
#include <windows.h>

using namespace std;

int data[6];
int size;



void displayHeap()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

    cout<<endl;
    //cout<<"----------------"<<endl;
    cout<<"Heap consistence:"<<endl;
    //cout<<"----------------"<<endl;

    for (int i=size; i>=1; i--)
    {
        cout<<data[i]<<endl;
    }

    if (size==0) cout<<"empty"<<endl;

    cout << "----------------"<<endl<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}



void push()
{
    if (size>=5)
    {
        cout << "heap full!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<< "PUSH (add to the heap): ";

        size=size+1;
        cin>>data[size];
    }
}



void pop()
{
    if (size>=1)
    {
        cout<<endl<<"POP - delete from list: "<<data[size];
        Sleep(2000);

        size=size-1;
    }
    else
    {
        cout << "Heap empty";
        Sleep(1000);
    }
}


void size()
{
    cout<<endl<<"Amount of element in heap: "<<size;
    Sleep(2000);
}



void empty()
{

    if (size==0) cout<<endl<<"EMPTY";
    else cout<<endl<<"NO EMPTY";
    Sleep(2000);
}



int main()
{

    int select;
    size=0;

    do
    {
        displayHeap();

        cout << "Main Menu:"<<endl;
        cout << "========================================="<<endl;
        cout << "1. PUSH (add element) "<<endl;
        cout << "2. POP (delete element) "<<endl;
        cout << "3. SIZE (size of the heap) "<<endl;
        cout << "4. EMPTY (wheather the heap is empty) "<<endl;
        cout << "5. exit program "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "select: ";
        cin >> select;

        switch (select)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            size();
            break;

        case 4:
            empty();
            break;

        }

    }
    while (select != 5);

    return 0;
}
