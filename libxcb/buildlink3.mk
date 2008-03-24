# $NetBSD: buildlink3.mk,v 1.4 2008/03/24 21:08:59 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXCB_BUILDLINK3_MK:=	${LIBXCB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxcb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxcb}
BUILDLINK_PACKAGES+=	libxcb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxcb

.if ${LIBXCB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.0
BUILDLINK_PKGSRCDIR.libxcb?=	../../wip/libxcb
.endif	# LIBXCB_BUILDLINK3_MK

.include "../../wip/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
