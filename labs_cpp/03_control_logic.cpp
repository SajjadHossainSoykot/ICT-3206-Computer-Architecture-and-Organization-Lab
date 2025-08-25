// Lab 03 — Control Logic (Hardwired + PLA)
#include <bits/stdc++.h>
using namespace std;
map<string,int> hardwired(int op){
    return {
        {"MRD", op==0}, {"MWR", op==1}, {"RLD", op==0||op==2||op==3},
        {"ALU_ADD", op==2}, {"ALU_SUB", op==3}
    };
}
int main(){
    vector<string> names={"LOAD","STORE","ADD","SUB"};
    for(int op=0; op<4; ++op){
        auto hw = hardwired(op);
        cout<<names[op]<<": MRD="<<hw["MRD"]<<" MWR="<<hw["MWR"]
            <<" RLD="<<hw["RLD"]<<" ADD="<<hw["ALU_ADD"]<<" SUB="<<hw["ALU_SUB"]<<"\n";
    }
}