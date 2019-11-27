#include "manager.h"

manager::manager(QObject *parent)
	: QObject(parent)
{
	connect(&producerThread, &QThread::started,&producer,&Producer::start,Qt::QueuedConnection);
	connect(&producer, &Producer::ready, this, &manager::ready, Qt::QueuedConnection);
	connect(&consumerThread, &QThread::started, &m_consumer, &consumer::start, Qt::QueuedConnection);

	producerThread.setObjectName("Producer Thread");
	consumerThread.setObjectName("consumer Thread");
	this->thread()->setObjectName("Main Thread");

	producer.moveToThread(&producerThread);
	m_consumer.moveToThread(&consumerThread);
}

manager::~manager()
{
}


void manager::start()
{
	producer.setMutex(&mutex);
	producer.setData(&data);
	m_consumer.setMutex(&mutex);
	m_consumer.setData(&data);
	m_consumer.setCondition(&condition);

	producerThread.start();
	consumerThread.start();
}

void manager::ready()
{
	qInfo() << "Data is ready" << this->thread();
	condition.wakeAll();
}