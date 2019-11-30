#pragma once

#include <QObject>
#include <qdebug.h>


class cat : public QObject
{
	Q_OBJECT

public:
	explicit cat(QObject *parent = nullptr);
	~cat();

signals:

public slots:
	void test();

private slots:
	void meow();
	void sleep();
	void speak(QString value);	// did not call due to param

};
