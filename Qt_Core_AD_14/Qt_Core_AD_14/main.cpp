#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qfuture.h>
#include <qfuturewatcher.h>
#include <qlist.h>
#include <QtConcurrent>

void multiply(int &value)
{
	qInfo() << "Called: " << value;
	value = value * 10;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QList<int> list;

	for (int i = 0; i < 100; i++) {
		list.append(i);
	}

	QFutureWatcher<void> watcher;
	QFuture<void> future = QtConcurrent::map(list, &multiply);
	watcher.setFuture(future);
	qInfo() << "Back in main!";

	watcher.waitForFinished();
	qInfo() << "done!";
	qInfo() << list;

	return a.exec();
}
