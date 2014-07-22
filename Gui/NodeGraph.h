//  Natron
//
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
*Created by Alexandre GAUTHIER-FOICHAT on 6/1/2012. 
*contact: immarespond at gmail dot com
*
*/

#ifndef NATRON_GUI_NODEGRAPH_H_
#define NATRON_GUI_NODEGRAPH_H_

#include <vector>
#include <map>
#include "Global/Macros.h"
CLANG_DIAG_OFF(deprecated)
CLANG_DIAG_OFF(uninitialized)
#include <QGraphicsView>
CLANG_DIAG_ON(deprecated)
CLANG_DIAG_ON(uninitialized)

#ifndef Q_MOC_RUN
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#endif

#include "Global/GlobalDefines.h"

class QVBoxLayout;
class QScrollArea;
class QEvent;
class QKeyEvent;
class Gui;
class NodeGui;
class QDropEvent;
class QDragEnterEvent;
class NodeSerialization;
class NodeGuiSerialization;
class NodeBackDropSerialization;
class NodeBackDrop;
struct NodeGraphPrivate;
namespace Natron{
    class Node;
}

class NodeGraph: public QGraphicsView , public boost::noncopyable
{
        
    Q_OBJECT

public:

    explicit NodeGraph(Gui* gui,QGraphicsScene* scene=0,QWidget *parent=0);

    virtual ~NodeGraph() OVERRIDE;
 
    void setPropertyBinPtr(QScrollArea* propertyBin);
    
    boost::shared_ptr<NodeGui> getSelectedNode() const;
    
    boost::shared_ptr<NodeGui> createNodeGUI(QVBoxLayout *dockContainer,const boost::shared_ptr<Natron::Node>& node,bool requestedByLoad);
    
    void selectNode(const boost::shared_ptr<NodeGui>& n);
    
    ///The visible portion of the graph, in scene coordinates.
    QRectF visibleRect();
    
    void deselect();
    
    QImage getFullSceneScreenShot();
    
    bool areAllNodesVisible();
    
    void updateNavigator();
    
    const std::list<boost::shared_ptr<NodeGui> >& getAllActiveNodes() const;
    
    std::list<boost::shared_ptr<NodeGui> > getAllActiveNodes_mt_safe() const;
    
    void moveToTrash(NodeGui* node);
    
    void restoreFromTrash(NodeGui* node);
    
    QGraphicsItem* getRootItem() const;
    
    Gui* getGui() const;
    
    void discardGuiPointer();
    
    bool areAllPreviewTurnedOff() const;
    
    void refreshAllEdges();
    
    void centerOnNode(const boost::shared_ptr<NodeGui>& n);
    void deleteNode(const boost::shared_ptr<NodeGui>& n);
    void copyNode(const boost::shared_ptr<NodeGui>& n);
    void cutNode(const boost::shared_ptr<NodeGui>& n);
    boost::shared_ptr<NodeGui> duplicateNode(const boost::shared_ptr<NodeGui>& n);
    boost::shared_ptr<NodeGui> cloneNode(const boost::shared_ptr<NodeGui>& n);
    void decloneNode(const boost::shared_ptr<NodeGui>& n);
    
    void deleteBackdrop(NodeBackDrop* n);
    void copyBackdrop(NodeBackDrop* n);
    void cutBackdrop(NodeBackDrop* n);
    void duplicateBackdrop(NodeBackDrop* n);
    void cloneBackdrop(NodeBackDrop* n);
    void decloneBackdrop(NodeBackDrop* n);
    
    boost::shared_ptr<NodeGui> getNodeGuiSharedPtr(const NodeGui* n) const;
    
    void setUndoRedoStackLimit(int limit);
    
    void deleteNodePermanantly(boost::shared_ptr<NodeGui> n);
    
    NodeBackDrop* createBackDrop(QVBoxLayout *dockContainer,bool requestedByLoad);
    
    ///Returns true if it already exists
    bool checkIfBackDropNameExists(const QString& n,const NodeBackDrop* bd) const;
    
    std::list<NodeBackDrop*> getBackDrops() const;
    std::list<NodeBackDrop*> getActiveBackDrops() const;
    
    /**
     * @brief This function just inserts the given backdrop in the list
     **/
    void insertNewBackDrop(NodeBackDrop* bd);
    
    /**
     * @brief This function just removes the given backdrop from the list, it does not delete it or anything.
     **/
    void removeBackDrop(NodeBackDrop* bd);
    
    void pushRemoveBackDropCommand(NodeBackDrop* bd);
    
    std::list<boost::shared_ptr<NodeGui> > getNodesWithinBackDrop(const NodeBackDrop* bd) const;
    
    
public slots:
    
    void deleteSelectedNode();
    
    void deleteSelectedBackdrop();
    
    void connectCurrentViewerToSelection(int inputNB);

    void updateCacheSizeText();
    
    void showMenu(const QPoint& pos);
    
    void populateMenu();
    
    void toggleCacheInfos();
    
    void turnOffPreviewForAllNodes();
    
    void toggleAutoPreview();
    
    void forceRefreshAllPreviews();

    void onProjectNodesCleared();
    
    ///All these actions also work for backdrops
    void copySelectedNode();
    void cutSelectedNode();
    void pasteNodeClipBoard();
    void duplicateSelectedNode();
    void cloneSelectedNode();
    void decloneSelectedNode();
    
    void centerOnAllNodes();
    
    void toggleConnectionHints();
    
    void onTimeChanged(SequenceTime time,int reason);
    

private:
    
    /**
     * @brief Given the node, it tries to move it to the ideal position
     * according to the position of the selected node and its inputs/outputs.
     * This is used when creating a node to position it correctly.
     * It will move the inputs / outputs slightly to fit this node into the nodegraph
     * so they do not overlap.
     **/
    void moveNodesForIdealPosition(boost::shared_ptr<NodeGui> n);
    
    boost::shared_ptr<NodeGui> pasteNode(const NodeSerialization& internalSerialization,const NodeGuiSerialization& guiSerialization);
    
    NodeBackDrop* pasteBackdrop(const NodeBackDropSerialization& serialization,bool offset = true);
  

    virtual void enterEvent(QEvent *event) OVERRIDE FINAL;

    virtual void leaveEvent(QEvent *event) OVERRIDE FINAL;

    virtual void keyPressEvent(QKeyEvent *e) OVERRIDE FINAL;
    
    virtual void keyReleaseEvent(QKeyEvent* e) OVERRIDE FINAL;

    virtual bool event(QEvent* event) OVERRIDE FINAL;

    void mousePressEvent(QMouseEvent *event);
    
    void mouseReleaseEvent(QMouseEvent *event);
    
    void mouseMoveEvent(QMouseEvent *event);
    
    void mouseDoubleClickEvent(QMouseEvent *event);
    
    void resizeEvent(QResizeEvent* event);
    
    void paintEvent(QPaintEvent* event);

    void wheelEvent(QWheelEvent *event);

    void dropEvent(QDropEvent* event);
    
    void dragEnterEvent(QDragEnterEvent *ev);
    
    void dragMoveEvent(QDragMoveEvent* e);
    
    void dragLeaveEvent(QDragLeaveEvent* e);

private:
    
    boost::scoped_ptr<NodeGraphPrivate> _imp;
    
};


#endif // NATRON_GUI_NODEGRAPH_H_
