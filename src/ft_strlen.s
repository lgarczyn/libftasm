%include "src/macros.s"
global ft_strlen
ft_strlen:
	mov RAX, RDI									; save RDI to return value
.loop:
	cmp [RAX], byte 0								; check current byte
	je .end											; if 0, stop
	inc RAX											; otherwise inc ptr
	jmp .loop										; go back to start
.end:
	sub RAX, RDI									; set RAX as diff between incremented and original pointer
	ret
