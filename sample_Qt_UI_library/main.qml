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


import QtQuick 2.3
import QtQuick.Controls 2.3

ApplicationWindow
{
	visible: true
	width: 350
    height: 200
	
	Item
	{
		anchors.fill: parent
		
		Rectangle
		{
			width: parent.width - 20
			height: parent.height - 20
			color: "light blue"
			border.width: 5
			border.color: "blue"
			opacity: 0.4
			radius: 10
			anchors.centerIn: parent;
			
			Text
			{
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.verticalCenter: parent.verticalCenter
				text: "Hello World"
			}
		}
	}
}