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


#include "CustomListModel.h"


CustomListModel::CustomListModel( QObject* parent )
	: QAbstractListModel( parent )
	, _current_row( 0 )
{
	_data.append("old");
	_data.append("<font style='color:#00A900;background-color:#FF0000'>Mar 26 06:52:59 <font style='color:#6495ED;background-color:#FFA500'>marked fragment</font> 2639.118 1677 filtered fragment</font>");
	_data.append("<font style='color:#00A900;background-color:#FFA000'>Green text on red background</font><br><font style='color: red; background-color: green'>Red text on green background</font>");
}


/*virtual*/ CustomListModel::~CustomListModel()
{}


int CustomListModel::rowCount( const QModelIndex& parent ) const
{
	if (parent.isValid())
		return 0;

	return _data.size();
}


QVariant CustomListModel::data( const QModelIndex& index, int role ) const
{
	if (!index.isValid())
		return QVariant();

	switch (role)
	{
	case ColorRole:
		return QVariant( index.row() < 2 ? "red" : "darkblue" );
	case TextRole:
		return _data.at( index.row() );
	default:
		return QVariant();
	}
}


QHash<int, QByteArray> CustomListModel::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
	roles[ColorRole] = "color";
	roles[TextRole] = "text";

	return roles;
}


void CustomListModel::set_current_row( int row )
{
	_current_row = row;
	if (_data.empty())
		return;

	_data[0] = QString( "Current: %1" ).arg( _current_row );
	QModelIndex index = createIndex( 0, 0, nullptr );
	emit dataChanged( index, index );
}


void CustomListModel::add()
{
	if (_data.empty())
		_current_row = 0;

	beginInsertRows( QModelIndex(), _current_row, _current_row );
	_data.insert( _current_row, "new" );
	endInsertRows();

	_data[0] = QString( "Size: %1" ).arg( _data.size() );
	QModelIndex index = createIndex( 0, 0, nullptr );
	emit dataChanged( index, index );
}


void CustomListModel::remove()
{
	if (_data.empty())
		return;

	beginRemoveRows( QModelIndex(), _current_row, _current_row );
	QStringList::iterator it = _data.begin() + _current_row;
	_data.erase( it );
	endRemoveRows();
}

