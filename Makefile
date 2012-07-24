CC     = gcc
CFLAGS = -Wall -pedantic -O3
LIBS   = -lm `pkg-config --cflags opencv` `pkg-config --libs opencv`
PREFIX = /usr/bin
TOOL   = vlen
DOCDIR = /usr/share/doc/${TOOL}
MAN    = /usr/share/man/man1

all:
	mkdir -p bin
	${CC} ${CFLAGS} ${LIBS} src/main.c -o bin/${TOOL}
	strip --strip-all bin/${TOOL}

clean:
	rm -f bin/${TOOL}

help:
	@echo make			: build ${TOOL}
	@echo make clean	: purge the folder from previous built
	@echo make install	: install ${TOOL} and doc files
	@echo make uninstall: uninstall ${TOOL} and doc files

install:
	install -s bin/${TOOL} ${PREFIX}
	mkdir -p ${DOCDIR}
	chmod 755 ${DOCDIR}
	install -m 644 -t ${DOCDIR} CHANGELOG LICENSE README REQUIREMENTS
	install -m 644 -t ${MAN} ${TOOL}.1.gz

uninstall:
	rm -f ${PREFIX}/${TOOL}
	rm -rdf ${DOCDIR}
	rm -f ${MAN}/${TOOL}.1.gz