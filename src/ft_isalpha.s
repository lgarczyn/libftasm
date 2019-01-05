%include "src/macros.s"

extern ascii_flags
global ft_isalpha

ft_isalpha:
	xor EAX, EAX						; empty EAX
	test EDI, ~127						; check for non-ascii (>127) input
	cmovz EAX, [rel ascii_flags + EDI]	; load ascii table if input fits
	and EAX, flag_alpha					; get specific bit
	ret

