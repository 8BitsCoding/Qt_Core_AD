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

	void setAge(int value);

signals:

public slots:

private slots:
	void testFail();
	void testAge();
	void testWidget();

private:
	int age;
};
