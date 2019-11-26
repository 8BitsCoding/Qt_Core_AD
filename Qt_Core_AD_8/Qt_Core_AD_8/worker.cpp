#include "worker.h"


worker::worker(QObject* parent, QStringList* data, QSemaphore* sema, int position) : QObject(parent), QRunnable()
{
	this->sema = sema;
	this->data = data;
	this->position = position;
}

worker::~worker()
{
	if (!data || !sema) {
		qInfo() << "Missing pointers!";
		return;
	}

	QString t;
	t.sprintf("%08p", QThread::currentThread());
	sema->acquire(1);
	data->replace(position, QString::number(position) + " - " + t);
	sema->release();

	qInfo() << t << " Finished" << position;
}

void worker::run()
{

}