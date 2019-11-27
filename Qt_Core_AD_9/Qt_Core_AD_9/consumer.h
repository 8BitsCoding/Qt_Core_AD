#pragma once

#include <QObject>
#include <qmutex.h>
#include <qrandom.h>
#include <qthread.h>
#include <qdebug.h>
#include <qlist.h>
#include <qwaitcondition.h>

class consumer : public QObject
{
	Q_OBJECT

public:
	explicit consumer(QObject *parent = nullptr);
	~consumer();

	void setData(QList<int>* data);
	void setMutex(QMutex* mutex);
	void setCondition(QWaitCondition* condition);

signals:
	

public slots:
	void start();

private:
	QList<int>* data;
	QMutex* mutex;
	QWaitCondition* condition;
};
