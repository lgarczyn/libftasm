extern malloc
extern ft_strlen
extern ft_memcpy
%include "src/macros.s"
global ft_strdup
ft_strdup:
	push RDI										; save str
	call ft_strlen									; call ft_strlen with str
	mov RDI, RAX
	inc RDI											; set first arg to strlen + 1
	push RDI										; save strlen + 1
	call malloc										; allocate strlen + 1 bytes
	cmp RAX, 0										; check for NULL return
	je .error										; if so, stop
	mov RDI, RAX									; set arg 1: dst to allocated memory
	pop RDX											; set arg 3: len to strlen + 1
	pop RSI											; set arg 2: src to str
	call ft_memcpy									; copy src to dst, set return value to dst
	ret
.error:
	mov RAX, 0
	ret
