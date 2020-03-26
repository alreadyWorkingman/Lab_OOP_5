#pragma once

extern enum typeEnk
{
	drill,      //Дрель
	screwdriver,   //Шуруповерт
	saw,           //Пила
	angleGrinder, //Болгарка
	plane,         //Рубанок
	jigsaw,			//Лобзик
	other
};

template <class T, class N>
class enk2
{
public:
	enk2();
	enk2(typeEnk t, char* n, T c, N m, int p);
	enk2(const enk2 &m);
	//~enk2();

	void input(typeEnk t, char* n, T c, float m, int p);
	void print();
	void copy(const enk2 &x); // & - ?
	enk2 summa(enk2 b);
	bool sravn(enk2 x);
	//friend bool operator ==(enk2 c1, enk2 c2);
	//friend bool operator !=(enk2 c1, enk2 c2);

	enk2&  operator++() //Префиксный
	{
		this->cost++;
		return *this;
	}
	enk2&  operator--() //Префиксный
	{
		if (cost > 0)
			this->cost--;
		return *this;
	}
	enk2 operator++ (int)
	{
		enk2 prev = *this;
		++*this;
		return prev;
	}
	enk2 operator--(int) //Постфиксный
	{
		enk2 tmp;
		tmp = *this;
		if (cost > 0)
			this->cost--;
		return tmp;
	}
	enk2&  operator = (const enk2 m)
	{
		this->copy(m);
		return *this;
	}
	enk2 operator += (enk2 m)
	{
		*this = this->summa(m);
		return *this;
	}
	enk2  operator + (const enk2 m)
	{
		return this->summa(m);
	}

	bool operator == (enk2 x)
	{
		return (type == x.type && !strcmp(name, x.name) && cost == x.cost && mass == x.mass && power == x.power);
	}
	bool operator != (enk2 x)
	{
		return !(type == x.type && !strcmp(name, x.name) && cost == x.cost && mass == x.mass && power == x.power);
	}
private:
	typeEnk type;
	char* name;
	T cost;
	float mass;
	int power;
	//Скорость
};









template <class T, class N>
enk2<T,N>::enk2()
{
	type = other;
	name = NULL;
	cost = 0;
	mass = 0;
	power = 0;
}

template <class T, class N>
enk2 <T,N>::enk2(typeEnk t, char* n, T c, N m, int p)
{
	type = t;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	cost = c;
	mass = m;
	power = p;								//Почему не вызвать инпут с параметрами х
}

template <class T, class N>
enk2<T, N>::enk2(const enk2 &x)
{
	if (&x != this)
	{
		type = x.type;
		if (x.name != NULL)
		{
			name = new char[strlen(x.name) + 1];
			strcpy(name, x.name);
		}
		cost = x.cost;
		mass = x.mass;
		power = x.power;                           //Почему не вызвать инпут с параметрами х
	}
}
//enk2::~enk2()
//{
//	//cout << "\n ~Вызов Деструктора\n";           //Удали <--------------------------------
//	delete[] name;
//}t
template <class T, class N>
void enk2<T,N>::input(typeEnk t, char* n, T c, float m, int p)
{
	type = t;
	if (name != NULL)
		delete[] name;
	if (n != NULL)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	cost = c;
	mass = m;
	power = p;
}
template <class T, class N>
void  enk2<T,N>::print()
{
	cout << "\nТип: " << GetTypeEnk(type) << " Навание: "; if (name != NULL)cout << name; else cout << "Нет названия";
	cout << "\nСтоимость: " << cost
		<< "\nМасса: " << mass
		<< "\nМощность: " << power << endl;
}
template <class T, class N>
void  enk2<T,N>::copy(const enk2 &x)
{
	if (&x != this)
		this->input(x.type, x.name, x.cost, x.mass, x.power);
}
template <class T, class N>
enk2<T,N> enk2<T,N>::summa(enk2 b)
{
	enk h;
	h.type = other;
	h.name = new char[strlen(name) + strlen(b.name) + 2];
	strcpy(h.name, name);
	strcat(h.name, "+");
	strcat(h.name, b.name);

	h.cost = cost + b.cost;
	h.mass = mass + b.mass;
	h.power = power + b.power;
	return h;
}
template <class T, class N>
bool  enk2<T,N>::sravn(enk2 x)
{
	return (type == x.type && !strcmp(name, x.name) && cost == x.cost && mass == x.mass && power == x.power);

}
//template <class N>
// bool operator == (enk2<N> c1, enk2<N> x)
//{
//	return (c1.type == x.type && !strcmp(c1.name, x.name) && c1.cost == x.cost && c1.mass == x.mass && c1.power == x.power);
//}
// template <class N>
// bool operator != (enk2<N> c1, enk2<N> x)
// {
//	 return !(c1.type == x.type && !strcmp(c1.name, x.name) && c1.cost == x.cost && c1.mass == x.mass && c1.power == x.power);
// }

