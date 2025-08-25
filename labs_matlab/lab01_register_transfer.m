% Lab 01 — Register Transfer (4-bit)
function lab01_register_transfer()
A = 0b1010; B = 0; C = 0;
disp(['Initial A=',bits(A),' B=',bits(B),' C=',bits(C)]);
B = A;
disp(['After A->B A=',bits(A),' B=',bits(B)]);
A = bitand(A+1,15);
disp(['After INC A=',bits(A)]);
C = bitand(A,B);
disp(['After AND C=',bits(C)]);
A = bitand(bitshift(A,1),15);
disp(['After SHL A=',bits(A)]);
end
function s = bits(x)
s = dec2bin(bitand(x,15),4);
end