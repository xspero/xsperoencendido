#ifndef BACKLIGHTCONTROLLER_H
#define BACKLIGHTCONTROLLER_H

#include <QObject>
#include <QString>

class BacklightController : public QObject
{
    Q_OBJECT
public:
    explicit BacklightController(QObject *parent = 0);

signals:

public slots:
    void backlightOn();
    void backlightCountdown();

private:
    bool          m_on {false};
    int           m_countdown {0};
};

#endif // BACKLIGHTCONTROLLER_H
