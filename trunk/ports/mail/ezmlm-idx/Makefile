# $OpenBSD: Makefile,v 1.12 2001/04/22 12:04:44 camield Exp $

NAME=		ezmlm-idx
VERSION=	0.435
DISTNAME=	${NAME}-${VERSION}
COMMENT=	easy-to-use, high-speed mailing list manager for qmail
HOMEPAGE=	http://www.ezmlm.org	
CATEGORIES=	mail
MAINTAINER=	Thomas Delaet <thomas@delaet.org>	

DISTFILES=	ezmlm-0.53${EXTRACT_SUFX}:0 ${VERSION}/${DISTNAME}${EXTRACT_SUFX}

MASTER_SITES=	http://www.ezmlm.org/pub/patches/ \
		http://www.uk.ezmlm.org/pub/patches/ \
		http://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/

MASTER_SITES0=	http://cr.yp.to/software/ \
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
LANGUAGES=	ch_GB ch_GB cs cs da da de de en_US en_US es es fr fr hu hu id id it it ja ja nl nl pl pl pt pt pt_BR \
		pt_BR ru ru sv sv
EGDIR=		${PREFIX}/share/examples/ezmlm-idx

ALL_TARGET=	it man
INSTALL_TARGET=	setup

RUN_DEPENDS=	${QMAILDIR}/bin/qmail-local::uopp/mail/qmail

post-extract:
	@mv ${WRKDIR}/${DISTNAME}/* ${WRKDIR}/ezmlm-0.53
	@rmdir ${WRKDIR}/${DISTNAME}
	@mv ${WRKDIR}/ezmlm-0.53 ${WRKDIR}/${DISTNAME}
pre-patch:
	@(cd ${WRKSRC}; patch < idx.patch)

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${EGDIR}/ezmlmsubrc
.for i in ${LANGUAGES}
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc.$i ${EGDIR}/ezmlmrc.$i 
.endfor

pre-install:
	@echo ${PREFIX}/bin/ezmlm > ${WRKSRC}/conf-bin
	@echo ${PREFIX}/man > ${WRKSRC}/conf-man

.include <bsd.port.mk>
