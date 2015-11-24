#include "qtMplayer.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QtMPlayer mplayer;
	mplayer.show();
	return app.exec();
}
