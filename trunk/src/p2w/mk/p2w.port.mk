# Ports 2 www port make-file

WMLTEMPLATES ?= ${P2WDIR}/templates
WMLTEMPLATE=${WMLTEMPLATES}/wml.port

_print-wmlfile:
.if ${_FULL_PACKAGE_NAME:L} == "yes"
	@echo '${PKGPATH}/${FULLPKGNAME${SUBPACKAGE}}'
.else
	@echo ${FULLPKGNAME${SUBPACKAGE}}
.endif


wml:
.if defined(MULTI_PACKAGES) && !defined(PACKAGING)
	@cd ${.CURDIR} && SUBPACKAGE='${SUBPACKAGE}' FLAVOR='${FLAVOR}' PACKAGING='${SUBPACKAGE}' exec ${MAKE} wml
.  if empty(SUBPACKAGE)
.    for _sub in ${MULTI_PACKAGES}
	@cd ${.CURDIR} && SUBPACKAGE='${_sub}' FLAVOR='${FLAVOR}' PACKAGING='${_sub}' exec ${MAKE} wml
.    endfor
.  endif
.else
	@mkdir -p ${WMLDIR}/${PKGPATH}
	@rm -f ${WMLDIR}/${PKGPATH}/${FULLPKGNAME${SUBPACKAGE}}.html
	@cd ${.CURDIR} && exec ${MAKE} ${FULLPKGNAME${SUBPACKAGE}}.html
.endif


${FULLPKGNAME${SUBPACKAGE}}.html:
	@echo ${_COMMENT} | ${HTMLIFY} >$@.tmp-comment
	@echo ${FULLPKGNAME${SUBPACKAGE}} | ${HTMLIFY} > $@.tmp3
.if defined(HOMEPAGE)
	@echo 'See <a href="${HOMEPAGE}">${HOMEPAGE}</a> for details.' >$@.tmp4
.else
	@echo "" >$@.tmp4
.endif
.if defined(MULTI_PACKAGES) 
.  if empty(SUBPACKAGE)
	@echo "<h2>Subpackages</h2>" >$@.tmp-subpackages
	@echo "<ul>" >>$@.tmp-subpackages

.    for _S in ${MULTI_PACKAGES}
	@name=`SUBPACKAGE=${_S} ${MAKE} _print-wmlfile _FULL_PACKAGE_NAME=No`; \
	echo "<li><a href=\"$$name.html\">$$name</a>" >>$@.tmp-subpackages
.    endfor
	@echo "</ul>" >>$@.tmp-subpackages
.  else
	@name=`unset SUBPACKAGE; ${MAKE} _print-wmlfile _FULL_PACKAGE_NAME=No`; \
	echo "<h2>Subpackage of <a href=\"$$name.html\">$$name</a></h2>" >$@.tmp-subpackages
.  endif
.else
	@>$@.tmp-subpackages
.endif
.for _I in build run
.  if !empty(_ALWAYS_DEP) || !empty(_${_I:U}_DEP)
	@cd ${.CURDIR} && ${MAKE} full-${_I}-depends _FULL_PACKAGE_NAME=Yes| \
		while read n; do \
			j=`dirname $$n|${HTMLIFY}`; k=`basename $$n|${HTMLIFY}`; \
			echo "<li><a href=\"${PKGDEPTH}$$j/$$k.html\">$$k</a>"; \
		 done  >$@.tmp-${_I}
.  else
	@echo "<li>none" >$@.tmp-${_I}
.  endif
.endfor
	@cat ${WMLTEMPLATE} | \
		sed -e 's|%%PORT%%|'"`echo ${FULLPKGPATH}  | ${HTMLIFY}`"'|g' \
			-e '/%%PKG%%/r$@.tmp3' -e '//d' \
			-e '/%%COMMENT%%/r$@.tmp-comment' -e '//d' \
			-e '/%%DESCR%%/r${PKGDIR}/DESCR${SUBPACKAGE}' -e '//d' \
			-e '/%%HOMEPAGE%%/r$@.tmp4' -e '//d' \
			-e '/%%BUILD_DEPENDS%%/r$@.tmp-build' -e '//d' \
			-e '/%%RUN_DEPENDS%%/r$@.tmp-run' -e '//d' \
 			-e '/%%SUBPACKAGES%%/r$@.tmp-subpackages' -e '//d' \
		>> ${WMLDIR}/${PKGPATH}/$@
	@rm -f $@.tmp*
