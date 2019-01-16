OBJS = main.o list.o
EXE = list
CC = gcc

$(EXE):$(OBJS)
	$(CC) -o $@ ${OBJS}

main.o: main.c
	$(CC) -c $?

list.o:list.c
	$(CC) -c $?

clean:
	rm $(OBJS) $(EXE)
