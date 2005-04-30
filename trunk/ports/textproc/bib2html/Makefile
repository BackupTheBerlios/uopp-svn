# $OpenBSD:$
COMMENT=		"The BibTeX to HTML Translator"

DISTNAME=		bib2html-3.3
CATEGORIES=		textproc print

HOMEPAGE=		http://galland.stephane.free.fr/arakhne.org/bib2html/

MAINTAINER=		Thomas Delaet <thomas@delaet.org>	

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		http://galland.stephane.free.fr/arakhne.org/bib2html/	

SITE_PERL=		${PREFIX}/libdata/perl5/site_perl

#BUILD_DEPENDS=		???
#RUN_DEPENDS=		???
#LIB_DEPENDS=		???
#REGRESS_DEPENDS=	???

post-patch:
	@sed -e "s|%%SITE_PERL%%|${SITE_PERL}|" ${WRKSRC}/src/bib2html.pl > ${WRKSRC}/src/bib2html.patched
	@mv ${WRKSRC}/src/bib2html.patched ${WRKSRC}/src/bib2html.pl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bib2html.pl ${PREFIX}/bin/bib2html
	@mkdir -p ${SITE_PERL}
	@cp -R ${WRKSRC}/src/Bib2HTML ${SITE_PERL}/
	@(cd ${SITE_PERL}; chmod 644 $$(find ${SITE_PERL} -type f); chmod 755 $$(find ${SITE_PERL} -type d))
.include <bsd.port.mk>
