
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

#define SIZE 10000

void input();
void sorting(int a[],int n);
void fileupdating(int a[],int n);
void inserting(int a[],int &n);
void deleting(int a[],int &n);
void searching(int a[],int n);
void display();
int menu();

int main()
{

    input();

    return 0;
}

void input()
{
    int  n,a[SIZE];
    cout<<"HELLO SIR,HOW MANY NUMBERS DO YOU WANT : ";

    while(1)
    {
        cin>>n;
        if(n>SIZE)
        {
            cout<<endl<<"SORRY, IT'S GREATER THAN SIZE,GIVE ANOTHER : ";
        }
        else
        {
            break;
        }
    }


    ofstream outf("RAND.DAT");
    srand(time(0));
    int i = 1;
    while(i<=n)
    {
        outf<<rand()%100<<" ";
        i++;
    }
    outf.close();

    ifstream inf("RAND.DAT");
    i = 0;
    while(inf>>a[i])
    {
        i++;
    }
    inf.close();

    cout<<endl<<"       BEFORE SORTING";
    display();
    sorting(a,n);
    fileupdating(a,n);
    cout<<endl<<"       AFTER SORTING";
    display();

    while(1)
    {
        int m;
        m = menu();

        switch(m)
        {
            case 1:
                inserting(a,n);
                break;

            case 2:
                deleting(a,n);
                break;

            case 3:
                searching(a,n);
                break;

            case 4:
                display();
                break;

            case 5:
                return;

            default:
                cout<<endl<<"     INVALID CHOICE, PLEASE TRY AGAIN"<<endl;
        }
    }
}

int menu()
{
    cout<<endl<<endl<<"         MENU"<<endl<<endl;
    cout<<"     1.INSERT  :"<<endl;
    cout<<"     2.DELETE  :"<< endl;
    cout<<"     3.SEARCH  :"<< endl;
    cout<<"     4.DISPLAY :"<< endl;
    cout<<"     5.EXIT    :"<< endl;
    int x;
    cout<<endl<<"PLEASE SELECT AN OPERATION : ";
    cin>>x;
    return x;
}

void sorting(int a[],int n)
{
    int i=0;
    while(i<n-1)
    {
        int k = 0,x = 0;
        while(k<n-i-1)
        {
            if(a[k]>a[k + 1])
            {
                int temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                x = 1;
            }
            k++;
        }
        if(x==0)
        {
            break;
        }
        i++;
    }
}

void fileupdating(int a[],int n)
{
    ofstream out("RAND.DAT");
    int i = 0;
    while(i<n)
    {
        out<<a[i]<<" ";
        i++;
    }
    out.close();
}

void inserting(int a[],int &n)
{
    int item;
    cout<<endl<<"PLEASE GIVE AN ITEM TO INSERT : ";
    cin>>item;

    if(n==SIZE)
    {
        cout<<endl<<"          OVERFLOW"<<endl;
        return;
    }

    int lower = 0,higher = n,position = n;
    while(lower<higher)
    {
        int midp = (lower+higher)/2;
        if(a[midp]<=item)
        {
            lower = midp + 1;
        }
        else
        {
            higher = midp;
        }
    }
    position = lower;

    int i = n;
    while(i>position)
    {
        a[i] = a[i-1];
        i--;
    }
    a[position] = item;
    n=n+1;

    fileupdating(a,n);
    cout<<endl<<"     SUCCESSFULLY ADDED"<<endl;
    display();
}

void deleting(int a[],int &n)
{
    int it;
    cout<<endl<<"PLEASE GIVE AN ITEM TO DELETE : ";
    cin>>it;

    if(n==0)
    {
        cout<<endl<<"          UNDERFLOW"<<endl;
        return;
    }

    int lb = 0,hb = n - 1,pos = -1;
    while(lb<=hb)
    {
        int mid = (lb+hb)/2;
        if(a[mid]==it)
        {
            pos = mid;
            lb = mid+1;
        }
        else if(it<a[mid])
        {
            hb = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    if(pos != -1)
    {
        while(pos<n-1)
        {
            a[pos] = a[pos+1];
            pos++;
        }
        n=n-1;
        fileupdating(a,n);
        cout<<endl<<"     SUCCESSFULLY DELETED"<<endl;
        display();
    }
    else
    {
        cout<<endl<<"     IT'S ALREADY NOT EXIST"<<endl;
    }
}

void searching(int a[],int n)
{
    int value;
    cout<<endl<<"PLEASE GIVE AN ITEM TO SEARCH : ";
    cin>>value;

    int low = 0,high = n - 1,res = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]==value)
        {
            res = mid;
            high = mid-1;
        }
        else if(value<a[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if(res != -1)
    {
        display();
        cout<<endl<<"     FOUND AT THE POSITION : "<<res+1<<endl;
    }
    else
    {
        cout<<endl<<"     NOT FOUND"<<endl;
    }
}

void display()
{
    ifstream file("RAND.DAT");
    int value,temp = 0;
    cout<<endl<<"THE NUMBERS ARE : ";
    while(file>>value)
    {
        cout<<value<<" ";
        temp = 1;
    }
    if(temp==0)
    {
        cout<<"[SORRY, FILE IS EMPTY]";
    }
    cout<<endl;
    file.close();
}
