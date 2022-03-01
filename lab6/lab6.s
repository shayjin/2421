.file "lab6.s"
.section .rodata
print_array:
.string "%i "

print_unsorted:
.string "Unsorted Array: "

print_sorted:
.string "Sorted Array: "

print_line:
.string "\n"

.data
.align 8

array:
.quad 10
.quad 39
.quad 85
.quad 17
.quad 6
.quad 13
.quad 152
.quad 33
.quad 13
.quad 3
.globl main
	.type main, @function
.text
main:
pushq %rbp
movq %rsp, %rbp

movq $0, %rbx
movq $0, %rax
movq $print_unsorted, %rdi
call printf

unsorted:
movq array (,%rbx, 8), %rsi

movq $0, %rax
movq $print_array, %rdi
call printf

incq %rbx
cmp $10, %rbx
jl unsorted

movq $array, %rsi
movq $10, %rdi

call sum

movq $print_line, %rdi
call printf

movq $0, %rbx
movq $0, %rax
movq $print_sorted, %rdi
call printf

sorted:
movq array(,%rbx, 8), %rsi
movq $0, %rax
movq $print_array, %rdi
call printf

incq %rbx
cmp $10, %rbx
jl sorted

movq $print_line, %rdi
call printf

leave
ret
.size main, .-main

.globl sum
	.type sum, @function
sum:
pushq %rbp
movq %rsp, %rbp

movq $0, %rax

movq (%rsi, %rdi, 8), %rbx
jmp loop1

loop1:
subq $1, %rdi
jl exit

movq $0, %rbx
jmp loop2

loop2:
movq %rbx, %r12
addq $1, %r12

movq array(,%rbx,8), %r13
movq array(,%r12,8), %r14

cmp %r13, %r14
jl calc

incq %rbx
cmp %rdi, %rbx
jl loop2

jmp loop1

calc:
mov %r13, %r14
movq array(,%r12,8), %r15

movq %r15, array(,%rbx,8)
movq %r13, array(,%r12,8)

incq %rbx
cmp $9, %rbx
jge loop1

jmp loop2

exit:
leave
ret
.size sum, .-sum
