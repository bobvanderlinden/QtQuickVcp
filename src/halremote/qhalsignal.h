#ifndef QHALSIGNAL_H
#define QHALSIGNAL_H

#include <QObject>
#include <QVariant>
#include "message.pb.h"

class QHalSignal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(ValueType type READ type NOTIFY typeChanged)
    Q_PROPERTY(QVariant value READ value NOTIFY valueChanged)
    Q_PROPERTY(int handle READ handle NOTIFY handleChanged)
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool synced READ synced NOTIFY syncedChanged)
    Q_ENUMS(ValueType)

public:
    explicit QHalSignal(QObject *parent = 0);

    enum ValueType {
        Bit = pb::HAL_BIT,
        Float = pb::HAL_FLOAT,
        S32 = pb::HAL_S32,
        U32 = pb::HAL_U32
    };

    QString name() const
    {
        return m_name;
    }

    ValueType type() const
    {
        return m_type;
    }

    QVariant value() const
    {
        return m_value;
    }

    int handle() const
    {
        return m_handle;
    }

    bool enabled() const
    {
        return m_enabled;
    }

    bool synced() const
    {
        return m_synced;
    }

public slots:
    void setName(QString arg);
    void setType(ValueType arg);
    void setValue(QVariant arg);
    void setHandle(int arg);
    void setEnabled(bool arg);
    void setSynced(bool arg);

signals:
    void nameChanged(QString arg);
    void typeChanged(ValueType arg);
    void valueChanged(QVariant arg);
    void handleChanged(int arg);
    void enabledChanged(bool arg);
    void syncedChanged(bool arg);

private:
    QString m_name;
    ValueType m_type;
    QVariant m_value;
    int m_handle;
    bool m_enabled;
    bool m_synced;
};

#endif // QHALSIGNAL_H
