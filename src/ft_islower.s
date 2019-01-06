%include "src/macros.s"

extern ascii_flags
global ft_islower

ft_islower:
	xor EAX, EAX							; zeros return value preemptively
	test EDI, ~127							; check for non-ascii (>127) input
	jnz .out_of_bounds						; if non-ascii was found, skip dereferenciation
	mov AL, byte [ascii_flags + EDI]		; dereference index into least sig. byte
	and EAX, flag_lower						; get specific bit
.out_of_bounds:
	ret
