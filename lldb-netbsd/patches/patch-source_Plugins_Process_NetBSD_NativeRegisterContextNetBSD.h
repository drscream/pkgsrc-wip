$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h.orig	2016-12-17 13:00:53.149085298 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h
@@ -0,0 +1,92 @@
+//===-- NativeRegisterContextNetBSD.h ----------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef lldb_NativeRegisterContextNetBSD_h
+#define lldb_NativeRegisterContextNetBSD_h
+
+#include "lldb/Host/common/NativeRegisterContextRegisterInfo.h"
+#include "lldb/Host/common/NativeThreadProtocol.h"
+
+#include "Plugins/Process/NetBSD/NativeProcessNetBSD.h"
+
+namespace lldb_private {
+namespace process_linux {
+
+class NativeRegisterContextNetBSD : public NativeRegisterContextRegisterInfo {
+public:
+  NativeRegisterContextNetBSD(NativeThreadProtocol &native_thread,
+                             uint32_t concrete_frame_idx,
+                             RegisterInfoInterface *reg_info_interface_p);
+
+  // This function is implemented in the NativeRegisterContextNetBSD_* subclasses
+  // to create a new
+  // instance of the host specific NativeRegisterContextNetBSD. The
+  // implementations can't collide
+  // as only one NativeRegisterContextNetBSD_* variant should be compiled into
+  // the final
+  // executable.
+  static NativeRegisterContextNetBSD *
+  CreateHostNativeRegisterContextNetBSD(const ArchSpec &target_arch,
+                                       NativeThreadProtocol &native_thread,
+                                       uint32_t concrete_frame_idx);
+
+protected:
+  lldb::ByteOrder GetByteOrder() const;
+
+  virtual Error ReadRegisterRaw(uint32_t reg_index, RegisterValue &reg_value);
+
+  virtual Error WriteRegisterRaw(uint32_t reg_index,
+                                 const RegisterValue &reg_value);
+
+  virtual Error ReadRegisterSet(void *buf, size_t buf_size,
+                                unsigned int regset);
+
+  virtual Error WriteRegisterSet(void *buf, size_t buf_size,
+                                 unsigned int regset);
+
+  virtual Error ReadGPR();
+
+  virtual Error WriteGPR();
+
+  virtual Error ReadFPR();
+
+  virtual Error WriteFPR();
+
+  virtual void *GetGPRBuffer() { return nullptr; }
+
+  virtual size_t GetGPRSize() {
+    return GetRegisterInfoInterface().GetGPRSize();
+  }
+
+  virtual void *GetFPRBuffer() { return nullptr; }
+
+  virtual size_t GetFPRSize() { return 0; }
+
+  // The Do*** functions are executed on the privileged thread and can perform
+  // ptrace
+  // operations directly.
+  virtual Error DoReadRegisterValue(uint32_t offset, const char *reg_name,
+                                    uint32_t size, RegisterValue &value);
+
+  virtual Error DoWriteRegisterValue(uint32_t offset, const char *reg_name,
+                                     const RegisterValue &value);
+
+  virtual Error DoReadGPR(void *buf, size_t buf_size);
+
+  virtual Error DoWriteGPR(void *buf, size_t buf_size);
+
+  virtual Error DoReadFPR(void *buf, size_t buf_size);
+
+  virtual Error DoWriteFPR(void *buf, size_t buf_size);
+};
+
+} // namespace process_linux
+} // namespace lldb_private
+
+#endif // #ifndef lldb_NativeRegisterContextNetBSD_h
