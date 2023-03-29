#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED

template <typename T>
struct Nodo
{
	T dato;		  // valor que contiene el nodo
	Nodo<T> *sig; // puntero al siguiente nodo
};

template <typename T>
void push(Nodo<T> *&pila, Nodo<T> *&pilau, T valor)
{
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;

	if (pilau == nullptr)
	{
		pilau = nuevo;
	}
}

template <typename T>
T pop(Nodo<T> *&pila, Nodo<T> *&pilau)
{
	if (pila == nullptr)
	{
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		// modo no recomendado de terminar, en particular si uso objetos
	};
	if (pila->sig == nullptr)
	{
		pilau = nullptr;
	};
	T valor = pila->dato;
	Nodo<T> *aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

template <typename T>
void agregar(Nodo<T> *&p, Nodo<T> *&q, T valor)
{
	Nodo<T> *nuevo = new Nodo<T>; // crea un nodo vacío
	nuevo->dato = valor;		  // se le pone información
	nuevo->sig = nullptr;
	if (q != nullptr) // si q no esta vacio, es porque tengo algo en p
	{
		q->sig = nuevo; // hago que el siguiente de q(el ultimo)sea el nuevo
	}
	else // si esta vacio
	{
		p = nuevo; // agrego al principio
	}

	q = nuevo; // pongo a q en el ultimo
}




/* busqueda lineal si no hubiese criterio:

template <typename T>
T *buscar_lineal(Nodo<T> *&primero, Nodo<T> *&ultimo, T clave) // BUSCAR LINEAL PTR PRIMERO
{
	int flag = 0;
	while (primero != nullptr)
	{
		if (primero->dato == clave)
		{
			flag = 1;
			std::cout << "Se ha encontrado el valor" << std::endl;
			return &primero->dato;
		}
		primero = primero->sig;
	}
	if (flag == 0)
	{
		std::cout << "No se ha encontrado el valor" << std::endl;
	}

	return nullptr;
} */




template <typename T> T* buscar_lineal(T clave, Nodo<T>* lista, Nodo<T>* listau, int (*criterio)(T, T))
{
	while (lista != nullptr) {
		if (criterio(lista->dato, clave) == 0)
			return &lista->dato;
		lista = lista->sig;
	}
	return nullptr;
}

template <typename T>
void mostrar(Nodo<T> *pila, Nodo<T> *pilau)
{
	while (pila != nullptr)
	{
		std::cout << pila->dato << std::endl;
		pila = pila->sig;
	}
}

#endif // LISTAS_HPP_INCLUDED