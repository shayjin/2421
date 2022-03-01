.file "lab7.s"
.section .rodata
print:
.string "%i"

.data
.align 8

A:
.skip 1048576, 0

B:
.skip 1048576, 0

C:
.skip 1048576, 0

.global main
	.type main, @function
.text
main:
pushq %rbp
movq %rsp, %rbp

movq $0, %rax
/* N */
movq $1024, %rdi
call compute
 
exitt:
leave
ret
.size main, .-main

.global compute
	.type sum, @function
compute:
pushq %rbp
movq %rsp, %rbp

movq $0, %rax

/* i, j, k */
movq $-1, %rsi
movq $-1, %rdx
movq $-1, %rcx

movq $0, %r8
movq $0, %r9

loop1:
addq $1, %rsi
cmp %rdi, %rsi
jge exit
movq $-1, %rdx 
jmp loop2

loop2:
addq $1, %rdx
/* asign A[i][k] * B[k][j] to C[i][j] */
movq %rsi, %r12
salq $9, %r12
addq %rdx, %r12
movq %rax, C(,%r12,2)

cmp %rdi, %rdx
jge loop1
movq $-1, %rcx
jmp loop3

loop3:
addq $1, %rcx
cmp %rdi, %rcx
jge loop2
jmp calc

calc:
movq %rsi, %r8
salq $9, %r8
addq %rcx, %r8

movq A(,%r8,2), %r8

movq %rcx, %r9
salq $9, %r9
addq %rdx, %r9

movq B(,%r9,2), %r9

imulq %r8, %r9
addq %r9, %rax

jmp loop3

exit:
leave
ret
.size compute, .-compute
