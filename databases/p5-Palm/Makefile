# $NetBSD: Makefile,v 1.25 2020/08/31 18:07:06 wiz Exp $

DISTNAME=	p5-Palm-1.012
PKGNAME=	${DISTNAME:S/012/12.0/}
PKGREVISION=	11
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BD/BDFOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.coldsync.org/
COMMENT=	Access Palm .pdb and .prc database files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
