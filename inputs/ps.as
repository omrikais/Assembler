; All rights reserved to the open university of israel. (c)
    .extern L3
MAIN: add r3,LIST
LOOP: prn #48
lea W,r6
inc r6
mov r3,K
sub r1,r4
    .extern L3
.entry MAIN
bne END
cmp K, #-6
bne &END
dec W
    .extern L3
;Comment0
.entry MAIN
jmp &LOOP
add L3,L3
END: stop
STR: .string "abcd"
;Comment1
LIST: .data 6,-9
.data -100
K: .data 31
.entry LIST
.extern W
.extern L3
.entry MAIN
    .extern L3