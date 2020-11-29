#ifndef GEMINI_H
#define GEMINI_H

#include <QObject>
#include <QDebug>

class Gemini: public QObject
{
    Q_OBJECT
    Q_ENUMS(BALL_COLOR)
    Q_PROPERTY(unsigned int ballNumber READ ballNumber WRITE setBallNumber NOTIFY ballNumberChanged)
public:
    Gemini(QObject *parent = nullptr);

    enum BALL_COLOR {
        BALL_COLOR_YELLOW,
        BALL_COLOR_RED,
        BALL_COLOR_BLUE,
        BALL_COLOR_ALL
    };

    Q_INVOKABLE void stop();
    unsigned int ballNumber() const;
    void setBallNumber(const unsigned int& _ballNumber);

signals:
    void begin();
    void ballNumberChanged();

public slots:

    void doSomething(BALL_COLOR ballColor);
    void cppSlot(const QString& message);

private:
    BALL_COLOR m_ballColor;
    unsigned int m_ballNumber;

};

#endif // GEMINI_H
