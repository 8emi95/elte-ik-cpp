template <typename TContainer>
void printC(const TContainer &cont) // print container contents
{
    typename TContainer::const_iterator it = cont.begin();
    for (it = cont.begin(); it != cont.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template <typename TContainer>
void revPrintC(const TContainer &cont) // reverse print container contents
{
    typename TContainer::const_reverse_iterator it = cont.rbegin();
    for (it = cont.rbegin(); it != cont.rend(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template <typename T, int N>
void printArr(const T(&arr)[N])  // print array contents
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}