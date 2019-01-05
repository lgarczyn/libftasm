%include "src/macros.s"
global ft_memcpy
ft_memcpy:
	mov RAX, RDI									; save dest to return value
	add RDX, RDI									; set RDX to dest + len
.loop:
	cmp RDI, RDX									; check if RDI has reached RDX
	je .end											; if so, stop
	mov R11, [RSI]
	mov [RDI], R11									; *dst = *src
	inc RDI											; dst++
	inc RSI											; src++
	jmp .loop
.end:
	ret
