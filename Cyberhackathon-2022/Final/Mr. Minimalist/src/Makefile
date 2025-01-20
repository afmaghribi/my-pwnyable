all:
	nasm -f elf64 chall.asm -o chall.o
	ld chall.o -o chall
	cp ./chall ../dist/chall
	rm -rf chall.o

clean:
	rm -f chall
	rm -f ../dist/chall
