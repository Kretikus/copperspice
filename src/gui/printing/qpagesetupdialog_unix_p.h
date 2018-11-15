/***********************************************************************
*
* Copyright (c) 2012-2018 Barbara Geller
* Copyright (c) 2012-2018 Ansel Sermersheim
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#ifndef QPAGESETUPDialog_Unix_P_H
#define QPAGESETUPDialog_Unix_P_H

#include <qglobal.h>

#ifndef QT_NO_PRINTDIALOG

#include <qprinter.h>
#include <qpagelayout.h>
#include <ui_qpagesetupwidget.h>

QT_BEGIN_NAMESPACE

class QPrinter;
class QPagePreview;


class QPageSetupWidget : public QWidget
{
   GUI_CS_OBJECT(QPageSetupWidget)

 public:
   QPageSetupWidget(QWidget *parent = nullptr);
   QPageSetupWidget(QPrinter *printer, QWidget *parent = nullptr);
   void setPrinter(QPrinter *printer);

   void setupPrinter() const;

 private :
   GUI_CS_SLOT_1(Private, void pageOrientationChanged())
   GUI_CS_SLOT_2(_pageOrientationChanged)

   GUI_CS_SLOT_1(Private, void pageSizeChanged())
   GUI_CS_SLOT_2(pageSizeChanged)

   GUI_CS_SLOT_1(Private, void pagesPerSheetChanged())
   GUI_CS_SLOT_2(pagesPerSheetChanged)

   GUI_CS_SLOT_1(Private, void unitChanged())
   GUI_CS_SLOT_2(unitChanged)

   GUI_CS_SLOT_1(Private, void topMarginChanged(double newValue))
   GUI_CS_SLOT_2(topMarginChanged)

   GUI_CS_SLOT_1(Private, void bottomMarginChanged(double newValue))
   GUI_CS_SLOT_2(bottomMarginChanged)

   GUI_CS_SLOT_1(Private, void leftMarginChanged(double newValue))
   GUI_CS_SLOT_2(leftMarginChanged)

   GUI_CS_SLOT_1(Private, void rightMarginChanged(double newValue))
   GUI_CS_SLOT_2(rightMarginChanged)

   void updateWidget();
   void initUnits();
   void initPagesPerSheet();
   void initPageSizes();

   Ui::QPageSetupWidget m_ui;
   QPagePreview *m_pagePreview;
   QPrinter *m_printer;

   QPrinter::OutputFormat m_outputFormat;

   QString m_printerName;
   QPageLayout m_pageLayout;
   QPageLayout::Unit m_units;
   bool m_blockSignals;

   friend class QUnixPrintWidgetPrivate;  // Needed by checkFields()

};



#endif // QT_NO_PRINTDIALOG
#endif