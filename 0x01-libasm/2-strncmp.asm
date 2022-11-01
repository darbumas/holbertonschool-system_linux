BITS 64

	global asm_strncmp

asm_strncmp:
	push rbp
	mov rbp, rsp

	mov R8, 0h
	mov R9, 0h

asm_loop:
	mov al, [rdi + R9]
	mov bl, [rsi + R9]

	cmp R9, rdx
	je asm_end

	cmp al, bl
	je equal_char
	jl al_big
	jg bl_big

equal_char:
	cmp al, 0h
	mov R8, 0
	je asm_end

	inc R9
	jmp asm_loop

al_big:
	inc R9
	neg R9
	mov R8, R9
	jmp asm_end

bl_big:
	inc R9
	mov R8, R9
	jmp asm_end

asm_end:
	mov rax, R8
	mov rsp, rbp
	pop rbp
	ret
