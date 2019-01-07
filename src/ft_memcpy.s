%include "src/macros.s"
global ft_memcpy
ft_memcpy:
	mov RAX, RDI									; save dest to return value
	cmp RDX, 0										; check if len == 0
	je .end											; if so, stop
	add RDX, RDI									; set RDX to dest + len
.loop:
	mov R11, [RSI]
	mov [RDI], R11									; *dst = *src
	inc RDI											; dst++
	inc RSI											; src++
	cmp RDI, RDX									; check if RDI has reached RDX
	jne .end										; if so, stop
.end:
	ret
