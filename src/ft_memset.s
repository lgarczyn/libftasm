%include "src/macros.s"
global ft_memset
global ft_memset_fast

ft_memset_fast:
	mov RAX, RDI			; save ptr to return value
	add RDX, RDI			; set RDX to ptr + len
	cmp RDI, RDX 			; if ptr has reached RSI, stop
	je .end
.loop:
	mov byte [RDI], SIL		; *ptr = c
	inc RDI					; ptr++
	cmp RDI, RDX 			; if ptr not reached RSI, continue
	jne .loop
.end:
	ret

ft_memset:
	push RDI				; save RDI (char *ptr) for return
	mov RCX, RDX			; move RDX (size_t len) to rep counter
	mov EAX, ESI			; move ESI (int c) to the rep STOS thing
	cld						; set direction as forward
	rep stosb				; while (RDX) {*RDI = AL; RDI++; RDX--}
	pop RAX					; place original ptr in return value
	ret
