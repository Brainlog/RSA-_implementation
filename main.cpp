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
    double decrypt(int commitment);
    int phi;
    int d;

public:
    Key();
    int N;
    int public_key;
    double encrypt(int message);
    int e;
    double test(int commitment);


};

Key::Key()
{

    int p = randomPrime();
    int q = randomPrime();
    N = p*q;
    phi = (p-1)*(q-1);
    e = ePrime();
    // d  = (N + 1)/e;
    for (int i = 0; i < 1000; i++)
    {
        /* code */
        if((N+1)%e == 0){
            d = (N+1)/e;
            break;
        }

    }
    
  
}

double Key::encrypt(int message){
   long long commitment;
   cout << sizeof(long long) << "\n";
    cout << pow(message,e) << "This is the commitment\n";
    commitment = ((long long )pow(message,e) % N);
    cout << commitment << "This is the commitment oo\n";
    return commitment;

}

double Key::decrypt(int commitment){
   long long message;
   cout << sizeof(long long) << "\n";
    cout << pow(commitment,d) << "This is the message\n";
    message = ((long long )pow(commitment,d) % N);
    cout << message << "This is the message oo\n";
    return message;

}

double Key::test(int commitment){
   double p =  decrypt(commitment);
   return p;
}

int main()
{
    Key *bob_key = new Key();
    long long a = bob_key->encrypt(10);
    long long b = bob_key->test(bob_key->encrypt(10));
    int p = bob_key->e;
 
    cout << a << "  " << p << "  " << b;


    

    
    



    return 0;
}