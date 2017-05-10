CFLAGS =-O0 -m32 -g -w -I/usr/local/ssl/include  -I../ -I/usr/local/lib  -I/usr/local/include
LD=-L /usr/lib  -lssl -lcrypto  -L /usr/local/lib/
CC = gcc
CLEANFILES = *.o

all: anti-re

anti-re:
	${CC} ${CFLAGS} -o echoserver_test echoserver.c $(LD)

clean:
	rm -f ${CLEANFILES}
	rm -f ${PROGS}
	rm -f *~

