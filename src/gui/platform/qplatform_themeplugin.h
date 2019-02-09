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

#ifndef QPLATFORM_THEMEPLUGIN_H
#define QPLATFORM_THEMEPLUGIN_H

#include <qplugin.h>
#include <qfactoryinterface.h>

class QPlatformTheme;

#define QPlatformThemeFactoryInterface_iid "com.copperspice.CS.QPA.QPlatformThemeFactoryInterface.5.1"

class Q_GUI_EXPORT QPlatformThemePlugin : public QObject
{
    GUI_CS_OBJECT(QPlatformThemePlugin)

public:
    explicit QPlatformThemePlugin(QObject *parent = nullptr);
    ~QPlatformThemePlugin();

    virtual QPlatformTheme *create(const QString &key, const QStringList &paramList) = 0;
};

#endif