target: main.o linkedlist.o
	gcc -lstdc++ -o main main.o linkedlist.o

main.o: main.cpp
	gcc -c -o main.o main.cpp

linkedlist.o: linkedlist.cpp
	gcc -c -o linkedlist.o linkedlist.cpp

clean:
	rm -f main *.o
