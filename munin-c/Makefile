# $NetBSD: $

VERSION=	0.0.11
DISTNAME=	munin-c-${VERSION}
COMMENT=	System monitoring tool, client version and plugin in C
CATEGORIES=	sysutils
WRKSRC=         ${WRKDIR}/${DISTNAME}

MAINTAINER=	tm@core.io
HOMEPAGE=	http://munin-monitoring.org/
LICENSE=	gnu-gpl-v2

MASTER_SITES=	${MASTER_SITE_GITHUB:=munin-monitoring/}
GITHUB_PROJECT=	munin-c
GITHUB_TAG=	${VERSION}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed pkg-config autoconf aclocal autoheader automake perl

LIBS.SunOS+=    -lnsl -lsocket

pre-configure:
	cd ${WRKSRC} && \
		libtoolize --force && \
		autoreconf --install && \
		autoreconf -i -I m4


.include "../../mk/bsd.pkg.mk"
