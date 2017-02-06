$NetBSD$

--- source/Symbol/GoASTContext.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Symbol/GoASTContext.cpp
@@ -25,6 +25,8 @@
 #include "lldb/Target/ExecutionContext.h"
 #include "lldb/Target/Target.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "Plugins/ExpressionParser/Go/GoUserExpression.h"
 #include "Plugins/SymbolFile/DWARF/DWARFASTParserGo.h"
 
@@ -593,8 +595,8 @@ GoASTContext::GetBasicTypeEnumeration(ll
   if (name) {
     typedef UniqueCStringMap<lldb::BasicType> TypeNameToBasicTypeMap;
     static TypeNameToBasicTypeMap g_type_map;
-    static std::once_flag g_once_flag;
-    std::call_once(g_once_flag, []() {
+    static llvm::once_flag g_once_flag;
+    llvm::call_once(g_once_flag, []() {
       // "void"
       g_type_map.Append(ConstString("void").GetStringRef(), eBasicTypeVoid);
       // "int"