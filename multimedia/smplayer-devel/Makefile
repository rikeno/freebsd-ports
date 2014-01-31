# Created by: r1ke<r1ke.gm@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
PKGNAMESUFFIX=	-devel
DISTVERSION=	0.8.6.r${SVN_REV}
SVN_REV=	6004

CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.assembla.com/code/smplayer/subversion/nodes/${SVN_REV}/${PORTNAME}/trunk?_format=zip?dummy=/

MAINTAINER=	r1ke.gm@gmail.com
COMMENT=	A great MPlayer front-end
LICENSE=	GPLv2

USE_QT4=	gui network script xml moc_build rcc_build uic_build \
		uic3_build porting_build linguist_build

ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USES=		desktop-file-utils dos2unix gmake qmake
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes

PORTDOCS=	Changelog Not_so_obvious_things.txt Readme.txt \
		Release_notes.txt Watching_TV.txt

OPTIONS_DEFINE=	MPLAYER2 DOCS SKINS THEMES NODEBUG

MPLAYER2_DESC?=	Use MPlayer2 instead of MPlayer as back-end
SKINS_DESC?=	Add skins
THEMES_DESC?=	Add extra icon themes
NODEBUG_DESC?=	Define NO_DEBUG_ON_CONSOLE

OPTIONS_DEFAULT=DOCS NODEBUG

SUB_FILES=	pkg-message

CONFLICTS=	smplayer-0.* smplayer-mod-0.*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER2}
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer2
.else
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MSKINS}
RUN_DEPENDS+=	${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-skins
.endif

.if ${PORT_OPTIONS:MTHEMES}
RUN_DEPENDS+=	${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-themes
.endif

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

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
