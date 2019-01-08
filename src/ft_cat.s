extern buffer
extern write
extern read
%include "src/macros.s"
global ft_cat
ft_cat:
	push RBX					; save RBX
	mov EBX, EDI				; save fd to RBX
.loop:
	mov EDI, EBX				; set arg 1 to fd
	lea RSI, [rel buffer]		; set arg 2 to buffer
	mov RDX, BUFFER_SIZE		; set arg 3 to buffer size
	call read					; call read
	cmp EAX, 0					; check return value
	jle .end					; jump to end if over or error
	mov EDI, STDOUT				; set arg 1 to STDOUT
	lea RSI, [rel buffer]		; set arg 2 to buffer
	mov RDX, RAX				; set arg 3 to previously read len
	call write					; call write
	cmp EAX, 0					; check something was written
	jg .loop					; if yes, start loop again
.end:
	pop RBX						; restore RBX
	ret