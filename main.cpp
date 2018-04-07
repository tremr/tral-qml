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



#include "sample_library/SampleLibrary.h"
#include "sample_Qt_UI_library/SampleQtUI.h"


int main(int argc, char** argv)
{
	SampleLibrary sample;
	sample.say_hello();

	SampleQtUI ui;
	return ui.start( argc, argv );
}
