% Lab 02 — 4-bit ALU
function lab02_alu()
A = bin2dec('1010'); B = bin2dec('0101');
for ctrl=0:3
    [out,c,z] = alu4(A,B,ctrl);
    fprintf('CTRL=%d OUT=%s C=%d Z=%d SHL=%s\n',ctrl,dec2bin(out,4),c,z,dec2bin(bitand(bitshift(out,1),15),4));
end
end
function [out,c,z] = alu4(a,b,ctrl)
if ctrl==0
    s = a+b; c = s>15; out = bitand(s,15);
elseif ctrl==1
    s = a + bitand(bitcmp(b),15) + 1; c = s>15; out = bitand(s,15);
elseif ctrl==2
    out = bitand(a,b); c=0;
else
    out = bitor(a,b); c=0;
end
z = out==0;
end