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

WANTLIB=        ICE SM X11 Xext Xrender c m art_lgpl_2.0.0 \
                pthread stdc++ util z jpeg png iconv xml2

LIB_DEPENDS=	kdeprint,kdesu,kdefx,kdeui,kparts,kio,kutils,kdecore,DCOP,kwalletclient,kjs,khtml::x11/kde/libs3
LIB_DEPENDS+=   pcre,pcreposix::devel/pcre


USE_X11=		Yes
USE_GMAKE=		Yes
CONFIGURE_STYLE=	gnu

MODULES=                x11/kde

MAKE_ENV=               KDEDIR="${LOCALBASE}"
MAKE_ENV+=              UIC_PATH="${MODQT_UIC}" UIC="${MODQT_UIC}"
MAKE_FLAGS=             ${MODKDE_MAKE_FLAGS}

CONFIGURE_ARGS+=        ${MODKDE_CONFIGURE_ARGS}
CONFIGURE_ENV=          ${MODKDE_CONFIGURE_ENV}

post-install:
	@mv ${WRKINST}/usr/local/share/apps/kmymoney2/icons/hicolor ${WRKINST}/usr/local/share/apps/kmymoney2/icons/crystalsvg
	@mv ${WRKINST}/usr/local/share/icons/hicolor ${WRKINST}/usr/local/share/icons/crystalsvg

.include <bsd.port.mk>
