%include "src/macros.s"
global ft_memset
ft_memset:
	push rbp
	mov rbp, rsp

	push 1
	mov RAX, RDI									; save ptr to return value
	add RDX, RDI									; set RDX to ptr + len
	push 2
.loop:
	cmp RDI, RDX 									; if ptr has reached RSI, stop
	je .end
	mov [RDI], SIL									; *ptr = c
	inc RDI											; ptr++
	jmp .loop
.end:
	pop RDI
	pop RDI

	mov rsp, rbp
	pop rbp
	ret	
