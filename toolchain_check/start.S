# code sits in .text.boot
.section ".text.boot"

# global sumbol for _start, SP will point to this symbol at start
.global _start

_start:
1: wfe
   # jump to label "1" searching backward, 'b' = backward
   b 1b