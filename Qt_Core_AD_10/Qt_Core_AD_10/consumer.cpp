#include "consumer.h"

consumer::consumer(QObject *parent)
	: QObject(parent)
{
	qInfo() << "Created on " << QThread::currentThread();
	thread.setObjectName("Timer Thread");

	/*
	Qt::AutoConnection - run on both
	Qt::QueuedConnection - run on main thread
	Qt::DirectConnection - run on thread
	Qt::BlockingQueuedConnection - blocks
	Qt::UniqueConnection - combined with others
	*/

	connect(&m_timer, &timer::timeout, this, &consumer::timeout, Qt::AutoConnection);
	connect(&thread, &QThread::started, &m_timer, &timer::started, Qt::AutoConnection);
	connect(&thread, &QThread::finished, this, &consumer::finished, Qt::AutoConnection);
}

consumer::~consumer()
{
}


void consumer::timeout()
{
	qInfo() << "Consumer timeout on " << QThread::currentThread();
	thread.quit();
}

void consumer::start()
{
	qInfo() << "Consumer start on " << QThread::currentThread();
	m_timer.setInternval(500);
	m_timer.moveToThread(&thread);
	thread.start();
}

void consumer::finished()
{
	qInfo() << "Consumer finished on " << QThread::currentThread();
}