%include "src/macros.s"

global ft_isascii

ft_isascii:
	cmp EDI, 128		; check if arg has no bit past the 7th
	setb AL				; if so, set return value to 1
	movzx EAX, AL		; set EAX to it least significant byte
	ret
