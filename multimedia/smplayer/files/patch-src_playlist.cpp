--- src/playlist.cpp.orig	2013-07-23 08:15:25.000000000 +0900
+++ src/playlist.cpp	2013-12-18 02:41:15.000000000 +0900
@@ -232,7 +232,7 @@
 
 void Playlist::createToolbar() {
 	toolbar = new QToolBar(this);
-	toolbar->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );
+	toolbar->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Minimum );
 
 	toolbar->addAction(openAct);
 	toolbar->addAction(saveAct);;
