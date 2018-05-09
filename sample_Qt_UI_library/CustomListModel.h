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


#ifndef SOURCE_DIRECTORY__SAMPLE_QT_UI_LIBRARY_CUSTOMLISTMODEL_H_
#define SOURCE_DIRECTORY__SAMPLE_QT_UI_LIBRARY_CUSTOMLISTMODEL_H_


#include <QtCore/QAbstractListModel>
#include <QtCore/QStringList>


class CustomListModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY( int current_row MEMBER _current_row WRITE set_current_row )

public:
	enum Roles
	{
		ColorRole = Qt::UserRole + 1,
		TextRole,
	};

	CustomListModel( QObject *parent = 0 );
	virtual ~CustomListModel();

	// QAbstractListModel
	virtual int rowCount(const QModelIndex &parent) const;
	virtual QVariant data(const QModelIndex &index, int role) const;
	virtual QHash<int, QByteArray> roleNames() const;

	void set_current_row( int row );

	Q_INVOKABLE void add();
	Q_INVOKABLE void remove();

private:
	QStringList _data;
	int         _current_row;
};

#endif /* SOURCE_DIRECTORY__SAMPLE_QT_UI_LIBRARY_CUSTOMLISTMODEL_H_ */
