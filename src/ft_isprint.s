%include "src/macros.s"

extern ascii_flags
global ft_isprint
global ft_isprint_branch
global ft_isprint_compact

ft_isprint_compact:
	sub EDI, 32								; substract 32 from input, to overflow any value < ' '
	xor EAX, EAX							; set return value to 0
	cmp EDI, 94								; check if input <= '~' - 32
	setbe AL								; if so, set return value to 1
	ret

ft_isprint_branch:
	xor EAX, EAX							; set return value to 0
	cmp EDI, 127							; check for non-ascii (>127) input
	ja .out_of_bounds						; if non-ascii was found, skip dereferenciation
	mov AL, byte [rel ascii_flags + EDI]	; dereference index into least sig. byte
.out_of_bounds:
	ret

ft_isprint:
	mov EAX, 128							; load default index
	cmp EDI, EAX							; check if ascii
	cmovae EDI, EAX							; replace with 128 if outside 0..127
											; cmov also zero-extends EDI into RDI
;	movzx EAX, byte [ascii_flags + RDI]		; alternative to two following instruction if masking is removed
	mov AL, byte [ascii_flags + RDI]		; load table entry
	and EAX, flag_print						; apply mask to get correct bit and zero rest of EAX
	ret
