# $FreeBSD$

PORTNAME=	smplayer
PORTVERSION=	14.9.0.${SVN_REV}
CATEGORIES=	multimedia audio
MASTER_SITES=	https://www.assembla.com/code/smplayer/subversion/nodes/${SVN_REV}/${PORTNAME}/trunk?_format=zip?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based MPlayer front-end

LICENSE=	GPLv2

SVN_REV=	6442
USE_QT4=	gui network script xml moc_build rcc_build uic_build \
		uic3_build porting_build linguist_build
ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}
NO_WRKSUBDIR=	yes
USES=		desktop-file-utils dos2unix gmake qmake zip
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes
PORTDOCS=	Changelog Not_so_obvious_things.txt Readme.txt \
		Release_notes.txt Watching_TV.txt
SUB_FILES=	pkg-message
CONFLICTS=	smplayer-14.*

OPTIONS_DEFINE=	DOCS SKINS THEMES NODEBUG EX_PATCH
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MPLAYER MPLAYER2 MPV

SKINS_DESC=	Add skins
THEMES_DESC=	Add extra icon themes
NODEBUG_DESC=	Define NO_DEBUG_ON_CONSOLE
EX_PATCH_DESC=	Apply patches(EXPERIMENTAL)
MPLAYER_DESC=	Use MPlayer as backend
MPLAYER2_DESC=	Use MPlayer2 as backend
MPV_DESC=	Use MPV as backend

OPTIONS_DEFAULT=DOCS NODEBUG EX_PATCH MPV

SKINS_RUN_DEPENDS=	${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-skins
THEMES_RUN_DEPENDS=	${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-themes
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
MPLAYER2_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer2
MPV_RUN_DEPENDS=	mpv:${PORTSDIR}/multimedia/mpv
EX_PATCH_PATCH_SITES=	https://gist.github.com/r1ke/8748732/raw/b5d43e7751962bfa79744327d8996e9a89e7697c/:1 \
			https://gist.github.com/r1ke/8748732/raw/9fd1195c4fc7358ba31754f410a93da0b8c2486d/:2
EX_PATCH_PATCHFILES+=	compactmode_without_titlebar.diff:1 \
			shrinkable_playlist.diff:2

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|&& $$(QMAKE) $$(QMAKE_OPTS)||; \
		s|lrelease|${LRELEASE}|; \
		s|/share/man|/man|g; \
		s| make| ${MAKE_CMD}|g' \
		${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MNODEBUG}
	@${REINPLACE_CMD} -e 's|#\(DEFINES += NO_DEBUG_ON_CONSOLE\)|\1|' \
		${WRKSRC}/src/smplayer.pro
.endif
	@${REINPLACE_CMD} -e 's|0UNKNOWN|${SVN_REV}|' ${WRKSRC}/get_svn_revision.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
