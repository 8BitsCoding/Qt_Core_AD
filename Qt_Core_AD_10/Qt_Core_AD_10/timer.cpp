#include "timer.h"

timer::timer(QObject *parent)
	: QObject(parent)
{
}

timer::~timer()
{
}


void timer::setInternval(int value)
{
	this->interval = value;
}

void timer::started()
{
	qInfo() << "Timer started on " << QThread::currentThread();
	this->thread()->msleep(this->interval);
	emit timeout();
}