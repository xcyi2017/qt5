# QML与C++数据绑定

## 暴露单个C++类的属性

通过这种方法，QML中可以直接访问注册到上下文的C++类实例，并且是注册到QML的全局（具体是注册到一个QQuickView或者engine）。

## 类定义

需要暴露给QML访问的类需要有特殊的定义：

```cpp
/*name.h*/
#include <QObject>

class Name : public QObject // 继承自QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY  dataChange)

public:
    Name(QObject *parent = nullptr);
    Name(QString_name);

    QString data() const; // READ接口

    void setData(const QString& _data); // WRITE 接口
    
signals:
    QString dataChange(); // NOTIFY信号（不需实现）

private:
    QString m_data; // 私有属性
}
```

可以通过右键项目->新建文件->C++ Class 来添加新类，继承自 QObject 并且自动添加文件到项目中。

Warning：不要在 cpp 文件中直接定义类，因为 Q_OBJECT 宏需要经过 moc 处理，非 .h 文件不会被 moc 处理，编译时出现“无法识别的符号”错误。

`Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)`

这一行代码定义了暴露给QML访问的接口，这里我们提供的对象是一个 QString，READ 接口是一个名为 data 的函数， WRITE 接口是一个名为 setData 的函数，NOTIFY 接口用于通知的绑定，只有设置了 NOTIFY 接口，QML 才能自动与 C++ 中的属性同步。这里的命名方式最好与默认的统一。


```cpp
/*name.cpp*/
#include "name.h"
Name::Name(QObject *parent) : QObject(parent)
{//默认构造函数
}

Name::Name(QString _data) : m_data(_data)
{//自定义构造函数，初始化私有对象m_data
}

QString Name::data() const
{
	return m_data;//READ 接口实现，返回私有对象
}

void Name::setData(const QString& _data)
{
    if(_data != m_data) {//WRITE 接口实现，更新m_data并发出信号
        m_data = _data;
        emit dataChanged();
    }
} 
```
