#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qthread.h>

#include "consumer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QThread::currentThread()->setObjectName("Main thread");
	qInfo() << "Application started on " << QThread::currentThread();

	consumer c;
	c.start();

	return a.exec();
}
