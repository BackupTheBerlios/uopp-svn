
RELEASES=3.4 3.5 3.6

P2WDIR=${TOPDIR}/../src/p2w

update:
.for i in ${RELEASES}
	@(cd ${TOPDIR}/../ports/${i} && cvs -q update -dP)
.endfor
	@(cd ${TOPDIR}/../ports/current && cvs -q update -dP)
	@(cd ${TOPDIR}/../ports/current/mystuff && svn update)

#generate: ${RELEASES} current unofficial templates
generate: clean unofficial templates

${RELEASES} current:
	@mkdir -p ${.TARGET}
	@(cd ${P2WDIR} && PORTSDIR=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_PATH=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_VERSION=${.TARGET} \
		BASE_INPUTDIR=${TOPDIR}/../ports/${.TARGET} \
		BASE_OUTPUTDIR=${TOPDIR}/ports/${.TARGET} \
		BASE_ROOTPATH=/ports/${.TARGET} \
		TREE_ROOTPATH=/ports/${.TARGET} \
		P2WDIR=${P2WDIR} \
		./make-wml) 

templates:
	@for i in $$(find * -type d); \
	do \
		cp Makefile.template $$i/Makefile; \
	done

unofficial:
	@mkdir -p ${TOPDIR}/../ports/current/mystuff
	@(cd ${P2WDIR} && PORTSDIR=${TOPDIR}/../ports/current \
		PORTSDIR_PATH=${TOPDIR}/../ports/current/mystuff:${TOPDIR}../ports/current
                PORTSDIR_VERSION=${.TARGET} \
                BASE_INPUTDIR=${TOPDIR}/../ports/current/mystuff \
                BASE_OUTPUTDIR=${TOPDIR}/ports/current/mystuff \
                BASE_ROOTPATH=/ports/current/mystuff \
                TREE_ROOTPATH=/ports/current \
                TGZ=1 \
                P2WDIR=${P2WDIR} \
                ./make-wml)
clean:
	@rm -rf ${RELEASES} current

.include "Makefile.inc"
