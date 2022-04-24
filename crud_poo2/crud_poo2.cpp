#include "proveedores2.h"
#include <iostream>

using namespace std;


int main() {
	
	string proveedor, direccion;
	int nit, telefono, idProveedores;


	Proveedores2 c = Proveedores2(idProveedores, proveedor, nit, direccion, telefono);
	
	c.crear();
	c.leer();
	c.modificar();
	c.eliminar();
	c.menu();
};


