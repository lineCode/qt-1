/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QGraphicsWidget>
#include "simplelistview.h"
#include "scroller.h"
#include "gvbwidget.h"

class AbstractViewItem;
class QGraphicsSceneResizeEvent;
class QGraphicsGridLayout;
class QGraphicsLinearLayout;

class ListWidget : public GvbWidget
{
    Q_OBJECT

public:
    ListWidget(QGraphicsWidget * parent = 0);
    virtual ~ListWidget();
    void addItem(QGraphicsWidget *item);
    void insertItem(int index, QGraphicsWidget *item);
    QGraphicsWidget* takeItem(int row);
    QGraphicsWidget* itemAt(int row);
    int itemCount() const;
#if (QT_VERSION >= 0x040600)
    bool listItemCaching() const;
    void setListItemCaching(bool enable);
#endif
    ScrollBar* verticalScrollBar() const;

    void setTwoColumns(const bool twoColumns);
    bool twoColumns();

protected:
    virtual void resizeEvent( QGraphicsSceneResizeEvent * event );

private:
    Q_DISABLE_COPY(ListWidget)

    QGraphicsLinearLayout *m_layout;
    SimpleListView *m_listView;
    Scroller m_scroller;
};

#endif
