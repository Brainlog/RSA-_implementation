#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int randomPrime()
{
    ifstream fin;
    fin.open("primeno.txt");
    
    int lower = 1;
    int upper = 8000;
    int p = rand() % (upper - lower) + lower;
    cout << "This is the random no." << p << "\n";
    int prim;
    for (int i = 1; i <= 8000; i++)
    {
        /* code */
        fin >> prim;

        if(i==p){
            cout << prim << "returned\n";
            return prim;
        }
    }
    return 0;
}


int ePrime()
{
    ifstream fin1;
    fin1.open("e_prime.txt");
    
    int lower = 1;
    int upper = 14;
    int p = rand() % (upper - lower) + lower;
    cout << "This is the random no." << p << "\n";
    int prim;
    for (int i = 1; i <= 14; i++)
    {
        /* code */
        fin1 >> prim;

        if(i==p){
            cout << prim << "returned\n";
            return prim;
        }
    }
    return 0;
}


class Key
{
private:
    int private_key;
    int decrypt();
    int phi;

public:
    Key();
    int N;
    int public_key;
    double encrypt(int message);
    int e;


};

Key::Key()
{

    int p = randomPrime();
    int q = randomPrime();
    N = p*q;
    phi = (p-1)*(q-1);
    e = ePrime();
  
}

double Key::encrypt(int message){
   long long commitment;
   cout << sizeof(long long) << "\n";
    cout << pow(message,e) << "This is the commitment\n";
    commitment = ((long long )pow(message,e) % N);
    cout << commitment << "This is the commitment oo\n";
    return commitment;

}

int main()
{
    Key *bob_key = new Key();
    int a = bob_key->encrypt(10);
    int p = bob_key->e;
 
    cout << a << "  " << p;


    

    
    



    return 0;
}