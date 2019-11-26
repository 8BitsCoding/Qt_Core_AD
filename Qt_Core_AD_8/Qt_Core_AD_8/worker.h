#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>
#include <qrunnable.h>
#include <qsemaphore.h>

class worker : public QObject, public QRunnable
{
	Q_OBJECT

public:
	explicit worker(QObject *parent = nullptr, QStringList* data = nullptr, QSemaphore* sema = nullptr, int position = -1);
	~worker();

	void run();

signals:

public slots:


private:
	QStringList* data;
	QSemaphore* sema;
	int position;
};
