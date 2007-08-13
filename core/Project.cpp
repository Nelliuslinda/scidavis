/***************************************************************************
    File                 : Project.cpp
    Project              : SciDAVis
    --------------------------------------------------------------------
    Copyright            : (C) 2007 by Knut Franke
    Email (use @ for *)  : knut.franke*gmx.de
    Description          : Represents a SciDAVis project.

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the Free Software           *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor,                    *
 *   Boston, MA  02110-1301  USA                                           *
 *                                                                         *
 ***************************************************************************/
#include "Project.h"
#include "ProjectWindow.h"
#include <QUndoStack>

class Project::Private
{
	public:
		QUndoStack undo_stack;
};

Project::Project()
	: Folder(tr("Unnamed")), d(new Private())
{
}

QUndoStack *Project::undoStack() const
{
	return &d->undo_stack;
}

QWidget *Project::view(QWidget *parent)
{
	Q_UNUSED(parent);
	return new ProjectWindow(this);
}
