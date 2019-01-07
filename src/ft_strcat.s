extern ft_memcpy
extern ft_memcpy_fast
%include "src/macros.s"
global ft_strcat
global ft_strcat_fast

ft_strcat:
	mov		R8, RDI				; store dst inside R8
	mov		RCX, -1				; set REP counter to -1 (0xFFFF...)
	mov		RDI, RSI			; store src in REP ptr
	repnz	scasb				; while (*src) { src++; RCX--;}
	not		RCX					; invert counter, giving us strlen + 1
	mov		RDX, RCX			; set arg3 to strlen(src) + 1
	mov		RCX, -1				; set REP counter to -1
	mov		RDI, R8				; store dst in REP ptr
	repnz	scasb				; while (*dst) { dst++; RCX--;}
	not		RCX					; invert counter, giving us strlen + 1
	lea		RDI, [R8 + RCX - 1]	; set arg1 to src + strlen(src)
	call	ft_memcpy			; copy strlen(dst) + 1 bytes from dst to src
	mov		RAX, R8				; set return value to dst
	ret

ft_strcat_fast:
	mov		R8, RDI				; store dst inside R8
	mov		RCX, -1				; set REP counter to -1 (0xFFFF...)
	mov		RDI, RSI			; store src in REP ptr
	repnz	scasb				; while (*src) { src++; RCX--;}
	not		RCX					; invert counter, giving us strlen + 1
	mov		RDX, RCX			; set arg3 to strlen(src) + 1
	mov		RCX, -1				; set REP counter to -1
	mov		RDI, R8				; store dst in REP ptr
	repnz	scasb				; while (*dst) { dst++; RCX--;}
	not		RCX					; invert counter, giving us strlen + 1
	lea		RDI, [R8 + RCX - 1]	; set arg1 to src + strlen(src)
	call	ft_memcpy_fast		; copy strlen(dst) + 1 bytes from dst to src
	mov		RAX, R8				; set return value to dst
	ret
