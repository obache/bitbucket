# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:36 rillig Exp $

BUILDLINK_TREE+=	go-toml-burntsushi

.if !defined(GO_TOML_BURNTSUSHI_BUILDLINK3_MK)
GO_TOML_BURNTSUSHI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-toml-burntsushi=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-toml-burntsushi?=	build

BUILDLINK_API_DEPENDS.go-toml-burntsushi+=		go-toml-burntsushi>=0.2.0
BUILDLINK_PKGSRCDIR.go-toml-burntsushi?=		../../www/go-toml-burntsushi

.endif  # GO_TOML_BURNTSUSHI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-toml-burntsushi
