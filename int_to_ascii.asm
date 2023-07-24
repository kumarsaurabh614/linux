segment .data
num dq 55
result db 0


segment .text

global main
main:

mov rax,[num]
add rax,'0'
mov [result],rax


mov rax,60
xor rax,rax
syscall
