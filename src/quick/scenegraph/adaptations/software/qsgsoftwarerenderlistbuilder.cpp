/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtQuick module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qsgsoftwarerenderlistbuilder_p.h"

#include "qsgsoftwarerenderablenode_p.h"
#include "qsgabstractsoftwarerenderer_p.h"
#include "qsgsoftwareimagenode_p.h"
#include "qsgsoftwarerectanglenode_p.h"
#include "qsgsoftwareglyphnode_p.h"
#include "qsgsoftwareninepatchnode_p.h"
#include "qsgsoftwarepainternode_p.h"
#include "qsgsoftwarepixmaptexture_p.h"

#include <QtQuick/QSGSimpleRectNode>
#include <QtQuick/qsgsimpletexturenode.h>

QT_BEGIN_NAMESPACE

QSGSoftwareRenderListBuilder::QSGSoftwareRenderListBuilder(QSGAbstractSoftwareRenderer *renderer)
    : m_renderer(renderer)
{

}

bool QSGSoftwareRenderListBuilder::visit(QSGTransformNode *)
{
    return true;
}

void QSGSoftwareRenderListBuilder::endVisit(QSGTransformNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGClipNode *)
{
    return true;
}

void QSGSoftwareRenderListBuilder::endVisit(QSGClipNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGGeometryNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGGeometryNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGOpacityNode *)
{
    return true;
}

void QSGSoftwareRenderListBuilder::endVisit(QSGOpacityNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGImageNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGImageNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGPainterNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGPainterNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGRectangleNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGRectangleNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGGlyphNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGGlyphNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGNinePatchNode *node)
{
    return addRenderableNode(node);
}

void QSGSoftwareRenderListBuilder::endVisit(QSGNinePatchNode *)
{
}

bool QSGSoftwareRenderListBuilder::visit(QSGRootNode *)
{
    return true;
}

void QSGSoftwareRenderListBuilder::endVisit(QSGRootNode *)
{
}

bool QSGSoftwareRenderListBuilder::addRenderableNode(QSGNode *node)
{
    auto renderableNode = m_renderer->renderableNode(node);
    if (renderableNode == nullptr) {
        // Not a node we can render
        return false;
    }
    m_renderer->appendRenderableNode(renderableNode);
    return true;
}

QT_END_NAMESPACE