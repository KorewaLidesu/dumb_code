template <class T>
void repeatValue(T val, int times)
{
    int x;
    for (x = 0 ; x < times ; x++)
    {
        cout << "#" << (x + 1) << " " << val << endl;
    }
}
