extern ft_strlen
extern ft_memcpy
%include "src/macros.s"
global ft_strcat
ft_strcat:
	mov RCX, RDI									; save dst
	mov RDI, RSI									; load src in arg 1
	call ft_strlen									; call strlen on src
	inc RAX
	mov RDX, RAX									; set arg 3: len to strlen(src) + 1
	mov RSI, RDI									; set arg 2: src to src
	mov RDI, RCX									; set arg 1: dst to dst
	call ft_strlen									; call strlen(dst)
	add RDI, RAX									; set arg1: dst to dst + strlen(dst)
	call ft_memcpy									; copy strlen(src) + 1 bytes from src to dst + strlen(dst)
	mov RAX, RCX									; set return value to dst
	ret
