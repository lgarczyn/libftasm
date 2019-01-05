%include "src/macros.s"

extern ascii_flags
global ft_isupper

ft_isupper:
	xor RAX, RAX						; empty RAX
	test RDI, ~127						; check for non-ascii (>127) input
	cmovz EAX, [rel ascii_flags + RDI]	; load ascii table if input fits
	and RAX, flag_upper					; get specific bit
	ret
