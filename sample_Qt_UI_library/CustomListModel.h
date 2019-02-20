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


#include "tral/include/list.h"
#include <QtCore/QAbstractListModel>
#include <QtCore/QStringList>


class CustomListModel : public QAbstractListModel, public Tral::Callback, private Tral::Log
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

	// Tral::Callback
	virtual void on_critical_section_begin();
	virtual void on_critical_section_end();
	virtual void on_insert_rows_begin( unsigned first, unsigned last );
	virtual void on_insert_rows_end( unsigned first, unsigned last );
	virtual void on_remove_rows_begin( unsigned first, unsigned last );
	virtual void on_remove_rows_end( unsigned first, unsigned last );


	void set_current_row( int row );

	Q_INVOKABLE void add();
	Q_INVOKABLE void remove();

	private slots:
	void slot_critical_section_begin();
	void slot_critical_section_end();
	void slot_insert_rows_begin( unsigned first, unsigned last );
	void slot_insert_rows_end( unsigned first, unsigned last );
	void slot_remove_rows_begin( unsigned first, unsigned last );
	void slot_remove_rows_end( unsigned first, unsigned last );

	signals:
	void signal_critical_section_begin();
	void signal_critical_section_end();
	void signal_insert_rows_begin( unsigned first, unsigned last );
	void signal_insert_rows_end( unsigned first, unsigned last );
	void signal_remove_rows_begin( unsigned first, unsigned last );
	void signal_remove_rows_end( unsigned first, unsigned last );

	private:
	QStringList _data;
	int         _current_row;
	Tral::List  _filtered_list;
};

#endif /* SOURCE_DIRECTORY__SAMPLE_QT_UI_LIBRARY_CUSTOMLISTMODEL_H_ */
