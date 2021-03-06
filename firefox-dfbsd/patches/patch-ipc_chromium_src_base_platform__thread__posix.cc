$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.8 2016/06/16 12:08:21 ryoon Exp $

* Support NetBSD
* Support Solaris
* Support DragonFly 4.7 after lwp_* function declarations moved to sys/lwp.h

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,14 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
+#elif defined(OS_DRAGONFLY)
+#include <sys/param.h>
+#if __DragonFly_version >= 400709
+#include <sys/lwp.h>
+#endif
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
@@ -107,7 +114,8 @@ void PlatformThread::SetName(const char*
   pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif defined(OS_BSD) && !defined(__GLIBC__)
   pthread_set_name_np(pthread_self(), name);
-#else
+#elif !defined(OS_SOLARIS)
+  prctl(PR_SET_NAME, reinterpret_cast<uintptr_t>(name), 0, 0, 0);
 #endif
 }
 #endif // !OS_MACOSX
