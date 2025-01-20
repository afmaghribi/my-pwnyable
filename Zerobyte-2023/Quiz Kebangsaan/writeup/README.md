# Writeup Quiz Kebangsaan

### Main idea
Akses shell menggunakan one_gadget

### How
Ada buffer overflow di input jawaban dan karena menggunakan fungsi `read` yang ngga nambah `null` diakhir input, kita bisa leak canary dan base libc. Setelah dapet semuanya tinggal panggil one_gadget.

### Example
1. Jawaban 1 sepanjang 0x29 untuk leak canary
2. Jawaban 5 sepanjang 0x38 untuk leak libc
3. Jawaban 5 untuk overwrite ret address dengan one_gadget

### Additional Notes