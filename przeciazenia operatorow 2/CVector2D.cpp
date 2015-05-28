#include "CVector2D.h"
#include <iostream>

CVector2D::CVector2D(float fX = 0.0f, float fY = 0.0f)
{
    m_fX = fX; m_fY = fY;
}

CVector2D::~CVector2D()
{
    //dtor
}

void CVector2D::wypisz()
{
    std::cout << "[" << m_fX << "," << m_fY << "]" << std::endl;
}

CVector2D CVector2D::operator+() const
{ return CVector2D(+m_fX, +m_fY); }

CVector2D CVector2D::operator-() const
{ return CVector2D(-m_fX, -m_fY); }

// preinkrementacja
CVector2D CVector2D::operator++()
{ ++m_fX; ++m_fY; return *this; }

// postinkrementacja
CVector2D CVector2D::operator++(int)
{
 CVector2D vWynik = *this;
 ++(*this);
 return vWynik;
}

CVector2D CVector2D::operator+(const CVector2D& vWektor1)
{
    return CVector2D(vWektor1.m_fX + m_fX,
    vWektor1.m_fY + m_fY);
}


CVector2D CVector2D::operator*(float fLiczba) const
 { return CVector2D(m_fX * fLiczba, m_fY * fLiczba); }

CVector2D operator*(float fLiczba, const CVector2D& vWektor)
{ return vWektor * fLiczba; }






