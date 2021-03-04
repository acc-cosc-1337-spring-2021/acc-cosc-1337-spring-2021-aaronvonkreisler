//cpp
int factorial(int num)
{
    int factory = 1;

    for (int i = 1; i <= num; ++i)
    {
        factory *= i;
    }

    return factory;
}