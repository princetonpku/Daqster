/************************************************************************
                        Daqster/QPluginListView.h.h - Copyright 
Daqster software
Copyright (C) 2016, Vasil Vasilev,  Bulgaria

This file is part of Daqster and its software development toolkit.

Daqster is a free software; you can redistribute it and/or modify it
under the terms of the GNU Library General Public Licence as published by
the Free Software Foundation; either version 2 of the Licence, or (at
your option) any later version.

Daqster is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library
General Public Licence for more details.

Initial version of this file was created on 16.03.2017 at 11:40:20
**************************************************************************/


#ifndef QPLUGINLISTVIEW_H
#define QPLUGINLISTVIEW_H
#include "base/global.h"
#include <QWidget>
#include "PluginFilter.h"

namespace Ui {
    class PluginListView;
}


namespace Daqster {

class FRAME_WORKSHARED_EXPORT QPluginFilter;

/**
  * class QPluginListView
  * This class implement plugins view Widget. It show plugins in list with
  * categories. It support plugin filtration features ( by type, subtypes, etc....
  * tbd ).
  */

class QPluginListView : public QWidget
{
public:

  // Constructors/Destructors

  /**
  * Constructor
  * @param  Filter Plugin filtrato parameter
  */
  QPluginListView ( QWidget* Parent = NULL ,const Daqster::PluginFilter& Filter = Daqster::PluginFilter() );

  /**
   * Empty Destructor
   */
  virtual ~QPluginListView ();

  /**
   * Set view plugin flter.
   * @param  Filter
   */
  void SetPluginFilter (const Daqster::QPluginFilter& Filter);

protected:
  // Plugin filter
  Daqster::PluginFilter m_PluginFilter;
private:
  Ui::PluginListView* ui;
};
} // end of package namespace

#endif // QPLUGINLISTVIEW_H