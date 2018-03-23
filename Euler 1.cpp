int main()
{
    return (3 *(999/3) *(999/3+1 )/2+  // all multiples of 3 under 1000
            5 *(999/5) *(999/5+1 )/2-  // plus all multiples of 5 under 1000
            15*(999/15)*(999/15+1)/2); // minus all multiples of 15 under 1000
}
