extern endline
extern ft_strlen
%include "src/macros.s"
global ft_puts
ft_puts:
	call ft_strlen									; (with arg str)
	mov RDX, RAX									; set syscall third arg as strlen return 
	mov RSI, RDI									; set syscall second arg as first received
	mov RDI, 1										; set syscall first arg as 1
	mov RAX, SYSCALL(WRITE)							; set syscall to write
	syscall											; call write
	cmp EAX, -1										; error handling
	je .error
	mov RDX, STDOUT									; set syscall third arg to 1
	mov RSI, [rel endline]							; set syscall second arg to "\n"
	syscall											; call write again
	cmp EAX, -1										; error handling
	je .error
	ret
.error:
	mov EAX, EOF									; set return to EOF (-1)
	ret

