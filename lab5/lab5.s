.file "lab5.s"
.section .rodata
printf_line:
.string "ret: %i\n"
.data
x:
.quad 0
y:
.quad 0
z:
.quad 0

.globl main
	.type main, @function
.text
main:
pushq %rbp
movq %rsp, %rbp

movq $3, %rdi
movq $4, %rsi
movq $5, %rdx

pushq %rdi
pushq %rsi
pushq %rdx

call sum

movq %rax, %rsi
movq $printf_line, %rdi

movq $0, %rax
call printf

leave
ret
.size main, .-main

.globl sum
	.type sum, @function
sum:
	pushq %rbp
	movq %rsp, %rbp

	pushq %rax
	pushq %rdi
	pushq %rsi
	
	leaq (%rdi, %rsi), %rax
	addq %rdx, %rax
	leaq (%rsi, %rsi, 2), %rdx
	salq $4, %rdx
	leaq 4(%rdi, %rdx), %rcx
	imulq %rcx, %rax

	leave 
	ret
.size sum, .-sum
