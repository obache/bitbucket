# $NetBSD: Makefile,v 1.3 2020/05/02 18:05:04 tsutsui Exp $
#

DISTNAME=		gobject-introspection-${VERSION}
COMMENT=		Ruby binding of Gobject Introspection
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2

# preserve generated files
GEM_KEEPBUILD=		\
	ext/gobject-introspection/gobject-introspection-enum-types.c \
	ext/gobject-introspection/gobject-introspection-enum-types.h \
	ext/gobject-introspection/rbgiversion.h

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.32.1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
