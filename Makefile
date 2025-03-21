# rxwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c rxwm.c util.c
OBJ = ${SRC:.c=.o}

all: rxwm

.c.o:
	${CC} ${CFLAGS} -c $<


${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

rxwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f rxwm ${OBJ} rxwm-${VERSION}.tar.gz

dist: clean
	mkdir -p rxwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		rxwm.1 drw.h util.h ${SRC} transient.c rxwm-${VERSION}
	tar -cf rxwm-${VERSION}.tar rxwm-${VERSION}
	gzip rxwm-${VERSION}.tar
	rm -rf rxwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f rxwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/rxwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < rxwm.1 > ${DESTDIR}${MANPREFIX}/man1/rxwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/rxwm.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/rxwm\
		${DESTDIR}${MANPREFIX}/man1/rxwm.1

.PHONY: all clean dist install uninstall
