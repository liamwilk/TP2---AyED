#include <iostream>
#include "listas.hpp"

using namespace std;

struct Pizza
{
	string gusto;
	int cant;
};

// ============ ENTEROS
int criterio_int(int a, int b)
{
	return a - b;
}

// ============ STRING
int criterio_str(string a, string b)
{
	return (a < b) ? -1 : (a > b);
}

// ============ Pizza buscando por GUSTO
int criterio_pizza(Pizza a, Pizza b)
{
	if (a.gusto == b.gusto)
		return 0;
	else
		return a.gusto > b.gusto ? 1 : -1;
}

ostream &operator<<(ostream &os, Pizza &p)
{
	os << p.gusto << " : " << p.cant;
	return os;
}

int main()
{
	Nodo<int> *pila = nullptr;
	Nodo<int> *pilau = nullptr;
	// pop(pila);//provoco error para ver como funciona
	push(pila, pilau, 1);
	push(pila, pilau, 2);
	push(pila, pilau, 3);
	cout << "Pila (1 2 3)" << endl;
	mostrar(pila, pilau);
	cout << endl
		 << "Eliminamos" << endl;
	while (pila != nullptr)
		cout << pop(pila, pilau) << endl;
	cout << endl
		 << "Confirmamos pila vacía:" << endl;
	mostrar(pila, pilau);
	cout << "fin mostrar pila" << endl;
	cout << "-----------------" << endl;

	Nodo<string> *cola = nullptr;
	Nodo<string> *colau = nullptr;
	agregar(cola, colau, "uno"s);
	agregar(cola, colau, "dos"s);
	agregar(cola, colau, "tres"s);
	cout << endl
		 << "Cola (uno dos tres)" << endl;
	mostrar(cola, colau);
	cout << endl
		 << "Eliminamos" << endl;
	while (cola != nullptr)
		cout << pop(cola, colau) << endl;
	cout << endl
		 << "Confirmamos cola vacía:" << endl;
	mostrar(cola, colau);
	cout << "fin mostrar cola" << endl;
	cout << "-----------------" << endl;

	agregar(cola, colau, "Juan"s);
	agregar(cola, colau, "Pedro"s);
	agregar(cola, colau, "María"s);
	cout << endl
		 << "Datos para la búsqueda" << endl;
	mostrar(cola, colau);
	string nombre;
	cout << endl
		 << "Ingrese el nombre a buscar: ";
	while (cin >> nombre)
	{
		if (buscar_lineal(nombre, cola, colau, criterio_str) != nullptr)
			cout << nombre << " SI está en la lista" << endl;
		else
			cout << nombre << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}

	cin.clear(); // como force EOF debo limpiar los bits de error
	cout << endl
		 << "-----------------" << endl;
	Nodo<Pizza> *lista = nullptr;
	Nodo<Pizza> *listau = nullptr;

	agregar(lista, listau, {"Muza", 4});
	agregar(lista, listau, {"Fugazzeta", 1});
	agregar(lista, listau, {"Especial", 3});
	agregar(lista, listau, {"Pizzaiola", 2});
	cout << endl
		 << "Pedidos en la lista:" << endl;
	mostrar(lista, listau);
	Pizza pizzaClave;
	Pizza *ptrPizza;
	cout << endl
		 << "Ingrese el gusto a buscar: ";
	while (cin >> pizzaClave.gusto)
	{
		ptrPizza = buscar_lineal(pizzaClave, lista, listau, criterio_pizza);
		if (ptrPizza != nullptr)
			cout << pizzaClave.gusto << " SI está en la lista ==> " << *ptrPizza << endl;
		else
			cout << pizzaClave.gusto << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}
	return EXIT_SUCCESS;
}
