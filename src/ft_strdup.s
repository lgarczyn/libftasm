extern malloc
extern ft_strlen
extern ft_memcpy
%include "src/macros.s"
global ft_strdup

ft_strdup:
	push    RBP			; store RBP
	mov     RBP, RDI	; save arg1 to RBP
	call    ft_strlen	; call strlen with str
	lea     R8, [RAX+1]	; store strlen + 1 in R8
	mov     RDI, R8		; store strlen + 1 in arg1
	call    malloc		; allocate strlen + 1 bytes
	test    RAX, RAX	; check if malloc failed
	je      .error		; if so, return NULL
	mov     RDX, R8		; store strlen + 1 in arg3
	mov     RSI, RBP	; store str to arg2
	mov     RDI, RAX	; store dst to arg1
	pop     RBP			; restore RBP
	jmp		ft_memcpy	; copy strlen + 1 bytes from src to dst, then return dst
.error:
	pop     RBP			; restore RBP
	ret
