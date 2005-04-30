COMMENT=		"Easy virtual domain and authentication package for use with qmail"

DISTNAME=		vpopmail-5.4.9
CATEGORIES=		mail

HOMEPAGE=		http://www.inter7.com/?page=vpopmail	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		 ${MASTER_SITE_SOURCEFORGE:=vpopmail/}	

RUN_DEPENDS=		:qmail-*:uopp/mail/qmail
BUILD_DEPENDS=		:qmail-*:uopp/mail/qmail

WANTLIB=		c
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-qmaildir=/var/qmail \
			--enable-qmail-newu=/var/qmail/bin/qmail-newu \
			--enable-qmail-inject=/var/qmail/bin/qmail-inject \
			--enable-qmail-newmrh=/var/qmail/bin/qmail-newmrh \
			--enable-vpopuser=vpopmail \
			--enable-vpopgroup=vpopmail \
			--disable-rebuild-tcpserver-file \
			--enable-qmail-ext \
			--enable-auth-module=cdb \
			--enable-logging=p
			
INSTALL_TARGET=		install-strip
PREFIX=			/var/vpopmail

pre-configure:
	@${SUDO} ${SH} ${PKGDIR}/../files/PREBUILD
.include <bsd.port.mk>
