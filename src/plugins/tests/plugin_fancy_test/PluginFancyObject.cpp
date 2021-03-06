#include "PluginFancyObject.h"
#include "QPluginManager.h"
#include "debug.h"
#include <QMainWindow>
#include<QLabel>
#include<QLayout>
#include<QPushButton>

PluginFancyObject::PluginFancyObject(QObject *Parent):QBasePluginObject ( Parent  ),m_Win(nullptr){

}

PluginFancyObject::~PluginFancyObject()
{
    DeInitialize();
}

void PluginFancyObject::SetName(const QString &name)
{
    if( m_Win )
    {
        m_Win->setWindowTitle( name );
    }
}

bool PluginFancyObject::Initialize()
{
    m_Win = new QMainWindow();
    QLabel* label = new QLabel( );
    label->setText("PluginFancyObject Demo");
    m_Win->setCentralWidget(label);
    QPushButton* button = new QPushButton(m_Win);

    m_Win->show();
    m_Win->setAttribute(Qt::WA_DeleteOnClose, true);
    connect( m_Win, SIGNAL(destroyed(QObject*)), this, SLOT(MainWinDestroyed(QObject*)) );
    connect( button, SIGNAL(clicked(bool)), this, SLOT(ShowPlugins()) );
}

void PluginFancyObject::DeInitialize()
{
    if( m_Win ){
        m_Win->deleteLater();
    }
    DEBUG_V << "PluginFancyObject destroyed";
}

void PluginFancyObject::MainWinDestroyed( QObject* obj )
{
    m_Win = nullptr;
    deleteLater();
    if( nullptr == obj )
        DEBUG << "Strange::!!!";

}

void PluginFancyObject::ShowPlugins()
{
    Daqster::QPluginManager* pm = Daqster::QPluginManager::instance();
    if( nullptr != pm )
    {
        DEBUG << "Plugin Manager: " << pm;
   //     pm->SearchForPlugins();
        pm->ShowPluginManagerGui( m_Win );
    }
}
