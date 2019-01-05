extern ascii_flags
extern ft_islower
%include "src/macros.s"
global ft_toupper
ft_toupper:
	call ft_islower							; check if char is lowercase
	test EAX, EAX							; load ZF if 0
	mov EAX, EDI							; move to return value
	jz .end									; skip next instruction
	and EAX, ~0b0100000							; set to uppercase
.end:
	ret
