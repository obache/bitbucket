# $NetBSD: Makefile,v 1.20 2020/12/04 20:45:49 nia Exp $

DISTNAME=	pygments.rb-1.2.1
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmm1/pygments.rb
COMMENT=	Pygments wrapper for ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.0:../../textproc/ruby-multi_json

REPLACE_PYTHON=	lib/pygments/mentos.py

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/pygments/popen.rb
SUBST_SED.path+=	-e 's|@PYTHON@|python${PYVERSSUFFIX}|'
SUBST_MESSAGE.path=	Fixing Python's path.

PYTHON_VERSIONS_ACCEPTED=	27 # as of 0.6.3

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
