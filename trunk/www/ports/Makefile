
RELEASES=3.4 3.5 3.6

P2WDIR=${TOPDIR}/../src/p2w

update:
.for i in ${RELEASES}
	@(cd ${TOPDIR}/../ports/${i} && cvs -q update -dP)
.endfor
	@(cd ${TOPDIR}/../ports/current && cvs -q update -dP)
	@(cd ${TOPDIR}/../ports/current/mystuff && svn update)

#generate: ${RELEASES} current unofficial templates
generate: clean current templates

${RELEASES} current:
	@mkdir -p ${.TARGET}
	@(cd ${P2WDIR} && PORTSDIR=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_PATH=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_VERSION=${.TARGET} \
		BASE_INPUTDIR=${TOPDIR}/../ports/${.TARGET}/archivers \
		BASE_OUTPUTDIR=${TOPDIR}/ports/${.TARGET}/archivers \
		BASE_ROOTPATH=/ports/${.TARGET}/archivers \
		P2WDIR=${P2WDIR} \
		./make-wml) 

templates:
	@for i in $$(find * -type d); \
	do \
		cp Makefile.template $$i/Makefile; \
	done

unofficial:
	@mkdir -p ${.TARGET}
	@(cd ${TOPDIR}/../ports/current/mystuff && make \
		PORTSDIR=`pwd`/.. \
		PORTSDIR_PATH=${TOPDIR}/../ports/current/mystuff:${TOPDIR}/../ports/current \
		PORTS_BRANCH=${.TARGET} \
		WMLDIR=${TOPDIR}/ports/current/mystuff TGZ= wml)

clean:
	@rm -rf ${RELEASES} current

.include "Makefile.inc"
