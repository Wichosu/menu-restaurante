#include <iostream>
using namespace std;
int foodPrice[6] = {18, 10, 15, 12, 8, 12}; //precios de la comida
string foodName[6] = {"Tacos", "Empanadas", "Tortas", "Picaditas", "Agua", "Refresco"}; //nombre de la comida
//Muestra una lista de opciones a elegir para el usuario
void optionsList(){
    cout << "1.- Ver menu y ordenar" << endl;
    cout << "2.- Pagar" << endl;
    cout << "3.- Dejar un comentario" << endl;
    cout << "4.- Salir del programa" << endl; 
}

/* displayMenu muestra al usuario su el menu, el array foodName[] contiene el nombre de la comida
    mientras que el array foodPrice[] el precio, los index de ambos se complementan es decir 
    foodName[0] = "Tacos" y foodPrice[0] = "18", el index 0 de ambos arrays forman la oracion
    completa del producto y su precio respectivo*/

void displayMenu(){ 
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
    int food = 1, i = 0, amount, maxi, order, error;
    int countAmount[] = {};
    string storeNames[] = {};
    int foodOrders[] = {};
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
            storeNames[i] = foodName[food -1];
            countAmount[i] = amount;
            foodOrders[i] = foodPrice[food -1];
            i++;
        }
        else{
            cout << "Escoge una comida del 1 al 6" << endl;
        }
    }
    maxi = i;
    do{
        cout << "Serian" << endl;
        for(i = 0; i <= maxi; i++){
            cout << countAmount[i] << " " << storeNames[i] << endl;
            bill += countAmount[i] * foodPrice[foodOrders[i]];
        }
        cout << "Es correcta la orden?" << endl << "1.- Si      2.-No" << endl;
        cin >> order;
        switch (order){
        case 1:
            break;
        case 2:
            do{
                cout << "En que fallo la orden?" << endl;
                for ( i = 0; i <= maxi; i++){
                    cout << i + 1 << ".- " << countAmount[i] << " " << storeNames[i] << endl;
                }
                cin >> error;
                if (error > 0 && error < 7){
                    cout << "Que deseaba ordenar?" << endl;
                    displayMenu();
                    cin >> food;
                    storeNames[error-1] = storeNames[food - 1];
                    cout << "Cuanto deseaba ordenar?" << endl;
                    cin >> amount;
                    countAmount[error-1] = amount;
                }
                else{
                    cout << "Escoge un numero de tu orden" << endl;
                }
            }
            while(error < 1 && error > 6);
            break;
        default:
            cout << "Presione 1 para salir" << endl;
            break;
        }
    }
    while(order != 1);
    return bill;
}

/* TODO: aniadir cuenta y mostrarla a la hora de selecionar la opcion de pagar.
   TODO: Dar cambio.
    el procedimiento deja al usuario escoger dos opciones 1 pagar con tarjeta y 
    2 pagar en efectivo, dependiendo de la opcion se solicita insertar la tarjeta/efectivo
    y se hace la resta con la cuenta, en este caso solo con el efectivo */

void payMethod( double bill){
    int method;
    char money, creditCard;
    cout << "La cuenta es $" << bill << endl;
    cout << "Elija su metodo de pago" << endl << "1.-Tarjeta de credito" << endl << "2.-Efectivo" << endl;
    cin >> method;
    switch (method){
    case 1:
        cout << "Ingrese su tarjeta" << endl;
        cin >> creditCard;
        if (creditCard == 'y'){
            cout << "transaccion completada" << endl;
        }
        else{
            cout << "transaccion fallida" << endl;
        }
        break;
    case 2:
        cout << "Ingrese su efectivo" << endl;
        cin >> money;
        break;
    default:
        break;
    }
}


int main(){
    double bill;
    int option = 0;
    const int exit = 4;
    cout << "Bienvenido por favor escoja una opcion" << endl;
    do{
        optionsList();
        cin >> option;
        switch (option){
        case 1:
            bill = total();
            cout << bill << endl;
            break;
        case 2:
            payMethod(bill);
            break;
        case 3:
            //TODO: function leave a comment
            break;
        case 4:
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
