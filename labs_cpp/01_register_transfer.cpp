// Lab 01 — Register Transfer (4-bit)
#include <bits/stdc++.h>
using namespace std;
struct Reg4 {
    int v=0;
    void load(int x){ v = x & 0xF; }
    void inc(){ v = (v+1)&0xF; }
    static int AND(int a, int b){ return (a&b)&0xF; }
    void shl(){ v = (v<<1)&0xF; }
    string bits() const { string s=""; for(int i=3;i>=0;--i) s+= ((v>>i)&1?'1':'0'); return s; }
};
int main(){
    Reg4 A,B; int C=0;
    A.load(0b1010);
    cout<<"Initial A="<<A.bits()<<" B="<<B.bits()<<" C=0000\n";
    B.load(A.v);
    cout<<"After A->B: A="<<A.bits()<<" B="<<B.bits()<<"\n";
    A.inc();
    cout<<"After INC A: A="<<A.bits()<<"\n";
    C = Reg4::AND(A.v,B.v);
    cout<<"After AND: C="<<bitset<4>(C)<<"\n";
    A.shl();
    cout<<"After SHL A: A="<<A.bits()<<"\n";
}