# $NetBSD: Makefile,v 1.14 2020/08/31 18:12:06 wiz Exp $
#

DISTNAME=	Text-WagnerFischer-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-WagnerFischer
COMMENT=	Perl module for configurable edit distance calculations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/WagnerFischer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
