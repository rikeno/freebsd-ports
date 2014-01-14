# Created by: r1ke <r1ke.gm@gmail.com>
# $FreeBSD$

PKGNAMESUFFIX=	-mod

MAINTAINER=	r1ke.gm@gmail.com
COMMENT=	Complete front-end based on Qt4 for mplayer with patches

MASTERDIR=	${.CURDIR}/../smplayer
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

EXTRA_PATCHES+=	${.CURDIR}/files/patch-src_playlist.cpp
CONFLICTS=	smplayer-0.*

.include "${MASTERDIR}/Makefile"
