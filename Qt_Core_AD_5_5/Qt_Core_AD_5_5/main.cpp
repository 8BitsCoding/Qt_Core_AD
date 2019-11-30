#include <QtCore/QCoreApplication>

#include <qtest.h>
#include "Widget.h"

// QTEST_MAIN(Widget);


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Widget w;
	QTest::qExec(&w);

	return a.exec();
}

