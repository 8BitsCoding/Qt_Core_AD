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
	// App�� ���� thread�Ʒ� ���ư���.

	QThread thread;
	sptr.reset(&thread);
	t.moveToThread(&thread);
	// test t(&a);
	// test�� App�� �ڳ��� thread�� �ű� �� ����.(������ �߻�)
	qInfo() << "Timer Thread(moved): " << t.thread();

	t.start();

	qInfo() << "Thread State: " << thread.isRunning();
	// �̴�� ���ؾƸ� thread�� �׾��ִ�.(false)

	thread.start();
	// thread�� �����ϴ� ������ �ʿ��ϴ�.

	QTimer timer;
	timer.singleShot(5000, &timeout);

	return a.exec();
}
