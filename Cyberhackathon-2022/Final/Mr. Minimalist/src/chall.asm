section .text
global _start

; read function
read:
    mov eax, 0x0            ; syscall number for read
    mov edi, 0x0            ; file descriptor (stdin)
    mov rsi, [rsp + 0x8]    ; buffer to read into
    mov rdx, [rsp + 0x10]   ; number of bytes to read
    syscall                 ; invoke the system call
    ret                     ; return from function

; write function
write:
    mov eax, 0x1            ; syscall number for write
    mov edi, 0x1            ; file descriptor (stdout)
    mov rsi, [rsp + 0x8]    ; buffer to write from
    mov rdx, [rsp + 0x10]   ; number of bytes to write
    syscall                 ; invoke the system call
    ret                     ; return from function

; vuln function
vuln:
    push rbp                ; save base pointer
    mov rbp, rsp            ; set up stack frame
    sub rsp, 0x50           ; allocate 80 bytes on the stack
    mov r10, rsp            ; store the buffer address in r10
    push 0x300              ; push the size (768 bytes)
    push r10                ; push the buffer address
    call read               ; call the read function
    push rax                ; save the return value of read
    push r10                ; push the buffer address
    call write              ; call the write function
    leave                   ; restore stack frame
    ret                     ; return from function

; program entry point
_start:
    call vuln               ; call the vuln function
    jmp _start              ; infinite loop

