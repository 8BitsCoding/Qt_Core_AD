#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <QtConcurrent>
#include <qthread.h>
#include <qthreadpool.h>

void loop()
{
	for (int i = 0; i < 10; i++)
	{
		qInfo() << "Loop" << i << "on: " << QThread::currentThread();
	}
}

void test()
{
	qInfo() << "Test on: " << QThread::currentThread();
	loop();
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QThread::currentThread()->setObjectName("Main");

	QThreadPool pool;
	QFuture<void> future = QtConcurrent::run(&pool, loop);
	qInfo() << "Main on: " << QThread::currentThread();
	loop();

	return a.exec();
}
