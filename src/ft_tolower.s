extern ascii_flags
extern ft_isupper
%include "src/macros.s"
global ft_tolower

ft_tolower:
	mov EAX, EDI						; set return value to c
	cmp EDI, 127						; if c is non-ascii
	ja .end								; if so, return c
	movsx RDX, EDI						; move EDI to 64bits
	lea RDI, [rel ascii_flags]			; load table address
	test byte [RDI + RDX], flag_upper	; check if c is uppercase
	jz .end								; if not, return c
	xor EAX, 32							; turn c lowercase
.end:
    ret