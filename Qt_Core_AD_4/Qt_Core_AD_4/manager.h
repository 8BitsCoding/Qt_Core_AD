#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>
#include <qlist.h>

#include "counter.h"

class manager : public QObject
{
	Q_OBJECT

public:
	explicit manager(QObject *parent = nullptr);
	~manager();
	void start();

signals:

public slots:
	void started();
	void finished();

private:
	QList<QThread*> threads;
};
