# Ports 2 www subdir make-file

WMLDIR ?= ${PORTSDIR}/wml

wml:
	@${_subdir_fragment}
	@mkdir -p ${WMLDIR}/${PKGPATH}
	@rm -f ${WMLDIR}/${PKGPATH}/index.html
	@cd ${.CURDIR} && exec ${MAKE} index.html

WMLTEMPLATES ?= ${P2WDIR}/templates
.if defined(PORTSTOP)
WMLTEMPLATE=${WMLTEMPLATES}/wml.top
.else
WMLTEMPLATE=${WMLTEMPLATES}/wml.category
.endif

index.html:
	@>$@.tmp
.for d in ${_FULLSUBDIR}
	@dir=$d; ${_flavor_fragment}; \
	name=`eval $$toset ${MAKE} _print-wmlfile`; \
	case $$name in \
		index) comment='';; \
		*) comment=`eval $$toset ${MAKE} show=_COMMENT|sed -e 's,^",,' -e 's,"$$,,' |${HTMLIFY}`;; \
	esac; \
	cd ${.CURDIR}; \
	echo "<dt><a href=\"${PKGDEPTH}$$dir/$$name.html\">$d</a><dd>$$comment" >>$@.tmp
.endfor
	@cat ${WMLTEMPLATE} | \
		sed -e 's%%CATEGORY%%'`echo ${.CURDIR} | sed -e 's.*/\([^/]*\)$$\1'`'g' \
			-e '/%%DESCR%%/r${.CURDIR}/pkg/DESCR' -e '//d' \
			-e '/%%SUBDIR%%/r$@.tmp' -e '//d' \
		> ${WMLDIR}/${PKGPATH}/$@
	@rm $@.tmp

_print-wmlfile:
	@echo "index"
