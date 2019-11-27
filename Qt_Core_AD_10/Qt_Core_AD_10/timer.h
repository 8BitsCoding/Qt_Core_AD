#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>

class timer : public QObject
{
	Q_OBJECT

public:
	explicit timer(QObject *parent = nullptr);
	~timer();

	void setInternval(int value);

signals:
	void timeout();

public slots:
	void started();

private:
	int interval = -1;
};
