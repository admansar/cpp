#ifndef iter_hpp
#define iter_hpp

template <typename T, typename U, typename Y>
void iter (T *arr, U size, Y (*function)( T&))
{
    U i;

    i = 0;
    while (i < size)
    {
        function (arr[i]);
        i++;
    }
}

template <typename T, typename U, typename Y>
void iter (T *arr, U size, Y (*function)(const T&))
{
    U i;

    i = 0;
    while (i < size)
    {
        function (arr[i]);
        i++;
    }
}

#endif
