# Writeup Sistem Anti Hek

### Main idea
Isi free_hook dengan system lalu free("/bin/sh") untuk dapat akses shell

### How
Setelah free pointer tidak di null jadi kita bisa leak alamat libc dan heap. Setelah leak kita bisa gunakan format string attack untuk mengubah fd jadi free_hook lalu isi dengan system. Kemudian panggil free yang berisi string "/bin/sh" untuk mendapatkan akses shell.

### Example
1. Buat 8 user lalu hapus agar masuk ke unsortedbin untuk leak libc
2. Leak heap lalu hitung alamat fd yang ingin diubah menjadi alamat free_hook
3. Isi free_hook dengan system
4. Buat user baru "/bin/sh" lalu free

### Additional Notes
1. Dengan memanfaatkan off-by-one pada input username, maka panjang payload maksimal untuk format string attack 64 bytes.