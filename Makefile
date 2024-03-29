PREFIX  := /usr/local
CC      := cc
CFLAGS  := -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS := -lX11
DEFINE	:=

ifneq (, $(shell which nvidia-smi))
	DEFINE := ${DEFINE} -DNVIDIA_SMI=1
endif
# FreeBSD (uncomment)
#LDFLAGS += -L/usr/local/lib -I/usr/local/include
# # OpenBSD (uncomment)
#LDFLAGS += -L/usr/X11R6/lib -I/usr/X11R6/include

all: options dwmblocks

options:
	@echo dwmblocks build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC      = ${CC}"
	@echo "DEFINE  = ${DEFINE}"

dwmblocks: dwmblocks.c blocks.def.h blocks.h
	${CC} -o dwmblocks dwmblocks.c ${CFLAGS} ${LDFLAGS} ${DEFINE}

blocks.h:
	cp blocks.def.h $@

clean:
	rm -f *.o *.gch dwmblocks blocks.h

install: dwmblocks
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwmblocks ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwmblocks
	for script in bin/*; do cp -f $$script ${DESTDIR}${PREFIX}/bin; chmod 755 ${DESTDIR}${PREFIX}/$$script; done

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwmblocks
	for script in bin/*; do rm -f ${DESTDIR}${PREFIX}/$$script; done

.PHONY: all options clean install uninstall
