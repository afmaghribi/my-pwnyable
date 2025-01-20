all:
	gcc -o chall chall.c
	pwninit --no-template
	mv chall_patched chall
	cp ./chall ../dist/
	cp ./libc.so.6 ../dist/
	cp ./ld-linux-x86-64.so.2 ../dist/
clean:
	rm -f chall
	rm -f ../dist/chall
