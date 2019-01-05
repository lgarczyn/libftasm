extern ascii_flags
extern ft_isupper
%include "src/macros.s"
global ft_tolower
ft_tolower:
	call ft_isupper							; check if char is lowercase
	test EAX, EAX							; load ZF if zero
	mov EAX, EDI							; move to return value
	jz .end									; skip next instruction
	or EAX, 0b0100000						; set to uppercase
.end:
	ret
