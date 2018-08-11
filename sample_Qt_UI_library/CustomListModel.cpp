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
#include <cassert>
#include <iostream>


CustomListModel::CustomListModel( QObject* parent )
	: QAbstractListModel( parent )
	, Tral::Log( "CustomListModel" )
	, _current_row( 0 )
	, _filtered_list( this )
{
	QObject::connect( this, &CustomListModel::signal_insert_rows_begin, this, &CustomListModel::slot_insert_rows_begin );
	QObject::connect( this, &CustomListModel::signal_insert_rows_end, this, &CustomListModel::slot_insert_rows_end );

	_data.append("old");
	_data.append( _filtered_list.get_row( 0 ).c_str() );
	_data.append("<font style='color:#00A900;background-color:#FFA000'>Green text on red background</font><br><font style='color: red; background-color: green'>Red text on green background</font>");
}


/*virtual*/ CustomListModel::~CustomListModel()
{}


/*virtual*/ int CustomListModel::rowCount( const QModelIndex& parent ) const
{
	if (parent.isValid())
		return 0;

	return _filtered_list.get_row_count();
}


/*virtual*/ QVariant CustomListModel::data( const QModelIndex& index, int role ) const
{
	if (!index.isValid())
	{
		assert( "unexpected data role" );
		return QVariant();
	}

	switch (role)
	{
	case ColorRole:
		return QVariant( index.row() < 2 ? "red" : "darkblue" );
	case TextRole:
		return _filtered_list.get_row( index.row() ).c_str();
	default:
		assert( "unexpected data role" );
		return QVariant();
	}
}


/*virtual*/ QHash<int, QByteArray> CustomListModel::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
	roles[ColorRole] = "color";
	roles[TextRole] = "text";

	return roles;
}


/*virtual*/ void CustomListModel::on_insert_rows_begin( unsigned first, unsigned last )
{
	log() << __FUNCTION__ << ": first(" << first << ") last(" << last << ")" << std::endl;
	emit signal_insert_rows_begin( first, last );
//	slot_insert_rows_begin( first, last );
}


/*virtual*/ void CustomListModel::on_insert_rows_end( unsigned first, unsigned last )
{
	log() << __FUNCTION__ << ": first(" << first << ") last(" << last << ")" << std::endl;
	emit signal_insert_rows_end( first, last );
//	slot_insert_rows_end( first, last );
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


void CustomListModel::slot_insert_rows_begin( unsigned first, unsigned last )
{
//	QModelIndex index = createIndex( first, 0, nullptr );
	beginInsertRows( QModelIndex(), first, last );
	log() << __FUNCTION__ << ": first(" << first << ") last(" << last << ")" << std::endl;

//	beginResetModel();
}


void CustomListModel::slot_insert_rows_end( unsigned first, unsigned last )
{
	endInsertRows();
	log() << __FUNCTION__ << ": first(" << first << ") last(" << last << ")" << std::endl;

//	QModelIndex index = createIndex( first, last, nullptr );
//	emit dataChanged( index, index ); // TODO(roman.tremaskin): looks wrong
//	endResetModel();
}
