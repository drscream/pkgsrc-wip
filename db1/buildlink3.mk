# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	db1

.if !defined(DB1_BUILDLINK3_MK)
DB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.db1+=		db1>=1.86
BUILDLINK_PKGSRCDIR.db1?=	../../wip/db1
.endif # DB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-db1
