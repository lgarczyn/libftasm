%include "src/macros.s"
global ft_strlen
global ft_strlen_fast

ft_strlen_fast:
	cmp [RDI], byte 0		; compare first byte to 0
	mov RAX, RDI			; save str to return value
	jz .end					; if first byte was enpty, skip
.loop:
	inc RAX					; inc ptr
	cmp [RAX], byte 0		; check current byte
	jne .loop				; go back to start if byte is not zero
.end:
	sub RAX, RDI			; set RAX as diff between incremented and original str
	sub RDI, RAX			; restore RDI
	ret

ft_strlen:
	xor AL, AL				; set REP scan byte to 0
	xor RCX, RCX			; reset RCX
	not RCX					; set RCX to 0xFFFFFFFF_FFFFFFFF
	cld						; set direction of rep operation
	repnz scasb				; while (*RDI) {RDI++, RCX--}
	not RCX					; recover strlen + 1 from counter
	dec RCX					; dec to strlen
	mov RAX, RCX			; move to return value
	ret
