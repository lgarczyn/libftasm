;arguments
;	RDI, RSI, RDX, RCX, R8, R9 (R10 is used as a static chain pointer in case of nested functions[19]:21)
;	then stack
;	XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6 and XMM7 for floating points
;return
;	set eax (rax is eax 64)
;	ret
;callee-saved
;	RBX, RBP, and R12–R15
;caller-saved
;	RAX, RCX, RDX, R8, R9, R10, R11
;variables
;	128bytes of stack are garanteed for leaf functions

%define STDOUT					1
%define EOF						-1
%define BUFFER_SIZE				4096

%ifdef LINUX
%define SYSCALL(nb)				(nb)
%define READ					0
%define WRITE					1
%else
%define SYSCALL(nb)				(0x2000000 | nb)
%define READ					3
%define WRITE					4
%endif

extern malloc

global _ft_bzero
global _ft_isprint
global _ft_toupper
global _ft_tolower
global _ft_puts
global _ft_strlen
global _ft_memset
global _ft_memcpy
global _ft_strdup
global _ft_cat

section .data
ascii:
	.flag_alpha db 0b00000001
	.flag_digit db 0b00000010
	.flag_alnum db 0b00000100
	.flag_print db 0b00001000
	.flag_lower db 0b00010000
	.flag_upper db 0b00100000
	.flag_ascii db 0b01000000
	.flags db \
		0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, \
		0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, \
		0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, \
		0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, \
		0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, \
		0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, \
		0b01001110, 0b01001110, 0b01001110, 0b01001110, 0b01001110, 0b01001110, 0b01001110, 0b01001110, \
		0b01001110, 0b01001110, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, \
		                                                                                                \
		0b01001000, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, \
		0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, \
		0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, 0b01101101, \
		0b01101101, 0b01101101, 0b01101101, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01001000, \
		0b01001000, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, \
		0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, \
		0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, 0b01011101, \
		0b01011101, 0b01011101, 0b01011101, 0b01001000, 0b01001000, 0b01001000, 0b01001000, 0b01000000

