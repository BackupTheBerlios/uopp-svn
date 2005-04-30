# $OpenBSD: Makefile,v 1.12 2001/04/22 12:04:44 camield Exp $

NAME=		ezmlm
VERSION=	0.53
DISTNAME=	${NAME}-${VERSION}
COMMENT=	easy-to-use, high-speed mailing list manager for qmail
HOMEPAGE=	http://cr.yp.to/ezmlm.html
CATEGORIES=	mail
MAINTAINER=	Thomas Delaet <thomas@delaet.org>	

MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/ \
		ftp://ftp.mira.net.au/unix/mail/qmail/ \
		ftp://ftp.id.wustl.edu/pub/qmail/ \
		ftp://mirror.uk.uu.net/pub/qmail/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		http://ftp.rifkin.technion.ac.il/pub/qmail/ \
		http://koobera.math.uic.edu/www/software/

PERMIT_PACKAGE_CDROM=	Yes	
PERMIT_PACKAGE_FTP=	Yes	
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

QMAILDIR=	/var/qmail

ALL_TARGET=	it man
INSTALL_TARGET=	setup

RUN_DEPENDS=	${QMAILDIR}/bin/qmail-local::uopp/mail/qmail

pre-build:
	@echo "cc -O2 -fno-builtin-log" > ${WRKSRC}/conf-cc 


pre-install:
	@echo ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@echo ${PREFIX}/man > ${WRKSRC}/conf-man

.include <bsd.port.mk>
