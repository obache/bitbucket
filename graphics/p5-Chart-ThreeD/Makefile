# $NetBSD: Makefile,v 1.24 2020/08/31 18:09:41 wiz Exp $

DISTNAME=	Chart-ThreeD-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Chart-ThreeD
COMMENT=	Three-Dimentional pie chart plotting

DEPENDS+=	p5-GD>=2.16:../../graphics/p5-GD

PERL5_PACKLIST=		auto/Chart-ThreeD/.packlist

REPLACE_PERL+=	pie.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
