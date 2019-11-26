#include <QtCore/QCoreApplication>

#include <qthread.h>
#include <qthreadpool.h>
#include <qmutex.h>
#include <qdebug.h>

#include "worker.h"
#include "Counter.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Counter counter;
	QMutex mutex; (QMutex::Recursive);
	QThreadPool* pool = QThreadPool::globalInstance();

	qInfo() << "Count: " << counter.count();

	for (int i = 0; i < pool->maxThreadCount();i++) {
		worker* w = new worker(&a, &counter, &mutex);
		w->setAutoDelete(true);
		pool->start(w);
	}

	pool->waitForDone();

	qInfo() << "Done, the count is: " << counter.count();

	return a.exec();
}
