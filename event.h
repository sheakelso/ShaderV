#ifndef EVENT_H
#define EVENT_H

#include <functional>
#include <QVector>

template <typename T> class Event
{
public:
    Event()
    {

    }

    void bind(std::function<void(T)> function)
    {
        bound_functions.append(function);
    }

    void unbind(std::function<void(T)> function)
    {
        bound_functions.remove(function);
    }

    void trigger(T arg)
    {
        for(int i = 0; i < bound_functions.count(); i++)
        {
            bound_functions[i](arg);
        }
    }

private:
    QVector<std::function<void(T)>> bound_functions;
};

#endif // EVENT_H
