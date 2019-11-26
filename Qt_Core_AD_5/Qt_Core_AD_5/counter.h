#pragma once

#include <QObject>
#include <qdebug.h>
#include <qrunnable.h>
#include <qrandom.h>
#include <qthread.h>

class counter : public QRunnable
{
public:
	void run();

};
