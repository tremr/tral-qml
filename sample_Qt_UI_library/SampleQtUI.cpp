// Copyright 2018 tremr
//
// This file is part of tral-qml.
//
// tral-qml is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// tral-qml is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with tral-qml.  If not, see <http://www.gnu.org/licenses/>.


//#include "SampleQtUI.h"

#include <QtWidgets/QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

#include "SampleQtUI.h"

SampleQtUI::SampleQtUI()
{}


SampleQtUI::~SampleQtUI()
{}


int SampleQtUI::start( int argc, char** argv )
{
//	QQuickWindow::setSceneGraphBackend( QSGRendererInterface::Software ); // Improves the UI performance but uses more CPU resources.
//	QCoreApplication::setAttribute(Qt::AA_UseOpenGLES); // Alternatives
//	QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
//	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app( argc, argv );
	Q_INIT_RESOURCE( qml );

    QQmlApplicationEngine engine( QUrl( QStringLiteral( "qrc:/main.qml" ) ) );
	if (engine.rootObjects().isEmpty())
		return -1;

	int const result = app.exec();
	Q_CLEANUP_RESOURCE( qml );
    return result;
}
