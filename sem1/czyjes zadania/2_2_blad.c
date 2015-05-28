int main()
{
    int *p;
    double q, tymcz;
    tymcz = 1234.34;
    p=&tymcz; // wskaznik wskazuje na zmienn¹ typu double, a sam zosta³ zadeklarowany dla typu integer
    q=*p; 
    printf(”%f”,q);
    return 0;
}
