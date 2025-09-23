#include "event.h"

template <typename T>
Event<T>::Event()
{

}

template <typename T>
void Event<T>::bind(std::function<void(T)> function)
{
    bound_functions.append(function);
}

template <typename T>
void Event<T>::unbind(std::function<void(T)> function)
{
    bound_functions.remove(function);
}

template <typename T>
void Event<T>::trigger(T arg)
{
    for(int i = 0; i < bound_functions.count(); i++)
    {
        bound_functions[i](arg);
    }
}
