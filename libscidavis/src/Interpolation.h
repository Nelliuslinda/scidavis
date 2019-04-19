/***************************************************************************
    File                 : Interpolation.h
    Project              : SciDAVis
    --------------------------------------------------------------------
    Copyright            : (C) 2007 by Ion Vasilief
    Email (use @ for *)  : ion_vasilief*yahoo.fr
    Description          : Numerical interpolation of data sets

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
#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "Filter.h"

class QwtPlotCurve;
class Interpolation : public Filter
{
Q_OBJECT

public:
  enum InterpolationMethod {Linear, Cubic, Akima};
  Interpolation() {}
  
  Interpolation(ApplicationWindow *parent, Graph *g, const QString& curveTitle, InterpolationMethod m = Linear);
  Interpolation(ApplicationWindow *parent, Graph *g, const QString& curveTitle, double start, double end, InterpolationMethod m = Linear);
  Interpolation(Graph& g, const QString& curveTitle, double start, double end, InterpolationMethod m):
    Interpolation(0,&g,curveTitle,start,end,m) {}
  Interpolation(Graph& g, const QString& curveTitle, double start, double end):
    Interpolation(g,curveTitle,start,end,Linear) {}
  Interpolation(Graph& g, const QString& curveTitle, InterpolationMethod m):
    Interpolation(0,&g,curveTitle,m) {}
  Interpolation(Graph& g, const QString& curveTitle):
    Interpolation(g, curveTitle, Linear) {}
    
  
  InterpolationMethod method(){return d_method;};
  void setMethod(InterpolationMethod m){d_method=m; init();};

protected:
  virtual bool isDataAcceptable();

private:
  void init();
  void calculateOutputData(double *x, double *y);

  //! the interpolation method
  InterpolationMethod d_method;
};

#endif
