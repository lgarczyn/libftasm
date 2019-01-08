%include "src/macros.s"

extern ascii_flags
global ft_isprint

ft_isprint:
	mov EAX, 128							; load default index
	cmp EDI, EAX							; check if ascii
	cmovae EDI, EAX							; replace with 128 if outside 0..127
											; cmov also zero-extends EDI into RDI
	lea RAX, [rel ascii_flags]				; load table address
	mov AL, byte [RAX + RDI]				; load table entry
	and EAX, flag_print						; apply mask to get correct bit and zero rest of EAX
	setnz AL								; normalize result, can be removed
	ret
