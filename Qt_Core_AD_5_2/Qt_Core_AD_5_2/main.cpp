#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qtest.h>

#include "Dog.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Dog g;

	QTest::qExec(&g);

	return a.exec();
}
