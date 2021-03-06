# $NetBSD$
#
.include "../../mk/bsd.fast.prefs.mk"

pre-configure:
	ln -s libKF5GlobalAccelPrivate.so.5 ${BUILDLINK_DIR}/lib/libKF5GlobalAccelPrivate.so
.if ${OPSYS} == "NetBSD"
	mkdir ${BUILDLINK_DIR}/include/linux
	cp ${FILESDIR}/input.h ${BUILDLINK_DIR}/include/linux/input.h
.endif

# $NetBSD: hacks.mk,v 1.1 2018/01/17 20:00:21 markd Exp $

# linking -lQt5Widgets on NetBSD with gcc produces
# ld: BFD (NetBSD Binutils nb1) 2.27 assertion fail
# /usr/src/external/gpl3/binutils/lib/libbfd/../../dist/bfd/elflink.c:2694
# unless -lexecinfo preceeds -lQt5Widgets
BUILDLINK_TRANSFORM.NetBSD+=	l:Qt5Widgets:execinfo:Qt5Widgets
