; -----------------------------------------------------------------------------
; Some assembly procedures that get called from the C program.
;
; @author Jacob Schrum, 7/21/2024
; -----------------------------------------------------------------------------

	global fibRecursive
	global mulExample

	section .text
; In parameter in register rdi, 
; Result returned in rax
fibRecursive:
	cmp rdi, 1			; if(rdi > 1) then it is neither 0 nor 1,
	ja recursiveCase	; therefore, we are in a recursive case.
						; Note: ja used because we have an unsigned number.
	mov rax, 1			; base cases for rdi = 0 or 1 both return 1.
	ret
recursiveCase:
	push rdi			; Save parameter rdi before recursive
	dec rdi				; First recursive call is fibRecursive(rdi - 1)
	call fibRecursive	; Now rax = fibRecursive(rdi - 1)
	pop rdi				; Restore original value of rdi
	push rax			; Save rax before second recursive call
	sub rdi, 2			; Second recursive call is for fibRecursive(rdi - 2)
	call fibRecursive	; Now rax = fibRecursive(rdi - 2)
	pop rbx				; Pop old rax onto rbx: rbx = fibRecursive(rdi - 1)
	add rax, rbx		; Now rax = fibRecursive(rdi - 2) + fibRecursive(rdi - 1)
	ret 

; No parameters. Just an example of how to
; use the mul instruction for unsigned 
; (non-negative) 32-bit integers.
; Result returned in rax
mulExample:

	mov eax, 20
	mov ecx, 33

    ; 64 bit result from multiplying two 32 bit ints
	mul ecx  ; EDX:EAX <- EAX * ECX

	; For these small numbers, the result will fit in
	; EAX, and EDX will be zero, but EDX would contain
	; values for larger numbers.

	ret
