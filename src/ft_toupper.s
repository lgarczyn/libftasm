extern ascii_flags
extern ft_islower
%include "src/macros.s"
global ft_toupper

ft_toupper:
	mov EAX, EDI						; set return value to c
	cmp EDI, 127						; if c is non-ascii
	ja .end								; if so, return c
	movsx RDX, EDI						; move EDI to 64bits
	lea RDI, [rel ascii_flags]			; load table address
	test byte [RDI + RDX], flag_lower	; check if c is lowercase
	jz .end								; if not, return c
	xor EAX, 32							; turn c uppercase
.end:
    ret
