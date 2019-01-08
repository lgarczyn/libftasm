%include "src/macros.s"

extern ascii_flags
global ft_isalnum

ft_isalnum:
	mov EAX, 128							; load default index
	cmp EDI, EAX							; check if ascii
	cmovae EDI, EAX							; replace with 128 if outside 0..127
											; cmov also zero-extends EDI into RDI
	lea RAX, [rel ascii_flags]				; get address to table
	mov AL, byte [RAX + RDI]				; load table entry
	and EAX, flag_alnum						; apply flag to isolate bit
	setnz AL								; normalize result, can be removed
	ret
