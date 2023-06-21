8080Disassembler: 8080-Disassembler.o
	gcc -o 8080Disassembler 8080-Disassembler.o

8080-Disassembler.o: 8080-Disassembler.c
	gcc -c 8080-Disassembler.c

clean:
		rm -f *.o