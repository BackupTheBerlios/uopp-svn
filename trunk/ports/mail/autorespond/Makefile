COMMENT=		"simple autoresponder for use in dot qmail files"

DISTNAME=		autorespond-2.0.4
CATEGORIES=		mail

HOMEPAGE=		http://www.inter7.com/?page=qmailadmin

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		 ${MASTER_SITE_SOURCEFORGE:=qmailadmin/}	

WANTLIB=		c

RUN_DEPENDS=		:qmail-*:uopp/mail/qmail
BUILD_DEPENDS=		:qmail-*:uopp/mail/qmail

.include <bsd.port.mk>
