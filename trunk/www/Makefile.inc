TARGETS+=*.html *.wml *.gif *.png *.jpg *.jpeg *.pdf *.css *.tgz

.SUFFIXES: .html .wml

_SUBDIRUSE: .USE
	@for subdir in $$(find . -type d -maxdepth 1 -mindepth 1 | grep -v .svn | cut -d"/" -f2 ); \
	do \
		(cd $$subdir; \
		${MAKE} -I${TOPDIR} \
			DESTDIR=${DESTDIR}/$$subdir \
			TOPDIR=${TOPDIR} \
			ROOTDIR=${ROOTDIR}/.. \
		${.TARGET} \
		); \
	done

*.html *.css *.gif *.png *.jpg *.jpeg *.pdf *.tgz: destdir
	@cp -p ${.TARGET} ${DESTDIR}/${.TARGET}
	@chmod 664 ${DESTDIR}/${.TARGET}

*.wml: destdir
	@wml -o ${DESTDIR}/${.PREFIX}.html -I${TOPDIR} -DROOT=${ROOTDIR} ${.PREFIX}.wml
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
	@(cd ${DESTDIR} && chmod 644 $$(find * -type f) && chmod 755 $$(find * -type d) )
	@rsync --recursive --links --times --delete --exclude=usage \
		${DESTDIR}/ shell.berlios.de:/home/groups/uopp/htdocs/
