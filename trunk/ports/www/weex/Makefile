# $OpenBSD$

COMMENT=		"Non-interactive ftp client"
DISTNAME=		weex-2.6.1.5
CATEGORIES=		www	

HOMEPAGE=		http://weex.sourceforge.net	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=weex/}	

SEPARATE_BUILD=		concurrent
CONFIGURE_STYLE=	gnu	
CONFIGURE_ARGS+=	--without-catgets \
			--without-included-gettext

MODULES=		gettext

DOCS=	AUTHORS BUGS BUGS.ja COPYING COPYING.ja \
	ChangeLog ChangeLog.ja FAQ FAQ.ja README README.ja \
	THANKS TODO TODO.ja

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/weex
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/weex
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/weex
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc \
			${PREFIX}/share/examples/weex

.include <bsd.port.mk>
