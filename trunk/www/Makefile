# Makefile for uopp website

DESTDIR=${.CURDIR}/../output
TOPDIR=${.CURDIR}
ROOTDIR=

default: build

generate update:
	@(cd ports; ${MAKE} -I${TOPDIR} DESTDIR=${DESTDIR}/ports TOPDIR=${TOPDIR} ROOTDIR=${ROOTDIR}/.. ${.TARGET});

.include "Makefile.inc"
