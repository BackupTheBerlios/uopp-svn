# $OpenBSD$
COMMENT=		"Website META Language"

DISTNAME=		wml-2.0.9	
CATEGORIES=		www	

HOMEPAGE=		http://www.thewml.org

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://www.thewml.org/distrib/

MODULES=		gettext
LIB_DEPENDS=		png.4::graphics/png

USE_GMAKE=		Yes
CONFIGURE_STYLE=gnu	
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/png"
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"	
.include <bsd.port.mk>
