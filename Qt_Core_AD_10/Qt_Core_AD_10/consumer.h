#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>

#include "timer.h"

class consumer : public QObject
{
	Q_OBJECT

public:
	explicit consumer(QObject *parent = nullptr);
	~consumer();

signals:

public slots:
	void timeout();
	void start();
	void finished();

private:
	QThread thread;
	timer m_timer;
};
