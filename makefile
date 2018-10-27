all: main.o work_10.o
	gcc -o out main.o work_10.o

main.o: main.c work_10.h
	gcc -c main.c

work_10.o: work_10.c
	gcc -c work_10.c

run:
	./out

clean:
	rm out
	rm *.o
	rm *.txt
