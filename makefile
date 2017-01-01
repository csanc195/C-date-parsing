# The following makefile builds the programs
# dateParser and dateConverter both independently
# and simultaneously, by using either build1 to
# build dateParser or build2 to build dateConverter,
# or buildall to build both.

CC = gcc

FILES1 = findDates.c validateDate.c
OBJ1 = findDates.o validateDate.o
OUT_EXEC1 = dateParser.out

FILES2 = convertDates.c translateDate.c
OBJ2 = convertDates.o translateDate.o
OUT_EXEC2 = dateConverter.out

build1:$(OBJ1)
	$(CC) $(FILES1) -o $(OUT_EXEC1)

build2:$(OBJ2)
	$(CC) $(FILES2) -o $(OUT_EXEC2)

buildall: build1 build2

clean:	
	rm -f *.o

rebuild: clean	build