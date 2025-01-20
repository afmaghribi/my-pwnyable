all:
	gcc -o chall chall.c
	pwninit --no-template
	mv chall_patched chall
	cp ./chall ../dist/

clean:
	rm -f chall
	rm -f ../dist/chall
