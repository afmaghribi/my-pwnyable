# Writeup SMS

### Main idea
ROP call system("/bin/sh") to gain shell

### How
One byte overflow stack address allocated for next variable to point to rip address. Then overwrite rip address with ROP to call system("/bin/sh"). Since the only available function is only syscall also no `rdx` gadget we need to use `ret2csu` and to set `rcx` can use hidden operation (not visible using decompiler) in function `read`.

### Example
1. Overflow 1 byte in receiver variable
2. Now variable message will overwrite rip address
3. ROP ret2csu + control rcx to leak libc
4. Call main
5. Call system("/bin/sh")

### Additional Notes
Below some constraints i faced during testing the chall:
1. Since stack address is random, only the last byte nibble that always the same. There is 1/16 possibility to make it correctly point to rip address
2. Need to wisely choose overwrite byte for rip address, because on the second call the rip address increased and max rop len is only 0x80