OLD_RELEASE="3.4"
NEW_RELEASE="3.5"

TARGETS+=${OLD_RELEASE} ${NEW_RELEASE} current unofficial templates

${OLD_RELEASE} ${NEW_RELEASE} current:
	@mkdir -p ${.TARGET} 
	@(cd ${TOPDIR}/../ports/${.TARGET} && cvs -q update -dP && make \
		PORTSDIR=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_PATH=${TOPDIR}/../ports/${.TARGET} \
		VERSION=${.TARGET} \
		WMLDIR=`pwd` wml)

templates:
	@for i in $$(find * -type d); \
	do \
		cp Makefile.template $$i/Makefile; \
	done

unofficial:
	@mkdir -p ${.TARGET}
	@(cd ${TOPDIR}/../ports/current/mystuff && svn update && make \
		PORTSDIR=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_PATH=${TOPDIR}/../ports/current/mystuff:${TOPDIR}/../ports/current \
		VERSION=${.TARGET} \
		WMLDIR=`pwd`/mystuff TGZ= wml)

clean:
	@rm -rf ${OLD_RELEASE} ${NEW_RELEASE} current

.include "Makefile.inc"
