# $OpenBSD$
COMMENT=		"Website META Language"

DISTNAME=		wml-2.0.9	
CATEGORIES=		www	

HOMEPAGE=		http://www.thewml.org

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://www.thewml.org/distrib/

# Dependencies
#
#BUILD_DEPENDS=		???
#RUN_DEPENDS=		???
#LIB_DEPENDS=		???

#USE_GMAKE=		Yes
# Set CONFIGURE_STYLE to value corresponding to some standard configuration
# 	  perl [modbuild]: perl's MakeMaker Makefile.PL (modbuild: perl's
#	  Module::Build Build.PL)
# 	  gnu [autoconf] [old] [dest]: gnu style configure (old: no
# 	  sysconfdir), (dest: add DESTDIR, does not handle it),
# 	  (autoconf: needed by port, implies gnu)
# 	XXX: cygnus products do NOT use autoconf for making the main
# 		configure from configure.in
# 	  imake [noman]: port uses imake for configuration.
#   	  (noman: no man page installation)
# 	  simple: port has its own configure script
CONFIGURE_STYLE=gnu	
#CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
#CONFIGURE_ENV=		???

.include <bsd.port.mk>
