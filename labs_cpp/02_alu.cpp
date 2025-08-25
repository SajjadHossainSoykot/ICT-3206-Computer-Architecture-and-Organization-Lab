// Lab 02 — 4-bit ALU
#include <bits/stdc++.h>
using namespace std;
tuple<int,int,int> ALU(int a,int b,int ctrl){
    int out=0,c=0; // ctrl:0 ADD 1 SUB 2 AND 3 OR
    if(ctrl==0){ int s=a+b; c = s>0xF; out = s & 0xF; }
    else if(ctrl==1){ int s=a+((~b)&0xF)+1; c = s>0xF; out = s & 0xF; }
    else if(ctrl==2){ out=a&b; }
    else { out=a|b; }
    int z = (out==0);
    return {out,c,z};
}
int shl1(int x){ return (x<<1)&0xF; }
int main(){
    int A=0b1010, B=0b0101;
    for(int ctrl=0; ctrl<4; ++ctrl){
        auto [out,c,z] = ALU(A,B,ctrl);
        cout<<"CTRL="<<ctrl<<" OUT="<<bitset<4>(out)<<" C="<<c<<" Z="<<z<<" SHL="<<bitset<4>(shl1(out))<<"\n";
    }
}