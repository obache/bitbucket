# $NetBSD: Makefile,v 1.35 2020/09/06 19:44:40 wiz Exp $

DISTNAME=	Device-Modem-1.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Device-Modem
COMMENT=	Perl module to talk to modem devices connected via serial port
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Device-SerialPort>=0.19:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
