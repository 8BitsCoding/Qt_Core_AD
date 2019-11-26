#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>
#include <qrandom.h>

class counter : public QObject
{
	Q_OBJECT

public:
	explicit counter(QObject *parent = nullptr);
	~counter();

signals:

public slots:
	void start();

};
