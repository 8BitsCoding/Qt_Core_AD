#pragma once

#include <QObject>
#include <qthread.h>
#include <qdebug.h>
#include <qtimer.h>
#include <qdatetime.h>

class test : public QObject
{
	Q_OBJECT

public:
	explicit test(QObject *parent = nullptr);
	~test();

signals:

public slots:
	void timeout();
	void start();

private:
	QTimer timer;
};
