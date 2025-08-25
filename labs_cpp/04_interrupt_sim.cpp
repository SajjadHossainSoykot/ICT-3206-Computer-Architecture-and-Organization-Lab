// Lab 04 — Interrupt simulation (simplified)
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
atomic<bool> intr(false);
void isr(){ cout<<"[ISR] LED ON\n"; this_thread::sleep_for(100ms); cout<<"[ISR] LED OFF\n"; }
void trigger(){ this_thread::sleep_for(1s); intr=true; }
int main(){
    thread t(trigger);
    int counter=0; auto start=chrono::steady_clock::now();
    while(chrono::steady_clock::now() - start < 2s){
        counter++;
        if(intr.exchange(false)) isr();
        this_thread::sleep_for(50ms);
    }
    cout<<"Done. counter="<<counter<<"\n";
    t.join();
}