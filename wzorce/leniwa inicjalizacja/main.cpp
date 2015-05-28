#include <cstdio>

class IProduct //INFO: dowolny interfejs produktu
{
public:
    virtual ~IProduct() { }
};

class TLazyCreator //INFO: leniwa inicjalizacja
{
private:
    IProduct * m_pProduct;
public:
    IProduct * GetProduct()
    {
        if( !m_pProduct )
             m_pProduct = CreateProduct();

        return m_pProduct;
    }

    TLazyCreator()
        : m_pProduct( NULL )
    {
    }
protected:
    virtual IProduct * CreateProduct() = 0;
};

class CMyProduct
    : public IProduct //INFO: implementacja produktu
{
public:
    CMyProduct()
    {
        printf( "Utworzylem CMyProduct.\n" );
    }
};

class CMyLazyCreator: public TLazyCreator //INFO: implementacja leniwej inicjalizacji
{
    virtual IProduct * CreateProduct()
    {
        return new CMyProduct;
    }
};

int main()
{
    CMyLazyCreator object;
    printf( "CMyLazyCreator utworzony.\n" );
    IProduct * pProduct = object.GetProduct();
    printf( "Szykujemy sie do sprzatania.\n" );
    delete pProduct;

    return 0;
}
