%include "src/macros.s"
global ft_memcpy
global ft_memcpy_fast


; RSI dst RDI src RDX 
ft_memcpy:
	mov RAX, RDI									; set return value to dst
	mov RCX, RDX									; set REP counter to len
	cld												; set direction
	rep movsb										; copy RCX bytes from [RDI] to [RSI]
	ret

ft_memcpy_fast:
	mov RAX, RDI									; save dest to return value
	test RDX, RDX									; check if len == 0
	je .end											; if so, stop
	xor RCX, RCX									; i = 0
.loop:
	movzx R11, byte [RSI + RCX]
	mov byte [RDI + RCX], R11b						; dst[i] = src[i]
	inc RCX											; i++
	cmp RCX, RDX									; check if i has reached len
	jne .loop										; if so, stop
.end:
	ret
