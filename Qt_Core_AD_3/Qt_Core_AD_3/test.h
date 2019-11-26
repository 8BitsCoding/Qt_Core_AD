#pragma once

#include <QObject>
#include <qdebug.h>
#include <qthread.h>

class test : public QThread
{
	Q_OBJECT

public:
	explicit test(QObject *parent = nullptr);
	~test();

signals:

public slots:
	void quit();

protected:
	void run();

private:
	bool ok;

};
