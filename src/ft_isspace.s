%include "src/macros.s"

extern ascii_flags
global ft_isspace

ft_isspace:
	mov EAX, 128							; load default index
	cmp EDI, EAX							; check if ascii
	cmovae EDI, EAX							; replace with 128 if outside 0..127
											; cmov also zero-extends EDI into RDI
	lea RAX, [rel ascii_flags]				; load table address
	movzx EAX, byte [RAX + RDI]				; load table entry
	and EAX, flag_white						; apply mask to get correct bit and zero rest of EAX
	ret
