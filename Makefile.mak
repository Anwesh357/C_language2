CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/student.c src/utils.c
OUT = student_system

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)