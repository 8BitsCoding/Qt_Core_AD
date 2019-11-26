#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qthreadpool.h>
#include <qsemaphore.h>

#include "worker.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList data;
	for (int i = 0; i < 100; i++) {
		data.append(QString::number(i));
	}

	QThreadPool* pool = QThreadPool::globalInstance();
	QSemaphore sema(100);

	for (int i = 0; i < data.length();i++)
	{
		worker* w = new worker(&a, &data, &sema, i);
		w->setAutoDelete(true);
		pool->start(w);
	}
	pool->waitForDone();

	foreach(QString string, data)
	{
		qInfo() << string;
	}

	return a.exec();
}
