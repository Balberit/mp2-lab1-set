// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	BitLen=len;
	MemLen=len/31;
	if (len&31!=0)
		MemLen++;
	pMem=new TELEM [MemLen];
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen=bf.BitLen;
	MemLen=bf.MemLEn;
	pMem=bf.pMem;
}

TBitField::~TBitField()
{
	delete [] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	if (n>BitLen)
		return 0;
	int m;
	TLEM* mask;
	mask=new TELEM [MemLen];
  	m=n/31;
	if (n%31>0)
	{
		m++;
		mask[m]=(1>>n%31);
		return mask[m];
	}
	else 
	{
		mask[m]=(1>>31);
		return mask[m];
	}
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	TELEM* m;
	int c=0;
	if (n<BitLen)
	{
		while ()
		{
			if (n<31)
				break;
			n=n-31;
			c++;
		}
	m=new TELEM
	pMem[c]|(1>>n);
	}
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLine;
}

void TBitField::SetBit(const int n) // установить бит
{
	int c=0;
	if (n<BitLen)
	{
		while ()
		{
			if (n<31)
				break;
			n=n-31;
			c++;
		}
	pMem[c]=pMem[c]|(1>>n);
	}
}

void TBitField::ClrBit(const int n) // очистить бит
{

	int c=0;
	if (n<BitLen)
	{
		while ()
		{
			if (n<31)
				break;
			n=n-31;
			c++;
		}
	pMem[c]=pMem[c]&(~(1>>n));
	}
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	int d;  
	int c=0;
	if (n<BitLen)
	{
		while ()
		{
			if (n<31)
				break;
			n=n-31;
			c++;
		}
	d=pMem[c]&(1>>n);
	}
  return d;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	int i=0;
	BitLen=bf.BitLen;
	MemLen=bf.MemLen;
	pMem=new TELEM [MemLen];
	while (i<Memlen)
	{
		pMem[i]=bf.pMem[i];
		i++;
	}
	return this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  int i=0;
  if (this.GetLine==bf.GetLine)
  {
  	while (i<=MemLen)
  	{
		if (this.pMem[i]!=bf.pMem[i])
			return 0;
		i++;
	}
	return 1;
  }
  return 0;
}
int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  if (this==bf)
  	return 0;
  return 1;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
 if (this.BitLen==bf.BitLen)
 {
	TBitField bf1(MemLen);
	int h=0;
	while (h<MemLen)
	{
		bf1.pMem[h]=(this.pMem[h]|bf.pMem[h]);
		h++;
	}
}
 return bf1;
}//логическое сложение (01+10=11, а так же 01+01=01)

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
  if (this.BitLen==bf.BitLen)
 {
	TBitField bf1(MemLen);
	int h=0;
	while (h<MemLen)
	{
		bf1.pMem[h]=(this.pMem[h]&bf.pMem[h]);
		h++;
	}
}
 return bf1;
}//логическое умножение (11*10=10)

TBitField TBitField::operator~(void) // отрицание
{
	int h=0;
	while (h<MemLen)
	{
		pMem[h]=(~pMem[h]);
		h++;
	}
 return bf1;
}//логическое отрицание (~01=10)

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
  int i=0;
  while (i<MemLen)
  {
	istr>>bf.pMem[i];
	i++;
  }
  return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
  int i=0;
  while (i<MemLen)
  {
	ostr<<bf.pMem[i];
	i++;
  }
  return ostr;
}
