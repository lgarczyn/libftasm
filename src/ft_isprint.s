%include "src/macros.s"

extern ascii_flags
global ft_isprint
global ft_isprint_branch
global ft_isprint_compact

ft_isprint_branch:
	test RDI, ~127							; check for non-ascii (>127) input
	jnz .out_of_bounds						; if non-ascii, jump to error handling
	mov AL, byte [ascii_flags + RDI]		; dereference index into least sig. byte
	and EAX, flag_print						; get specific bit (and zeros rest of EAX)
	ret
.out_of_bounds:
	xor EAX, EAX							; zeros return value
	ret

ft_isprint_compact:
	xor EAX, EAX							; zeros return value preemptively
	test EDI, ~127							; check for non-ascii (>127) input
	jnz .out_of_bounds						; if non-ascii was found, skip dereferenciation
	mov AL, byte [ascii_flags + EDI]		; dereference index into least sig. byte
.out_of_bounds:
	ret

ft_isprint:
	mov EAX, 128							; load default index
	cmp EDI, EAX							; check if ascii
	cmovae EDI, EAX							; replace with 128 if outside 0..127
											; cmov also zero-extends EDI into RDI
	movzx EAX, byte [ascii_flags + RDI]		; load table entry
	ret
