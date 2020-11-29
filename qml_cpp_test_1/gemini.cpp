#include "gemini.h"

Gemini::Gemini(QObject *parent)
    :QObject(parent)
    ,m_ballColor(BALL_COLOR_YELLOW)
    ,m_ballNumber(0)
{

}

void Gemini::stop()
{
    qDebug() << "Gemini::stop() called...";
}

unsigned int Gemini::ballNumber() const
{
    return m_ballNumber;
}

void Gemini::setBallNumber(const unsigned int &_ballNumber)
{
    if (m_ballNumber != _ballNumber) {
        m_ballNumber = _ballNumber;
        emit ballNumberChanged();
    }
}

void Gemini::doSomething(Gemini::BALL_COLOR ballColor)
{
    qDebug() << "Gemini::doSomething() called..";
    if (ballColor != m_ballColor)
    {
        m_ballColor = ballColor;
        qDebug() << "ballColor changed ...";
    }
}

void Gemini::cppSlot(const QString &message)
{
    qDebug() << "called the C++ slot with message " << message;
}


