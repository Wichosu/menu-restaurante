#include <iostream>
using namespace std;
int foodPrice[6] = {18, 10, 15, 12, 8, 12}; //precios de la comida
//Muestra una lista de opciones a elegir para el usuario
void optionsList(){
    cout << "1.- Ver menu y ordenar" << endl;
    cout << "2.- Pagar" << endl;
    cout << "3.- Salir del programa" << endl; 
}

/* displayMenu muestra al usuario su el menu, el array foodName[] contiene el nombre de la comida
    mientras que el array foodPrice[] el precio, los index de ambos se complementan es decir 
    foodName[0] = "Tacos" y foodPrice[0] = "18", el index 0 de ambos arrays forman la oracion
    completa del producto y su precio respectivo*/

void displayMenu(){
    string foodName[6] = {"Tacos", "Empanadas", "Tortas", "Picaditas", "Agua", "Refresco"}; 
    int i = 0, maxFood = 6;
    for(i = 0; i < maxFood; i++){
        cout << i + 1 << ".- " << foodName[i] << "............." << "$" << foodPrice[i] << endl;
    }
}
/* Calcula la cuenta de lo que compor el cliente, se hace display de un menu especial
    para seleccionar que compro el cliente despues cuanto de eso compro y la cuenta
    se obtiene multiplicando la cantidad por el precio de la comida (el numero se 
    sustituye por la cantidad del array)*/
double total(){
    int food = 1, amount;
    double bill;
    while (food != 0){
        cout << "Ingrese el numero de lo que desea llevar" << endl;
        displayMenu();
        cout << "Ingrese 0 para salir" << endl;
        cin >> food;
        if(food == 0){
            break;
        }
        else if(food > 0 && food < 7){
            cout << "¿Cantidad?" << endl;
            cin >> amount;
            bill += (amount * foodPrice[food -1]);
        }
        else{
            cout << "Escoge una comida del 1 al 6" << endl;
        }
    }
    cout << "Orden tomada" << endl;
    return bill;
}

/* 
    el procedimiento deja al usuario escoger dos opciones 1 pagar con tarjeta y 
    2 pagar en efectivo, dependiendo de la opcion se solicita insertar la tarjeta/efectivo
    y se hace la resta con la cuenta, en este caso solo con el efectivo */

void payMethod( double bill){
    double money, exchange;
    cout << "La cuenta es $" << bill << endl;
    cout << "Porfavor ingrese el efectivo" << endl;
    cin >> money;
    exchange = money - bill;
    while(exchange < 0){
        cout << "Por favor ingrese el dinero restante" << endl;
        cout << "Faltan $" << abs(exchange) << endl;
        cin >> money;
        exchange = money - abs(exchange);
    }
    cout << "Su cambio es " << exchange << " Gracias por su compra" << endl;
}


int main(){
    double bill;
    int option = 0;
    const int exit = 3;
    cout << "Bienvenido por favor escoja una opcion" << endl;
    do{
        optionsList();
        cin >> option;
        switch (option){
        case 1:
            bill = total();
            break;
        case 2:
            payMethod(bill);
            break;
        case 3:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Escoja una opcion entre 1 y 5" << endl;
            break;
        }
    }
    while (option != exit);
    return 0;
}
