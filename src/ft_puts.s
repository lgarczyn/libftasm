extern ft_strlen
%include "src/macros.s"
global ft_puts

section .data
endline: db 10

section .text
ft_puts:
	mov RSI, RDI					; set arg2 to str
	call ft_strlen					; get strlen(str)
	mov RDI, STDOUT					; set arg1 to STDOUT
	mov RDX, RAX					; set arg3 to strlen(str)
	mov RAX, SYSCALL(WRITE) 		; set syscall to write
	syscall							; call write
	cmp RAX, -1						; if error
	je .end							; skip next call and transmit return value
	mov RDX, 1						; set arg3 to 1
	lea RSI, [rel endline]			; set arg2 to "\n"
	mov RDI, STDOUT					; set arg1 to STDOUT
	mov RAX, SYSCALL(WRITE) 		; set syscall to write
	syscall							; call write
.end:
	ret

