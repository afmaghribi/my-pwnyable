# Mr. Simple
Program merupakan sebuah binary ELF 64 bit

## Deskripsi
Apakah kalian bisa melakukan eksploitasi pada program yang sangat sederhana ini?

## Hint
- Ret2csu
- Ret2libc

## Techincal Information
- Sebenarnya sama seperti ret2libc biasa lainnya. Tapi karena fungsi yang tersedia sedikit, maka perlu menggunakan teknik ret2csu
- Alur eksploitasi seperti biasa, Buffer Overflow -> Leak base address -> call system("/bin/sh")