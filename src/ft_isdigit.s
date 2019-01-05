%include "src/macros.s"

extern ascii_flags
global ft_isdigit

ft_isdigit:
	xor RAX, RAX						; empty RAX
	test RDI, ~127						; check for non-ascii (>127) input
	cmovz EAX, [rel ascii_flags + RDI]	; load ascii table if input fits
	and RAX, flag_digit					; get specific bit
	ret

