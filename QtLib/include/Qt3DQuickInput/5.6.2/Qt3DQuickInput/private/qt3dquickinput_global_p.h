/****************************************************************************
**
** Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DQUICKINPUT_GLOBAL_P_H
#define QT3DQUICKINPUT_GLOBAL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DQuickInput/qt3dquickinput_global.h>
#include <QtQml/qqml.h>

#define QT3DQUICKINPUTSHARED_PRIVATE_EXPORT QT3DQUICKINPUTSHARED_EXPORT

QT_BEGIN_NAMESPACE

namespace Qt3DInput {

namespace Quick {

QT3DQUICKINPUTSHARED_PRIVATE_EXPORT void Quick3DInput_initialize();
QT3DQUICKINPUTSHARED_PRIVATE_EXPORT void Quick3DInput_registerType(const char *className, const char *quickName, int major, int minor);

template<class T, class E> void registerExtendedType(const char *className, const char *quickName,
                                                     const char *uri, int major, int minor, const char *name)
{
    qmlRegisterExtendedType<T, E>(uri, major, minor, name);
    Quick3DInput_registerType(className, quickName, major, minor);
}

template<class T> void registerType(const char *className, const char *quickName,
                                    const char *uri, int major, int minor, const char *name)
{
    qmlRegisterType<T>(uri, major, minor, name);
    Quick3DInput_registerType(className, quickName, major, minor);
}

} // Quick

} // Qt3D

QT_END_NAMESPACE

#endif // QT3DQUICKINPUT_GLOBAL_P_H
