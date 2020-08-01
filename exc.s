;
; Note: this example is written in Intel Assembly syntax
;
[BITS 16]

boot:


	
	mov ax, 0x07C0		; Set up 4K stack space after this bootloader
	add ax, 288		; (4096 + 512) / 16 bytes per paragraph
	mov ss, ax
	mov sp, 4096

	mov ax, 0x07C0		; Set data segment to where we're loaded
	mov ds, ax

	mov ah, 0x0e
	mov bh, 0x00
	mov bl, 0x07


	mov si, mylabel
	
.print: 
	mov ah, 0x0e
	lodsb
	cmp al, 0
	je .repeat
	int 0x10
	jmp .print
	
.repeat:

	mov ah, 0x00
	int 0x16 
	mov ah, 0x0e
	int 0x10
	jmp .repeat


.done:

    jmp $


mylabel db '$#', 0


times 510-($-$$) db 0

db 0x55
db 0xaa
