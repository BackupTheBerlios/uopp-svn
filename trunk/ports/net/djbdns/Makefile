# $OpenBSD$
# Original from: Giacomo Cariello <jwk@bug.it>

COMMENT=	"collection of Domain Name System tools"

DISTNAME=	djbdns-1.05
CATEGORIES=	net
MAINTAINER=	Thomas Delaet <thomas@delaet.org>	
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://ftp.id.wustl.edu/pub/qmail/
MASTER_SITES0=	ftp://ftp.innominate.org/gpa/djb/
HOMEPAGE=	http://cr.yp.to/djbdns.html
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-man${EXTRACT_SUFX}:0

PERMIT_PACKAGE_CDROM=	No
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

ALL_TARGET=	default
INSTALL_TARGET=	setup check

RUN_DEPENDS=	:daemontools-*:sysutils/daemontools

MAN5LIST=	qualification
MAN1LIST=	dnsfilter dnsipq dnsname dnsqr dnstxt dnsip \
		dnsmx dnsq dnstrace dnstracesort
MAN8LIST=	axfr-get dnscache pickdns rbldns tinydns axfrdns \
		pickdns-conf rbldns-conf tinydns-conf walldns-conf \
		dnscache-conf pickdns-data rbldns-data tinydns-data \
		walldns

SUBST_VARS=	SYSCONFDIR

pre-build:
	@echo ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@echo ${PREFIX} > ${WRKSRC}/conf-home

pre-install:
	@echo ${PREFIX} > ${WRKSRC}/conf-home

post-install:
.for mtype in 1 5 8
.  for file in ${MAN${mtype}LIST}
	${INSTALL_MAN} ${WRKDIR}/djbdns-man/${file}.${mtype} \
		${PREFIX}/man/man${mtype}
.  endfor
.endfor

.include <bsd.port.mk>
