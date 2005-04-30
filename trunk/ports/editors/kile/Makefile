COMMENT=		"LaTeX source editor for KDE"

DISTNAME=		kile-1.8b2
CATEGORIES=		editors	

HOMEPAGE=		http://kile.sourceforge.net	
MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

SEPARATE_BUILD=		simple
USE_X11=		Yes
USE_GMAKE=		Yes
CONFIGURE_STYLE=	gnu	

MODULES=		x11/kde

MAKE_ENV=		KDEDIR="${LOCALBASE}"
MAKE_ENV+=		UIC_PATH="${MODQT_UIC}" UIC="${MODQT_UIC}"
MAKE_FLAGS=		${MODKDE_MAKE_FLAGS}

WANTLIB=        ICE SM X11 Xext Xrender art_lgpl_2.0.0 c jpeg m png \
                pthread stdc++ util z

LIB_DEPENDS=    vcard,kdecore.6,DCOP,kabc,kresources,kdefx,kdeprint,kdesu,kdeui,kio,kparts,kwalletclient,khtml,kjs,ktexteditor,kutils,katepartinterfaces,kspell::x11/kde/libs3
LIB_DEPENDS+=	pcre,pcreposix::devel/pcre
RUN_DEPENDS=    :teTeX_base->=3.0:print/teTeX/base

CONFIGURE_ARGS+=	${MODKDE_CONFIGURE_ARGS}
CONFIGURE_ENV=		${MODKDE_CONFIGURE_ENV}

post-install:
	@mv ${WRKINST}/usr/local/share/apps/kile/icons/hicolor ${WRKINST}/usr/local/share/apps/kile/icons/crystalsvg

.include <bsd.port.mk>
