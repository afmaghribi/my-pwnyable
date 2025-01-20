# Writeup Ez Pwn

### Main idea
Akses shell menggunakan one_gadget

### How
Ada buffer overflow di input jawaban dan karena jumlah maksimal input sepanjang 64 bytes, sedangkan buffer input hanya sebesar 32 bytes. Meskipun ada pengecekan `strlen()` jika input melebihi 32 bytes akan `exit()`, masih bisa dibypass dengan menggunakan `null` bytes.

### Example
1. Input 32 null bytes
2. Isi rbp dengan alamat GOT yang akan dioverwrite dengan one_gadget + `0x20`
3. Selanjutnya tinggal leaks alamat `puts()` kemudian panggil alamat `call puts()`

### Additional Notes