;       '\0',       DET,        DTX,        FTX,        FTR,        DEM,        ACC,        '\a',
;       '\b',       '\t',       '\n',       '\v',       '\f',       '\r',       HC,         ES,
;       ECT,        CD1,        CD2,        CD3,        CD4,        ACN,        SYN,        FBT,
;       ANN,        FS,         SUB,        ECH,        SF,         SG,         SA,         SSA,
;       ' ',        '!',        '"',        '#',        '$',        '%',        '&',        ''',
;       '(',        ')',        '*',        '+',        ',',        '-',        '.',        '/',
;       '0',        '1',        '2',        '3',        '4',        '5',        '6',        '7',
;       '8',        '9',        ';',        ';',        '<',        '=',        '>',        '?',
;
;       '@',        'A',        'B',        'C',        'D',        'E',        'F',        'G',
;       'H',        'I',        'J',        'K',        'L',        'M',        'N',        'O',
;       'P',        'Q',        'R',        'S',        'T',        'U',        'V',        'W',
;       'X',        'Y',        'Z',        '[',        '\',        ']',        '^',        '_',
;       '`',        'a',        'b',        'c',        'd',        'e',        'f',        'g',
;       'h',        'i',        'j',        'k',        'l',        'm',        'n',        'o',
;       'p',        'q',        'r',        's',        't',        'u',        'v',        'w',
;       'x',        'y',        'z',        '{',        '|',        '}',        '~',        SUP

	.padding times 128 db 0
endline: db 10
buffer: times BUFFER_SIZE db 0

_ft_bzero:
	mov RDX, RSI	; set third argument (len) as the second given argument
	mov RSI, 0		; set second argument to 0
	call _ft_memset	; call memset with ptr and 0

_ft_isprint:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_print]
	ret

_ft_isascii:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_ascii]
	ret

_ft_isalnum:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_alnum]
	ret

_ft_isdigit:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_digit]
	ret

_ft_isalpha:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_alpha]
	ret

_ft_isupper:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_upper]
	ret

_ft_islower:
	lea RAX, [rel ascii.flags]
	mov AL, byte[rax + rdi]
	and AL, [rel ascii.flag_lower]
	ret

_ft_toupper:
	mov EAX, EDI							; save argument to return value
	lea R11, [rel ascii.flags]				; load table address
	mov R11, [R11D + EDI]					; deref correct byte (and some more)
	test R11b, [rel ascii.flag_lower]		; check byte against flag
	jz .end									; if not lowercase skip next instruction
	or AL, 0b1000000						; set to uppercase
.end:
	ret

_ft_tolower:
	mov EAX, EDI							; save argument to return value
	lea R11, [rel ascii.flags]				; load table address
	mov R11, [R11D + EDI]					; deref correct byte (and some more)
	test R11b, [rel ascii.flag_upper]		; check byte against flag
	jz .end									; if not lowercase skip next instruction
	and AL, ~0b1000000						; set to uppercase
.end:
	ret

_ft_puts:
	call _ft_strlen									; (with arg str)
	mov RDX, RAX									; set syscall third arg as strlen return 
	mov RSI, RDI									; set syscall second arg as first received
	mov RDI, 1										; set syscall first arg as 1
	mov RAX, SYSCALL(WRITE)					; set syscall to write
	syscall											; call write
	cmp EAX, -1										; error handling
	je .error
	mov RDX, STDOUT									; set syscall third arg to 1
	mov RSI, [rel endline]							; set syscall second arg to "\n"
	syscall											; call write again
	cmp EAX, -1										; error handling
	je .error
	ret
.error:
	mov EAX, EOF									; set return to EOF (-1)
	ret


_ft_strlen:
	mov RAX, RDI									; save RDI to return value
.loop:
	cmp [RAX], byte 0								; check current byte
	je .end											; if 0, stop
	inc RAX											; otherwise inc ptr
	jmp .loop										; go back to start
.end:
	sub RAX, RDI									; set RAX as diff between incremented and original pointer
	ret

_ft_memset:
	push rbp
	mov rbp, rsp

	push 1
	mov RAX, RDI									; save ptr to return value
	add RDX, RDI									; set RDX to ptr + len
	push 2
.loop:
	cmp RDI, RDX 									; if ptr has reached RSI, stop
	je .end
	mov [RDI], SIL									; *ptr = c
	inc RDI											; ptr++
	jmp .loop
.end:
	pop RDI
	pop RDI

	mov rsp, rbp
	pop rbp

	ret	

_ft_memcpy:
	mov RAX, RDI									; save dest to return value
	add RDX, RDI									; set RDX to dest + len
.loop:
	cmp RDI, RDX									; check if RDI has reached RDX
	je .end											; if so, stop
	mov R11, [RSI]
	mov [RDI], R11									; *dst = *src
	inc RDI											; dst++
	inc RSI											; src++
	jmp .loop
.end:
	ret

_ft_strdup:
	push RDI										; save str
	call _ft_strlen									; call _ft_strlen with str
	mov RDI, RAX
	inc RDI											; set first arg to strlen + 1
	push RDI										; save strlen + 1
	call malloc										; allocate strlen + 1 bytes
	cmp RAX, 0										; check for NULL return
	je .error										; if so, stop
	mov RDI, RAX									; set arg 1: dst to allocated memory
	pop RDX											; set arg 3: len to strlen + 1
	pop RSI											; set arg 2: src to str
	call _ft_memcpy									; copy src to dst, set return value to dst
	ret
.error:
	mov RAX, 0
	ret

_ft_cat:
	mov R11, RDI							; save fd to R11
	lea RSI, [rel buffer]					; load buffer in arg 2
.loop:
	mov RDX, BUFFER_SIZE					; load buffer size in arg 3
	mov RAX, SYSCALL(READ)					; set syscall to read
	syscall									; read
	cmp RAX, 0								; check return value
	jle .end								; jump to end if over or error
	mov RDI, STDOUT							; set arg 1 to STDOUT
	mov RDX, RAX							; set arg 3 to previously read len
	mov RAX, SYSCALL(WRITE)					; set syscall to write
	syscall									; write
	cmp RAX, 0								; check something was written
	jle .end								; jump to end if not
	mov RDI, R11							; put fd back in arg 1
	jmp .loop
.end:
	ret