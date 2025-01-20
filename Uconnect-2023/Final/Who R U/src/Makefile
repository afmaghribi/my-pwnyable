all:
	gcc chall.c -no-pie -Wl,-z,norelro -o chall
	cp ./chall ../dist/chall
clean:
	rm -f chall
	rm -f ../dist/chall
