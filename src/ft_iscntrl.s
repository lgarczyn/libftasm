%include "src/macros.s"

extern ascii_flags
global ft_iscntrl

ft_iscntrl:
	cmp EDI, 128							; check if ascii
	jae .end
	lea RAX, [rel ascii_flags]				; load table address
	mov AL, byte [RAX + RDI]				; load table entry
	and EAX, flag_print						; apply mask to get correct bit and zero rest of EAX
    sete AL                                 ; invert result
	ret
.end:
    xor EAX, EAX
    ret