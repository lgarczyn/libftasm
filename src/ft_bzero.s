extern ft_memset
%include "src/macros.s"
global ft_bzero

ft_bzero:
	test RSI, RSI			; check if counter is already 0
	je .end					; if so, return
	add RSI, RDI			; store ptr + len in RSI
.loop:
	mov byte [RDI], 0	; *ptr = 0;
	inc RDI					; ptr++;
	cmp RDI, RSI			; if (ptr == ptr + len)
	jne .loop				; break;
.end:
	ret