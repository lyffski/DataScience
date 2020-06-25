#include <iostream>
#include <windows.h>

using namespace std;

int data[5];
int amount;
int head;
int tail;



void displayQueue()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

    cout<<endl;
    //cout<<"-------------------"<<endl;
    cout<<"Consistance of Queue: "<<endl;
    //cout<<"-------------------"<<endl;


    if (amount==0)
    {
        cout<<"empty";
    }

    else
    {

        int indx;

        for (int i=0; i<amount; i++)
        {
            indx=head+i;
            if (head+i>=5) indx=head+i-5;
            cout<<data[indx]<<" ";
        }

    }

    cout<<endl<<"-------------------"<<endl<<endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}



void push()
{
    if (amount>=5)
    {
        cout << "Queue full";
        Sleep(1000);
    }
    else
    {
        cout<<endl<< "PUSH (add to queue): ";
        cin>>data[tail];
        tail=(tail+1)%5;
        amount=amount+1;
    }
}



void pop()
{
    if (amount==0)
    {
        cout<<"Queue is empty";
        Sleep(1000);
    }
    else
    {
        cout<<endl<<"POP - delete from list: "<<data[head];
        head=(head+1)%5;
        amount=amount-1;
		Sleep(1000);

    }


}


void size()
{
    cout<<endl<<"Amount of element in Queue: "<<amount;
    Sleep(1000);
}



void empty()
{

    if (amount==0) cout<<endl<<"True";
    else cout<<endl<<"FALSE";
    Sleep(1000);
}


int main()
{

    int select;
    amount=0;
    head=0;
    tail=0;

    do
    {

        displayQueue();

        cout<<"head="<<head<<"   tail="<<tail<<"   amount="<<amount<<endl<<endl;

        cout << "Main Menu:"<<endl;
        cout << "=========================================="<<endl;
        cout << "1. PUSH (add element) "<<endl;
        cout << "2. POP (delete element) "<<endl;
        cout << "3. SIZE (amount of element in Queue) "<<endl;
        cout << "4. EMPTY? "<<endl;
        cout << "5. Exit programm "<<endl;
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
