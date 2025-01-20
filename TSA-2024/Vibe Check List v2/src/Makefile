all:
	gcc -o chall chall.c -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -pie -fPIE -Wl,-z,relro,-z,now
	pwninit --no-template
	mv chall_patched chall
	cp ./chall ../dist/
	cp ./libc.so.6 ../dist/
	cp ./ld-linux-x86-64.so.2 ../dist/
clean:
	rm -f chall
	rm -f ../dist/chall
