$NetBSD: patch-src_leveldb_port_port__posix.h,v 1.1 2013/12/12 20:45:11 noud4 Exp $

Be nbsd specific.

--- src/leveldb/port/port_posix.h.orig	2013-09-12 10:43:31.000000000 +0000
+++ src/leveldb/port/port_posix.h
@@ -50,8 +50,12 @@
 #include "port/atomic_pointer.h"
 
 #ifndef PLATFORM_IS_LITTLE_ENDIAN
+#if defined(OS_NETBSD)
+#define PLATFORM_IS_LITTLE_ENDIAN (BYTE_ORDER == LITTLE_ENDIAN)
+#else
 #define PLATFORM_IS_LITTLE_ENDIAN (__BYTE_ORDER == __LITTLE_ENDIAN)
 #endif
+#endif
 
 #if defined(OS_MACOSX) || defined(OS_SOLARIS) || defined(OS_FREEBSD) ||\
     defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_DRAGONFLYBSD) ||\
