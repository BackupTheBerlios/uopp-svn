# $OpenBSD$

COMMENT=	"collection of tools for managing UNIX services"

DISTNAME=	daemontools-0.76
CATEGORIES=	sysutils	
MAINTAINER=	Thomas Delaet <thomas@delaet.org>	
HOMEPAGE=	http://cr.yp.to/daemontools.html
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://ftp.id.wustl.edu/pub/qmail/
WRKDIST=	${WRKDIR}/admin/daemontools-0.76

PERMIT_PACKAGE_CDROM=	No
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

do-build:
	cd ${WRKDIST} && \
	ksh package/compile
do-install:
	cd ${WRKDIST}/command && \
	install -g wheel -o root * ${WRKINST}${LOCALBASE}/bin/	

.include <bsd.port.mk>
