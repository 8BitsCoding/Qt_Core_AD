#include "cat.h"

cat::cat(QObject *parent)
	: QObject(parent)
{
}

cat::~cat()
{
}

void cat::speak(QString value)
{
	qInfo() << "speak" << value;
}


void cat::meow()
{
	qInfo() << "meow";
}

void cat::sleep()
{
	qInfo() << "sleep";
}

void cat::test()
{
	qInfo() << "test";
}