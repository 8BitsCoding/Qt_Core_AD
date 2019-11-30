#include "Dog.h"

Dog::Dog(QObject *parent)
	: QObject(parent)
{
	qInfo() << "Constructor";
}

Dog::~Dog()
{
}


void Dog::initTestCase()
{
	qInfo() << "initTestCase";
}

void Dog::init()
{
	qInfo() << "init";
}

void Dog::cleanup()
{
	qInfo() << "cleanup";
}

void Dog::cleanupTestCase()
{
	qInfo() << "cleanupTestCase";
}

void Dog::bark()
{
	qInfo() << "bark";
}

void Dog::rollover()
{
	qInfo() << "rollover";
}