#pragma once

#include <QObject>
#include <qdebug.h>

class Dog : public QObject
{
	Q_OBJECT

public:
	explicit Dog(QObject *parent = nullptr);
	~Dog();

signals:

public slots:

private slots:
	// Called before the first test
	void initTestCase();
	
	// Called before each test
	void init();

	// Called after each test
	void cleanup();

	// Called after the last test
	void cleanupTestCase();

	// Our custom slots to be tested
	void bark();

	// Another custom slot to test
	void rollover();
};
