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

%define flag_alpha 0b00000001
%define flag_digit 0b00000010
%define flag_alnum 0b00000100
%define flag_print 0b00001000
%define flag_lower 0b00010000
%define flag_upper 0b00100000
