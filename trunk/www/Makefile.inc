TARGETS+=*.wml *.gif *.png *.jpg *.jpeg *.pdf *.css

.SUFFIXES: .html .wml

_SUBDIRUSE: .USE
	@for subdir in $$(find . -type d -maxdepth 1 -mindepth 1 | cut -d"/" -f2); \
	do \
		(cd $$subdir; \
		${MAKE} -I${TOPDIR} \
			DESTDIR=${DESTDIR}/$$subdir \
			TOPDIR=${TOPDIR} \
			ROOTDIR=${ROOTDIR}/.. \
		${.TARGET} \
		); \
	done

*.css *.gif *.png *.jpg *.jpeg *.pdf: destdir
	@cp -Rp ${.TARGET} ${DESTDIR}/${.TARGET}
	@chmod 664 ${DESTDIR}/${.TARGET}

*.wml: destdir
	@wml -o ${DESTDIR}/${.PREFIX}.html -DROOT=${ROOTDIR} ${.PREFIX}.wml
	@chmod 664 ${DESTDIR}/${.PREFIX}.html

build: _SUBDIRUSE ${TARGETS}

clean:
	@rm -rf ${DESTDIR}

destdir:
	@mkdir -p ${DESTDIR}

upload: build
	@(cd ${DESTDIR} && chmod 644 $$(find * -type f) && chmod 755 $$(find * -type d) )
	@rsync --recursive --links --times --delete --exclude=usage \
		${DESTDIR}/ shell.berlios.de:/home/groups/uopp/htdocs/
