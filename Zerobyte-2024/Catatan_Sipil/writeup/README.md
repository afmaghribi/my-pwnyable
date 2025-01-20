# Writeup Catatan Sipil

### Main idea
Isi free_hook dengan `system` lalu `free("/bin/sh")` untuk dapat akses shell

### How
Ada heap overflow 9 bytes karena panjang input sesuai actual size `malloc()`. Penuhin tcache bins sampai masuk unsorted bin untuk leak libc. Kemudian overwrite fd dengan free_hook. Karena ga ada menu edit, cara exploitnya kita maininin prev_size and prev_in_use untuk tcache poisoning.

### Example
1. Buat 0x90 chunk 8 kali, freed ke 8 masuk unsorted bin
2. Leak libc dan heap base
3. Buat tchache dengan 2 bins
4. Overwrite `fd` kedua bins dengan `free_hook`
5. Alokasi chunk lain, isi dengan `/bin/sh`
6. `free()` untuk dapet shell

### Additional Notes