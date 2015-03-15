# Makefile for fork programs
# part of exerCises

CC=gcc
CFLAGS = -Wall -Werror -g -O -std=c99

all: mostbasicfork waitforchild helloworld waitandkill threechildren \
		threewaitingchildren

mostbasicfork: 01_mostbasicfork.o
	${CC} ${CFLAGS} -o $@ $<
waitforchild: 02_waitforchild.o
	${CC} ${CFLAGS} -o $@ $<
helloworld: 03_helloworld.o
	${CC} ${CFLAGS} -o $@ $<
waitandkill: 04_waitandkill.o
	${CC} ${CFLAGS} -o $@ $<
threechildren: 05_threechildren.o
	${CC} ${CFLAGS} -o $@ $<
threewaitingchildren: 06_threewaitingchildren.o
	${CC} ${CFLAGS} -o $@ $<
%.o: %.c
	${CC} ${CFLAGS} -c $<

dist:
	mkdir forks
	cp *.c forks/
	cp Makefile forks/
	tar -cvzf forks.tgz forks

distclean:
	rm forks.tgz
	rm -r forks

clean_o:
	rm -f *.o

clean:
	rm -f mostbasicfork waitforchild helloworld waitandkill threechildren \
		threewaitingchildren
	rm -f *.o
# rm dSYM dirs created on Mac
# don't output this line on the command line (@)
	@rm -r -f *.dSYM
