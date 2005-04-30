COMMENT=		"Apache HTTP (Web) server, version 2"

VERSION=		2.0.54
DISTNAME=		httpd-${VERSION}	
PKGNAME=		apache-${VERSION}
CATEGORIES=		www	

HOMEPAGE=		http://httpd.apache.org	

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# Apache License 
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/}	

#BUILD_DEPENDS=		???
#RUN_DEPENDS=		???
#LIB_DEPENDS=		???

PREFIX=/usr/local/apache2

CONFIGURE_STYLE=	gnu	
CONFIGURE_ARGS+=	${CONFIGURE_SHARED} \
			--prefix=${PREFIX} \
			--sysconfdir=/etc/apache2 \
			--enable-dav \
			--enable-dav-fs \
			--enable-proxy \
			--enable-proxy-connect \
			--enable-proxy-ftp \
			--enable-proxy-http \
			--enable-rewrite \
			--enable-so \
			--enable-ssl
.include <bsd.port.mk>
