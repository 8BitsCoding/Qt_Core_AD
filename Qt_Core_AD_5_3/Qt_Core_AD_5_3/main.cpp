#include <QtCore/QCoreApplication>

#include "Widget.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Widget w;
	w.setAge(20);
	QTest::qExec(&w);

	return a.exec();
}
