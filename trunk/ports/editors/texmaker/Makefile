# $OpenBSD$
# $FreeBSD: /repoman/r/pcvs/ports/editors/texmaker/Makefile,v 1.2 2004/01/09 09:16:33 krion Exp $
# Original from: ports@FreeBSD.org

COMMENT=		"LaTeX Development Environment"
DISTNAME=		texmaker-1.11	
CATEGORIES=		editors	

HOMEPAGE=		http://www.xm1math.net/texmaker/index.html	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes 
PERMIT_DISTFILES_CDROM=Yes
PERMIT_DISTFILES_FTP=	Yes 

MASTER_SITES=		http://www.xm1math.net/texmaker/			
EXTRACT_SUFX=		.tar.bz2

MODULES=		qt3
MODQT_MT=		Yes

do-configure:
	@cd ${WRKSRC} && \
	qmake-mt -makefile \
		-spec ${MODQT_LIBDIR}/mkspecs/openbsd-g++ \
		-unix \
		"LIBS+=-L/usr/local/lib -lm -lqt-mt" \
		"PREFIX=${LOCALBASE}" \
		"INCLUDEPATH+=${MODQT_INCDIR}" \
		"UIC=${MODQT_UIC}" \
		"MOC=${MODQT_MOC}" \
		texmaker.pro && \
	cp Makefile Makefile.orig
pre-build:
	@cd ${WRKSRC} && \
	cat Makefile.orig | sed -e 's| -lqt | -lpthread |' > Makefile
	
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texmaker ${PREFIX}/bin
	cp -Rp ${WRKSRC}/utilities ${PREFIX}/share/texmaker
.include <bsd.port.mk>
