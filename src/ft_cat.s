extern buffer
%include "src/macros.s"
global ft_cat
ft_cat:
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
