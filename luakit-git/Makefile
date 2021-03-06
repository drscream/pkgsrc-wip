# $NetBSD$

PKGNAME=	luakit-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=luakit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://luakit.org/
COMMENT=	Webkit based browser framework extensible by Lua
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

GIT_REPOSITORIES=	luakit
GIT_BRANCH.luakit=	develop
GIT_REPO.luakit=	git://github.com/luakit/luakit
WRKSRC=			${WRKDIR}/luakit

LUAKIT_MAKE_FLAGS+=	DEVELOPMENT_PATHS=0
LUAKIT_MAKE_FLAGS+=	APPDIR=${DESTDIR}${PREFIX}/share/applications
LUAKIT_MAKE_FLAGS+=	DOCDIR=${DESTDIR}${PREFIX}/share/doc/luakit
LUAKIT_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}
LUAKIT_MAKE_FLAGS+=	PIXMAPDIR=${DESTDIR}${PREFIX}/share/pixmaps
LUAKIT_MAKE_FLAGS+=	XDGPREFIX=${DESTDIR}${PREFIX}/etc/xdg
LUAKIT_MAKE_FLAGS+=	USE_LUAJIT=0
BUILD_MAKE_FLAGS+=	${LUAKIT_MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	${LUAKIT_MAKE_FLAGS}

LUA_VERSIONS_ACCEPTED=	51

SUBST_CLASSES+=		xdg-dirs
SUBST_STAGE.xdg-dirs=	pre-configure
SUBST_MESSAGE.xdg-dirs=	Add pkgsrc xdg-dirs to the search path.
SUBST_FILES.xdg-dirs=	luah.c clib/xdg.c common/luautil.c
SUBST_SED.xdg-dirs=	-e 's,@PKGSRCXDGPATH@,"${PREFIX}/etc/xdg",g'

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

# Based on lang/swi-prolog-packages:
setupx:
.if exists(${X11BASE}/bin/Xvfb)
	-${X11BASE}/bin/Xvfb :2 & \
	${ECHO} $$! >${WRKDIR}/.Xvfb.pid
	${ECHO} checkforx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
DISPLAY= :2
.else
	@${ECHO} "Error: Please install Xvfb so that the documentation can be built."
	@${FALSE}
.endif  #Xvfb

MAKE_ENV+=	DISPLAY=${DISPLAY:Q}

teardownx:
	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
	${RM} -f ${WRKDIR}/.Xvfb.pid

pre-build:	setupx
post-build:	teardownx

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../wip/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
