#pragma once

#include <QObject>
#include <qdebug.h>

class Counter : public QObject
{
	Q_OBJECT

public:
	explicit Counter(QObject *parent = nullptr);
	~Counter();

	void increment();
	void decrement();
	int count();

signals:

public slots:

private:
	int value = 0;
};
