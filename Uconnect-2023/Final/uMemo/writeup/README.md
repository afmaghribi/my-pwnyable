# uMemo | Pwn

## Proof of Concept
- No null after free -> use after free
- flag store on random index 10-49
- bruteforce delete (free) then allocate new chunks using same memory, then overwrite first 16 bytes without null, then print the content