# $OpenBSD: Makefile$

COMMENT=		"Extremely scalable, statistical-hybrid anti-spam filter"

DISTNAME=	 	dspam-3.2.2
CATEGORIES=		mail

HOMEPAGE=		http://www.nuclearelephant.com/projects/dspam/	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://dspam.nuclearelephant.com/sources/ \
			http://dspam.irontec.com/sources/	

#BUILD_DEPENDS=		???
#RUN_DEPENDS=		???
LIB_DEPENDS=		sqlite.8::databases/sqlite

CONFIGURE_STYLE=	gnu	
CONFIGURE_ARGS+=	${CONFIGURE_SHARED} \
			--with-storage-driver=sqlite_drv \
			--with-dspam-home=/var/dspam \
			--with-sqlite-includes=/usr/local/include \
			--with-sqlite-libraries=/usr/local/lib \
			--with-dspam-group=wheel
		
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dspam
	${INSTALL_DATA} ${WRKINST}/etc/dspam.conf ${PREFIX}/share/examples/dspam/dspam.conf
	${INSTALL_DATA} ${WRKSRC}/tools.sqlite_drv/purge.sql ${PREFIX}/share/examples/dspam/purge.sql
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dspam/txt
	${INSTALL_DATA} ${WRKSRC}/txt/*.txt ${PREFIX}/share/examples/dspam/txt/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dspam
	${INSTALL_DATA} ${WRKSRC}/tools.sqlite_drv/README ${PREFIX}/share/doc/dspam/README.sqlite
		
.include <bsd.port.mk>
