COMMENT=		"The web browser for the GNOME Desktop"
DISTNAME=		epiphany-1.2.6
CATEGORIES=		www	
MOZ=			1.6
PKGNAME=		${DISTNAME}
HOMEPAGE=		http://www.gnome.org/projects/epiphany/

MAINTAINER=	 	Thomas Delaet <thomas@delaet.org>	

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_GNOME:=sources/epiphany/1.2/}	

BUILD_DEPENDS=          :mozilla-${MOZ}:www/mozilla \
                        :mozilla-devel-${MOZ}:www/mozilla,-devel \
                        :scrollkeeper->=0.3.12:textproc/scrollkeeper
RUN_DEPENDS=            :mozilla-${MOZ}:www/mozilla \
                        :scrollkeeper->=0.3.12:textproc/scrollkeeper
LIB_DEPENDS=		nautilus::x11/gnome/nautilus
CONFIGURE_ENV=          CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
                        LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
                        MOZILLA_CONFIG=/usr/local/mozilla/mozilla-config

USE_X11=                Yes
USE_GMAKE=              Yes
CONFIGURE_STYLE=        gnu
CONFIGURE_ARGS=         --disable-werror \
                        --disable-scrollkeeper-update \
			--enable-nautilus-view=yes \
			--with-mozilla-snapshot=${MOZ} \
                        --with-mozilla-home=${LOCALBASE}/mozilla \
                        --with-mozilla-libs=${LOCALBASE}/mozilla/lib \
                        --with-mozilla-includes=${LOCALBASE}/mozilla/include \
			--with-gconf-schema-file-dir=${LOCALBASE}/share/schemas/epiphany

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/schemas/epiphany
	${INSTALL_DATA} ${WRKSRC}/data/epiphany.schemas ${PREFIX}/share/schemas/epiphany/
	cat ${PREFIX}/bin/epiphany | sed -e 's|/usr/local/lib|/usr/local/mozilla|' > ${PREFIX}/bin/epiphany.new
	mv ${PREFIX}/bin/epiphany.new ${PREFIX}/bin/epiphany
	chmod 555 ${PREFIX}/bin/epiphany
	chown root:bin ${PREFIX}/bin/epiphany
.include <bsd.port.mk>
