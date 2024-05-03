#include<bits/stdc++.h>
#include "patient.cpp"
using namespace std;

int main(){
    char n1[100] ;
    char n2 [100];
    cin>>n1>>n2;

    int temp1[]{10,10,10},temp2[]{20,20,20};

    

    
    patient p(1,n1,temp1);
    patient p2(2,n2,temp2);
    // cout<<endl<<n2<<endl<<endl;
    cout<<endl<<"Patent Details:- ";
    cout<<p;
    cout<<p2;

    cout<<endl;

    return 0;
}