extern ft_strlen
%include "src/macros.s"
global ft_puts

section .data
endline: db 10

section .text
ft_puts:
	push rbp
	mov rbp, rsp
	call ft_strlen									; (with arg str)
	mov RDX, RAX									; set syscall third arg as strlen return 
	mov RSI, RDI									; set syscall second arg as first received
	mov RDI, 1										; set syscall first arg as 1
	mov RAX, SYSCALL(WRITE)							; set syscall to write
	syscall											; call write
	cmp EAX, -1										; if return value is -1, transmit it to caller
	je .end
	mov RDX, STDOUT									; set syscall third arg to 1
	mov RSI, [rel endline]							; set syscall second arg to "\n"
	mov RDI, 1										; set syscall first arg as 1
	syscall											; call write again
													; if return value is -1, transmit it to caller
.end:
	leave
	ret

