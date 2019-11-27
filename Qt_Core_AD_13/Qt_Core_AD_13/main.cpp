#include <QtCore/QCoreApplication>

#include <QtConcurrent>
#include <qdebug.h>
#include <qthread.h>
#include <qthreadpool.h>

void test(QString name, int max)
{
	for (int i = 0; i < max; i++) {
		qInfo() << name << i << QThread::currentThread();
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString name = "name";
	QFuture<void> future = QtConcurrent::run(test, name, 5);
	// QFuture<void> future = QtConcurrent::run(test, "name", 5);
	// Error

	return a.exec();
}
