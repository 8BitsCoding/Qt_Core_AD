#pragma once

#include <QObject>
#include <qdebug.h>
#include <qtest.h>

class Widget : public QObject
{
	Q_OBJECT

public:
	explicit Widget(QObject *parent = nullptr);
	~Widget();

signals:

public slots:

private slots:
	void test();
	void test_data();
	void testFail();
};
