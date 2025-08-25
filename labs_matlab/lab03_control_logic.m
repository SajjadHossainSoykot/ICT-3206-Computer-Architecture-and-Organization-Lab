% Lab 03 — Control Logic (Hardwired)
function lab03_control()
names = {'LOAD','STORE','ADD','SUB'};
for op=0:3
    MRD = op==0; MWR = op==1; RLD = any(op==[0,2,3]);
    ADD = op==2; SUB = op==3;
    fprintf('%s: MRD=%d MWR=%d RLD=%d ADD=%d SUB=%d\n',names{op+1},MRD,MWR,RLD,ADD,SUB);
end
end