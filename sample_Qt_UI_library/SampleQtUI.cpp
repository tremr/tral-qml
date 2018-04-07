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
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "SampleQtUI.h"

SampleQtUI::SampleQtUI()
{}


SampleQtUI::~SampleQtUI()
{}


int SampleQtUI::start( int argc, char** argv )
{
    QApplication app( argc, argv );

    QWidget widget;
    widget.resize( 640, 480 );
    widget.setWindowTitle( "Hello, world!!!" );

    QGridLayout *gridLayout = new QGridLayout( &widget );

    QLabel * label = new QLabel( "Hello, world!!!" );
    label->setAlignment( Qt::AlignVCenter | Qt::AlignHCenter );
    gridLayout->addWidget( label );

    widget.show();

    return app.exec();
}
