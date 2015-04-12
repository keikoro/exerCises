# Makefile for file programs
# part of exerCises

CC=gcc
CFLAGS = -Wall -Werror -g -O -std=c99

all: openafile opendifferentfiles openfilewithargument createfile

openafile: 01_openafile.o
	${CC} ${CFLAGS} -o $@ $<
opendifferentfiles: 02_opendifferentfiles.o
	${CC} ${CFLAGS} -o $@ $<
openfilewithargument: 03_openfilewithargument.o
	${CC} ${CFLAGS} -o $@ $<
createfile: 04_createfile.o
	${CC} ${CFLAGS} -o $@ $<
%.o: %.c
	${CC} ${CFLAGS} -c $<

dist:
	mkdir files
	cp *.c files/
	cp Makefile files/
	tar -cvzf files.tgz files

distclean:
	rm files.tgz
	rm -r files

clean_o:
	rm -f *.o

clean:
	rm -f openafile opendifferentfiles openfilewithargument createfile
	rm -f *.o
# rm dSYM dirs created on Mac
# don't output this line on the command line (@)
	@rm -r -f *.dSYM
