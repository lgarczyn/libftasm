extern ft_memset
%include "src/macros.s"
global ft_bzero
ft_bzero:
	mov RDX, RSI	; set third argument (len) as the second given argument
	mov RSI, 0		; set second argument to 0
	call ft_memset	; call memset with ptr and 0
	ret
