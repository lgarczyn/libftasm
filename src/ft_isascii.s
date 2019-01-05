%include "src/macros.s"

global ft_isascii

ft_isascii:
	cmp RDI, 128		; check if arg has any bit past the 7th
	setl AL				; if not, set return value to 0
	movzx EAX, AL		; set EAX to it least significant byte
	ret
