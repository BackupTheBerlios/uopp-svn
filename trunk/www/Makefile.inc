TARGETS+=*.html *.wml *.gif *.png *.jpg *.jpeg *.pdf *.css *.tgz

.SUFFIXES: .html .wml

.PHONY: upload empty-indexes tidy linklint permissions

_SUBDIRUSE: .USE
	@for subdir in $$(find . -type d -maxdepth 1 -mindepth 1 | grep -v .svn | cut -d"/" -f2 ); \
	do \
		(cd $$subdir; \
		${MAKE} -I${TOPDIR} \
			DESTDIR=${DESTDIR}/$$subdir \
			TOPDIR=${TOPDIR} \
		${.TARGET} \
		); \
	done

*.html *.css *.gif *.png *.jpg *.jpeg *.pdf *.tgz: destdir
	@cp -p ${.TARGET} ${DESTDIR}/${.TARGET}
	@chmod 664 ${DESTDIR}/${.TARGET}

*.wml: destdir
	@wml -I${TOPDIR} ${.PREFIX}.wml > ${DESTDIR}/${.PREFIX}.html
	@chmod 664 ${DESTDIR}/${.PREFIX}.html

build: _SUBDIRUSE ${TARGETS}

empty-indexes:
	@(cd ${DESTDIR} && find * -type d | xargs -I NAME touch NAME/index.html)

tidy:
	@(cd ${DESTDIR} && (find * -type f -name "*html" | xargs -I NAME \
	/usr/local/lib/wml/exec/wml_aux_tidy -q -i -config ${TOPDIR}/tidy_config -m NAME 2>&1) \
	|| true)

linklint:
	@(cd ${DESTDIR} && /usr/local/lib/wml/exec/wml_aux_linklint \
		-textonly -error -silent /\@)

clean:
	@rm -rf ${DESTDIR}

destdir:
	@mkdir -p ${DESTDIR}

permissions:
	@(cd ${DESTDIR} && find * -type f | xargs chmod 644 && find * -type d | xargs chmod 755) 

upload: tidy empty-indexes permissions
	@(rsync -q --progress --recursive ${DESTDIR}/ \
	shell.berlios.de:/home/groups/uopp/htdocs/)

####### Ports section

TAGS=3.4 3.5 3.6
P2WDIR=${TOPDIR}/../src/p2w

clean-ports: .USE
	@rm -rf ports/${.TARGET}

update-cvs: .USE
	@(cd ${TOPDIR}/../ports/${.TARGET} && cvs -q -d anoncvs@anoncvs.at.openbsd.org:/cvs update -dP)

make-wml: .USE
	@mkdir -p ports/${.TARGET}
	@(cd ${P2WDIR} && PORTSDIR=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_PATH=${TOPDIR}/../ports/${.TARGET} \
		PORTSDIR_VERSION=${.TARGET} \
		BASE_INPUTDIR=${TOPDIR}/../ports/${.TARGET} \
		BASE_OUTPUTDIR=${TOPDIR}/ports/${.TARGET} \
		BASE_ROOTPATH=/ports/${.TARGET} \
		TREE_ROOTPATH=/ports/${.TARGET} \
		P2WDIR=${P2WDIR} \
		./make-wml)

update-unofficial:
	@(cd ${TOPDIR}/../ports/current/uopp && svn update)

clean-unofficial:
	@rm -rf ports/current/uopp

${TAGS} current: clean-ports update-cvs make-wml templates 

unofficial: clean-unofficial update-unofficial make-wml-unofficial templates-unofficial snapshot

generate: ${TAGS} current unofficial

snapshot:
	@(cd ports && rm -rf uopp) 
	@(cd ports && svn export svn://svn.berlios.de/uopp/trunk/ports uopp)
	@(cd ports && tar -czf uopp-snapshot.tgz uopp)
	@(cd ports && rm -rf uopp)

templates: .USE
	@for i in $$(find ports/${.TARGET} -type d); \
	do \
		cp ports/Makefile.template $$i/Makefile; \
	done

templates-unofficial:
	@for i in $$(find ports/current/uopp -type d); \
	do \
		cp ports/Makefile.template $$i/Makefile; \
	done

make-wml-unofficial:
	@mkdir -p ${TOPDIR}/ports/current/uopp
	@(cd ${P2WDIR} && PORTSDIR=${TOPDIR}/../ports/current \
		PORTSDIR_PATH=${TOPDIR}/../ports/current/uopp:${TOPDIR}/../ports/current \
                PORTSDIR_VERSION=unofficial \
                BASE_INPUTDIR=${TOPDIR}/../ports/current/uopp \
                BASE_OUTPUTDIR=${TOPDIR}/ports/current/uopp \
                BASE_ROOTPATH=/ports/current/uopp \
                TREE_ROOTPATH=/ports/current \
                TGZ=1 \
                P2WDIR=${P2WDIR} \
                ./make-wml)
