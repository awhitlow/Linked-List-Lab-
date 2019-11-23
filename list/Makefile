#list/Makefile
#
#Makefile for list implementation and test file
#
# <Author>
# Alexandria Whitlow
#alswhitlow@gmail.com

CC=gcc
CFLAGS = -I -std=c99 
DEPS = list.h
OBJ = list.c main.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)