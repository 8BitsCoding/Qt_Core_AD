#pragma once

#include <QObject>
#include <qmutex.h>
#include <qrandom.h>
#include <qthread.h>
#include <qdebug.h>
#include <qlist.h>
#include <qwaitcondition.h>

#include "Producer.h"
#include "consumer.h"

class manager : public QObject
{
	Q_OBJECT

public:
	explicit manager(QObject *parent = nullptr);
	~manager();

signals:

public slots:
	void start();
	void ready();

private:
	QList<int> data;
	QMutex mutex;
	QThread producerThread;
	QThread consumerThread;
	QWaitCondition condition;
	Producer producer;
	consumer m_consumer;
};
