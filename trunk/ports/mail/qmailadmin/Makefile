COMMENT=		"Easy virtual domain and authentication package for use with qmail"

DISTNAME=		qmailadmin-1.2.3	
CATEGORIES=		mail

HOMEPAGE=		http://www.inter7.com/?page=qmailadmin	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		 ${MASTER_SITE_SOURCEFORGE:=qmailadmin/}	

RUN_DEPENDS=		:qmail-*:uopp/mail/qmail
RUN_DEPENDS+=		::uopp/mail/vpopmail
RUN_DEPENDS+=		::uopp/mail/autorespond
RUN_DEPENDS+=		::uopp/mail/ezmlm-idx
BUILD_DEPENDS=		:qmail-*:uopp/mail/qmail
BUILD_DEPENDS+=		::uopp/mail/vpopmail
BUILD_DEPENDS+=		::uopp/mail/autorespond
BUILD_DEPENDS+=		::uopp/mail/ezmlm-idx

WANTLIB=		c
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-htmldir=/var/www/htdocs  \
			--disable-ezmlm-mysql \
			--enable-modify-quota \
			--enable-vpopgroup=vpopmail \
			--enable-vpopmaildir=/var/vpopmail \
			--enable-ezmlmdir=${LOCALBASE}/bin/ezmlm
	
INSTALL_TARGET=		install-strip

post-install:
	@mkdir -p /usr/local/share/examples
	@mv ${WRKINST}/var/www ${WRKINST}/usr/local/share/examples/qmailadmin

.include <bsd.port.mk>
