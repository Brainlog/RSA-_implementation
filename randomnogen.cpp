#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
   ofstream fo;
   ofstream fo1;
   fo.open("primeno.txt");
   fo1.open("e_prime.txt");
   for (int i = 10; i < 64; i++)
   {
       /* code */
       int chk = 0;
       for (int j = 2; j < i; j++)
       {
           /* code */
           if(i % j == 0) chk = 1;
       }
       if(!chk) fo1 << i << "\n";
       
   }
   for (int i = 100000; i < 200000; i++)
   {
       /* code */
       int chk = 0;
       for (int j = 2; j < i; j++)
       {
           /* code */
           if(i % j == 0) chk = 1;
       }
       if(!chk) fo << i << "\n";
       
   }
   
   
    return 0;
}