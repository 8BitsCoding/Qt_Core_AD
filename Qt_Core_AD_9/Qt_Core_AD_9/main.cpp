#include <QtCore/QCoreApplication>

#include "manager.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	manager m_manager;
	m_manager.start();

	return a.exec();
}
