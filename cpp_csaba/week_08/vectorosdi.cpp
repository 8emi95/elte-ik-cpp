#include <iostream>
#include <vector>

// template<class C, class T = typename C::value_type > // c++11
// void printCont(const C<T> & cont){
//     const_iterator C<T>::const_iterator it = cont.begin();
// }

template <typename TContainer>
void printC(const TContainer &cont)
{
    typename TContainer::const_iterator it = cont.begin();
    for (it = cont.begin(); it != cont.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template <typename TContainer>
void revPrintC(const TContainer &cont)
{
    typename TContainer::const_reverse_iterator it = cont.rbegin();
    for (it = cont.rbegin(); it != cont.rend(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

// template <typename T>
// struct helper
// {
//     static void print(T value) { std::cout << value; }
// };
// template <typename T>
// struct helper<std::vector<T> >
// {
//     static void print(std::vector<T> const &value) {}
// };

// template <typename T>
// void print(T const &value)
// {
//     // Just delegate.
//     helper<T>::print(value);
// }

int main()
{
    std::vector<int> intVect;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    intVect.assign(arr, arr + 10);
    printC(intVect);
    revPrintC(intVect);

    // print (5);
    // std::vector<int> v;
    // print (v);
}