% Lab 04 — Interrupt simulation (timed event)
function lab04_interrupt()
led = 0; counter=0; tStart = tic;
while toc(tStart) < 2
    counter = counter + 1;
    if toc(tStart) > 1 && led==0
        disp('[ISR] LED ON'); pause(0.1); disp('[ISR] LED OFF'); led = 1;
    end
    pause(0.05);
end
disp(['Done. counter=',num2str(counter)]);
end