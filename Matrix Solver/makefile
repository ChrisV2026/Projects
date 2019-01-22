OBJS = main.o linsolve.o gendata.o checkresult.o
EXE = linsolve
CC = gcc

$(EXE):$(OBJS)
	$(CC) -o $@ ${OBJS}

main.o: main.c
	$(CC) -c $?

linsolve.o:linsolve.c
	$(CC) -c $?

gendata.o:gendata.c
	$(CC) -c $?

checkresult.o:checkresult.c
	$(CC) -c $?

clean:
	rm $(OBJS) $(EXE)
