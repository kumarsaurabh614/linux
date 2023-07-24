segment .data
result dq 0		 ; final result will be stored
n dq 8                   ; N th value to calcualte

segment .text
global main
main:
	push rbp
	mov rbp,rsp
	sub rsp,16
	mov r8,[n]         

	cmp r8,0           ; comparing value of n
	jle exit
	xor rbx,rbx
	mov rcx,1

for:
	mov rdx,rbx                
	add rdx,rcx
			;swapping values
	mov rbx,rcx
	mov rcx,rdx

	dec r8
	jnz for

	mov [result],rbx




exit:
	mov rax,60
	xor rax,rax
	syscall



