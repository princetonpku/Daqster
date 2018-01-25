#ifndef PLUGINMAININTERFACE_H
#define PLUGINMAININTERFACE_H

#include <QObject>
#include "plugin_global.h"
#include "QDaqsterPluginInterface.h"


using namespace Daqster;


class PLUGIN_EXPORT PluginMainInterface:  public QDaqsterPluginInterface
{
    Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID IID_DAQSTER_PLUGIN_INTERFACE FILE "PluginMainTest.json")
#endif
    Q_INTERFACES(Daqster::QDaqsterPluginInterface)
public:
    PluginMainInterface( QObject* parent = 0);
    ~PluginMainInterface(  );
protected:
    virtual Daqster::QBasePluginObject* CreatePluginInternal(QObject* Parrent = NULL);
};

#endif // DATAPLOTINTERFACE_H
