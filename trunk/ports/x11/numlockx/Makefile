# $OpenBSD$

COMMENT=		"This little thingy allows you to start X with NumLock turned on"

VERSION=		1.0
DISTNAME=		numlockx-${VERSION}
CATEGORIES=		x11	

HOMEPAGE=		http://ktown.kde.org/~seli/numlockx/	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://caraldi.com/jbq/numlockx/ \
		http://ktown.kde.org/~seli/numlockx/	

SEPARATE_BUILD=		concurrent
CONFIGURE_STYLE=	gnu
USE_X11=		Yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include"
DOCS=			LICENSE README TODO AUTHORS

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/doc/numlockx
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/doc/numlockx/
.endfor

.include <bsd.port.mk>
