COMMENT=		"secure, reliable, efficient, simple MTA"

DISTNAME=	 	qmail-1.03	
CATEGORIES=		mail	

HOMEPAGE=		http://cr.yp.to/qmail.html	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

PERMIT_PACKAGE_CDROM=	Copyright	
PERMIT_PACKAGE_FTP=	Copyright	
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://cr.yp.to/software/ \
			ftp://ftp.id.wustl.edu/pub/qmail/ \
			ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/

RUN_DEPENDS=		tcpserver::net/ucspi-tcp

ALL_TARGET=		it man	

PREFIX=/var/qmail

pre-build:
	@${SUDO} ${SH} ${PKGDIR}/PREINSTALL
	@echo ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@echo ${WRKINST}/var/qmail > ${WRKSRC}/conf-qmail
	@(cd ${WRKSRC} && make install-static && make clean)
	@echo /var/qmail > ${WRKSRC}/conf-qmail
do-install:
	@(cd ${WRKSRC} && ./install-static)
	@(mkdir -p ${WRKINST}/var/qmail/setup && cp ${WRKSRC}/install ${WRKINST}/var/qmail/setup/)
.include <bsd.port.mk>
