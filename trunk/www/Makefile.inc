TARGETS+=*.html *.wml *.gif *.png *.jpg *.jpeg *.pdf *.css *.tgz

.SUFFIXES: .html .wml

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
	@wml -o ${DESTDIR}/${.PREFIX}.html -I${TOPDIR} ${.PREFIX}.wml
	@chmod 664 ${DESTDIR}/${.PREFIX}.html

build: _SUBDIRUSE ${TARGETS}

empty-indexes:
	@(cd ${DESTDIR} && for i in $$(find * -type d); do touch $${i}/index.html; done)

tidy:
	@(cd ${DESTDIR} && for i in $$(find * -type f -name "*.html"); do \
	/usr/local/lib/wml/exec/wml_aux_tidy -i -m -utf8 -quiet $${i} 2>&1; done)

linklint:
	@(cd ${DESTDIR} && /usr/local/lib/wml/exec/wml_aux_linklint \
		-textonly -error -warn -silent /\@)

clean:
	@rm -rf ${DESTDIR}

destdir:
	@mkdir -p ${DESTDIR}

upload: tidy empty-indexes
	@(cd ${DESTDIR} && chmod 644 $$(find * -type f) && chmod 755 $$(find * -type d))
 	@rsync --recursive --links --times ${DESTDIR}/ shell.berlios.de:/home/groups/uopp/htdocs/	

upload-destructive: tidy empty-indexes
	@(cd ${DESTDIR} && chmod 644 $$(find * -type f) && chmod 755 $$(find * -type d) )
	@rsync --recursive --links --times --delete \
		${DESTDIR}/ shell.berlios.de:/home/groups/uopp/htdocs/

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

${TAGS} current: clean-ports make-wml templates 

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
                PORTSDIR_VERSION=${.TARGET} \
                BASE_INPUTDIR=${TOPDIR}/../ports/current/uopp \
                BASE_OUTPUTDIR=${TOPDIR}/ports/current/uopp \
                BASE_ROOTPATH=/ports/current/uopp \
                TREE_ROOTPATH=/ports/current \
                TGZ=1 \
                P2WDIR=${P2WDIR} \
                ./make-wml)
