#pragma once

#include <QObject>
#include <qmutex.h>
#include <qrandom.h>
#include <qthread.h>
#include <qdebug.h>
#include <qlist.h>

class Producer : public QObject
{
	Q_OBJECT

public:
	explicit Producer(QObject *parent = nullptr);
	~Producer();

	void setData(QList<int>* data);
	void setMutex(QMutex* mutex);

signals:
	void ready();


public slots:
	void start();

private:
	QList<int>* data;
	QMutex* mutex;
};
