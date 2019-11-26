#pragma once

#include <QObject>
#include <qthread.h>
#include <qrunnable.h>
#include <qdebug.h>
#include <qrandom.h>
#include <qmutex.h>

#include "Counter.h"

class worker : public QObject, public QRunnable
{
	Q_OBJECT

public:
	explicit worker(QObject *parent = nullptr, Counter* counter = nullptr, QMutex* mutex = nullptr);
	
	void run();

signals:

public slots:


private:
	Counter* counter;
	QMutex* mutex;
};
