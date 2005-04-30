COMMENT=		"KDE-based personal finance assistant"

DISTNAME=		kmymoney2-0.6.4	
CATEGORIES=		productivity	

HOMEPAGE=		http://kmymoney2.sourceforge.net/	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_sourceforge:=kmymoney2/}
EXTRACT_SUFX=		.tar.bz2

#BUILD_DEPENDS=		???
#RUN_DEPENDS=		???
#LIB_DEPENDS=		???
#REGRESS_DEPENDS=	???

USE_X11=		Yes
USE_GMAKE=		Yes
CONFIGURE_STYLE=	gnu
#CONFIGURE_ARGS+=	${CONFIGURE_SHARED}

MODULES=                x11/kde

MAKE_ENV=               KDEDIR="${LOCALBASE}"
MAKE_ENV+=              UIC_PATH="${MODQT_UIC}" UIC="${MODQT_UIC}"
MAKE_FLAGS=             ${MODKDE_MAKE_FLAGS}

CONFIGURE_ARGS+=        ${MODKDE_CONFIGURE_ARGS}
CONFIGURE_ENV=          ${MODKDE_CONFIGURE_ENV}

.include <bsd.port.mk>
