CC=g++
TARGET=main
SRC=$(shell echo *.cpp)
OBJ=$(SRC:$.cpp=$.o)
CFLAGS= -std=c++11
.PHONY:clean
debug:
	$(CC) -g -c $(SRC) $(CFLAGS)
	$(CC) -o $(TARGET) $(OBJ)
release:
	$(CC) -c $(SRC) $(CFLAGS)
	$(CC) -o $(TARGET) $(OBJ)
	make clean
clean:
	rm -fr *.o $(TARGET)
