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
	width: 450
	height: 400
	
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

			Column
			{
				anchors.margins: 10
				anchors.fill: parent
				spacing: 10

				ListView
				{
					id: view
					model: dataModel
					onCurrentIndexChanged: dataModel.current_row = currentIndex
					cacheBuffer: 320

					width: parent.width
					height: parent.height - buttons.height - parent.spacing
					spacing: 1
					clip: true
					focus: true
					flickDeceleration: 500
					highlightMoveDuration: 1000

					highlight: Rectangle
					{
						color: "green"
					}
					highlightFollowsCurrentItem: true

					delegate: Rectangle
					{
						width: view.width
						height: 12
						color: "skyblue"
						id: raw_rect

						property var isCurrent: ListView.isCurrentItem

						Text
						{
							anchors.centerIn: parent
							renderType: Text.NativeRendering
							textFormat: Text.RichText
							text: "%2 %1".arg( model.text ).arg( isCurrent ? "<b>*</b>" : "-" )
							color: model.color
						}

						MouseArea
						{
							anchors.fill: parent
							onClicked:
							{
								view.currentIndex = model.index
							}
						}

						ListView.onRemove:
							SequentialAnimation
							{
								ScriptAction { script: console.log("ListView.onRemove2"); }
								PropertyAction { target: raw_rect; property: "ListView.delayRemove"; value: true }

								PropertyAnimation { target: raw_rect; property: "opacity"; to: 0.0; duration: 500 }
								PropertyAnimation { target: raw_rect; property: "height"; to: 0; duration: 500 }

								PropertyAction { target: raw_rect; property: "ListView.delayRemove"; value: false }
							}
					}
				}
			}


			Row
			{
				id: buttons
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.bottom: parent.bottom
				anchors.bottomMargin: 10
				spacing: 10

				Rectangle
				{
					id: buttonAdd

					width: 100
					height: 40

					border
					{
						color: "black"
						width: 1
					}

					Text
					{
						anchors.centerIn: parent
						renderType: Text.NativeRendering
						text: "Add"
					}

					MouseArea
					{
						anchors.fill: parent
						onClicked: dataModel.add()
					}
				}

				Rectangle
				{
					id: buttonRemove

					width: 100
					height: 40

					border
					{
						color: "black"
						width: 1
					}

					Text
					{
						anchors.centerIn: parent
						renderType: Text.NativeRendering
						text: "Remove"
					}

					MouseArea
					{
						anchors.fill: parent
						onClicked: dataModel.remove()
					}
				}
			}

		}
	}
}
