#pragma once
# include <iostream>
#include "proveedores.h"
#include "Conexion_DB.h"
#include "mysql.h"
#include <string>

using namespace std;

class Proveedores2 : Proveedores {

	//constructor
public:
	Proveedores2() {

	}

	Proveedores2(int id, string prov, int n, string dir, int te) : Proveedores(id, prov, n, dir, te) {


	}

	//metodos
	//set(modificar)
	void setIdProveedores(int id) { idProveedores = id; }
	void setProveedores(string prov) { proveedor = prov; }
	void setNit(int n) { nit = n; }
	void setDirecciones(string dir) { direccion = dir; }
	void setTelefonos(int te) { telefono = te; }

	//get (mostrar)
	int getIdProveedores() { return idProveedores; }
	string getProveedor() { return proveedor; }
	int getNit() { return nit; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }


	//metodos

	void crear() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id = to_string(idProveedores);
			string n = to_string(nit);  //pasar int a un string
			string tel = to_string(telefono);
			string insert = "INSERT INTO proveedores(idproveedores,proveedor,nit,direccion,telefono)VALUES("+id+",'" + proveedor + "'," + n + ",'" + direccion + "'," + tel + ");";
			const char* i = insert.c_str();                               //esta linea ejecuta el insert into.
			q_estado = mysql_query(cn.getconectar(), i);                         //esta linea ejecuta el insert into.
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}
	void leer() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from proveedores";          // select, muestra los puestos _ endl while fila								
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "--------------Productos-------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << ";" << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}

			}
		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id = to_string(idProveedores);
			string n = to_string(nit);  //pasar int a un string
			string tel = to_string(telefono);
			string update = "UPDATE proveedores SET idProveedores = " + id + ",proveedor='" + proveedor + "',nit=" + n + ",direccion='" + direccion + "',telefono=" + tel + " where  idProveedores = " + id + ";";
			const char* i = update.c_str();                               //esta linea ejecuta el insert into.
			q_estado = mysql_query(cn.getconectar(), i);                         //esta linea ejecuta el insert into.
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
	int q_estado;
	Conexion_BD cn = Conexion_BD();
	cn.abrir_conexion();
	if (cn.getconectar()) {
		string id = to_string(idProveedores);
		string n = to_string(nit);  //pasar int a un string
		string tel = to_string(telefono);
		string delet = "DELETE from proveedores where  idProveedores = " + id + ";";
		const char* i = delet.c_str();                               //esta linea ejecuta el insert into.
		q_estado = mysql_query(cn.getconectar(), i);                         //esta linea ejecuta el insert into.
		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}

	}
	else {
		cout << "xxxxError al Ingresar Informacion xxxx" << endl;
	}
	cn.cerrar_conexion();

}
	
	
	
	void menu() {
		int opc;
		do {
			system("cls");
			cout << "----------MENU---------\n";
			cout << "\n 1. Ingresar proveedor " << endl;
			cout << "\n 2. Modificar " << endl;
			cout << "\n 3. eliminar" << endl;
			cout << "\n 4. ver " << endl;
			cout << "\n ----Ingrese una Opcion----" << endl;
			cin >> opc;

			switch (opc) {
			case 1:
				crear();
				cout << "Ingrese Id Proveedor:\n";
				cin >> idProveedores;
				cout << "Ingrese Proveedor:\n";
				cin >> proveedor;
				cout << "Ingresar Nit:\n";
				cin >> nit;
				cout << "Ingrese Direccion:\n";
				cin >> direccion;
				cout << "Ingresar Telefono:\n";
				cin >> telefono;

				break;
				

			case 2:
				modificar();
				cout << "Id de registro que desea editar:\n" << endl;
				cin >> idProveedores;
				cout << "Ingrese Proveedor:\n";
				cin >> proveedor;
				cout << "Ingresar Nit:\n";
				cin >> nit;
				cout << "Ingrese Direccion:\n";
				cin >> direccion;
				cout << "Ingresar Telefono:\n";
				cin >> telefono;
				
				break;

			case 3:
				eliminar();
				cout << "Id de registro que desea eliminar:\n" << endl;
				cin >> idProveedores;
				
				break;

			case 4:
				
				leer();

				break;
			}

			system("pause");
			break;
		} while (opc <= 4);

		menu();
		
	}
	};