/***************************************************************************
    File                 : AspectModel.h
    Project              : SciDAVis
    --------------------------------------------------------------------
    Copyright            : (C) 2007 by Knut Franke
    Email (use @ for *)  : knut.franke*gmx.de
    Description          : Private model data managed by AbstractAspect.

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
#ifndef ASPECT_MODEL_H
#define ASPECT_MODEL_H

#include <QString>
#include <QDateTime>
#include <QList>

class AbstractAspect;

//! Private model data managed by AbstractAspect.
class AspectModel
{
	public:
		AspectModel(const QString& name);

		void addChild(AbstractAspect *child);
		void insertChild(int index, AbstractAspect *child);
		int indexOfChild(const AbstractAspect *child) const;
		void removeChild(AbstractAspect *child);
		int childCount() const;
		AbstractAspect* child(int index);

		QString name() const;
		void setName(const QString &value);
		QString comment() const;
		void setComment(const QString &value);
		QString captionSpec() const;
		void setCaptionSpec(const QString &value);
		QDateTime creationTime() const;

		QString caption() const;

	private:
		static int indexOfMatchingBrace(const QString &str, int start);
		QList<AbstractAspect*> d_children;
		QString d_name, d_comment, d_caption_spec;
		QDateTime d_creation_time;
};

#endif // ifndef ASPECT_MODEL_H
