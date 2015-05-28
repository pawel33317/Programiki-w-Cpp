#ifndef CVECTOR2D_H
#define CVECTOR2D_H
#include <iostream>

class CVector2D
{
    public:
        explicit CVector2D(float,float);
        virtual ~CVector2D();
        void wypisz();
        CVector2D operator+() const;
        CVector2D operator-() const;

        CVector2D operator++(int);
        CVector2D operator++();




        CVector2D operator+(const CVector2D&);

        CVector2D operator*(float fLiczba) const;
        //ponizsza linia jest zbedna to bardziej taka informacja
        //nie mozemy przeciazac operaforow tej klasy tylko musimy float
        friend CVector2D operator*(float fLiczba, const CVector2D& vWektor);


    protected:
    private:
        float m_fX, m_fY;
};

#endif // CVECTOR2D_H
