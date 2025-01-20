all:
	gcc chall.c -no-pie -o chall
	pwninit --no-template
	mv chall_patched chall
	cp ./chall ../dist/
clean:
	rm -f chall
	rm -f ../dist/chall
