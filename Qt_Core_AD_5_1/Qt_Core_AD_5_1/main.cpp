#include <QtCore/QCoreApplication>

#include <qtest.h>

#include "cat.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	cat c;
	QTest::qExec(&c);


	return a.exec();
}
