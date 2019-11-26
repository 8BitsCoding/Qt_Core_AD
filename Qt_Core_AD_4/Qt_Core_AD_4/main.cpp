#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qthread.h>

#include "manager.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QThread::currentThread()->setObjectName("Main");

	manager m;
	m.start();

	return a.exec();
}
