# $NetBSD: Makefile,v 1.7 2020/12/11 10:58:20 jaapb Exp $

GITHUB_PROJECT=	ocsigen-i18n
DISTNAME=	${GITHUB_PROJECT}-3.7.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=besport/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/besport/ocsigen-i18n/
COMMENT=	I18n package for Ocsigen
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
USE_TOOLS=		gmake
BUILD_TARGET=		build
MAKE_ENV=		bindir=${DESTDIR}${PREFIX}/bin
INSTALLATION_DIRS+=	bin

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	# empty

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	OPTNESS=native
.else
MAKE_ENV+=	OPTNESS=byte
.endif

.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
