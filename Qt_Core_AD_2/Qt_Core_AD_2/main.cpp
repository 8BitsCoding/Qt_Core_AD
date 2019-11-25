#include <QtCore/QCoreApplication>

#include <qthread.h>
#include <qdebug.h>
#include <qtimer.h>

#include "test.h"

static QSharedPointer<QThread> sptr;
void timeout()
{
	if (!sptr.isNull())
	{
		qInfo() << "Time out - stopping thread from" << QThread::currentThread();;
		sptr.data()->quit();
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	qInfo() << "App Thread: " << a.thread();
	qInfo() << "Current Thread: " << QThread::currentThread();

	test t;
	qInfo() << "Timer Thread: " << t.thread();
	// App과 같은 thread아래 돌아간다.

	QThread thread;
	sptr.reset(&thread);
	t.moveToThread(&thread);
	// test t(&a);
	// test가 App의 자녀라면 thread를 옮길 수 없다.(에러가 발생)
	qInfo() << "Timer Thread(moved): " << t.thread();

	t.start();

	qInfo() << "Thread State: " << thread.isRunning();
	// 이대로 실해아면 thread가 죽어있다.(false)

	thread.start();
	// thread를 실행하는 절차가 필요하다.

	QTimer timer;
	timer.singleShot(5000, &timeout);

	return a.exec();
}
