#pragma once
#pragma once
#include <iostream>

using namespace std;
class Proveedores {

protected: string proveedor, direccion;
		 int nit, telefono,idProveedores;



protected:
	Proveedores() {
	}

	Proveedores(int id,string prov, int n, string dir, int tel) {

		idProveedores = id;
		proveedor = prov;
		nit = n;
		direccion = dir;
		telefono = tel;




	}
};

