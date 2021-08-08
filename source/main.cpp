#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

// Osztályok
class Vehicle {
    protected:
        string licensePlateNumber;
        string type;
        int manufactureYear;
        int capacity;
        int stress;
    public:
        Vehicle() : Vehicle("000-000"){
        }

        Vehicle(string licensePlateNumber) : Vehicle(licensePlateNumber, "Unidentified"){
        }

        Vehicle(string licensePlateNumber, string type) : Vehicle(licensePlateNumber, type, 9999){
        }

        Vehicle(string licensePlateNumber, string type, int manufactureYear) : Vehicle(licensePlateNumber, type, manufactureYear, -1){
        }

        Vehicle(string licensePlateNumber, string type, int manufactureYear, int capacity) : Vehicle(licensePlateNumber, type, manufactureYear, capacity, -1){
        }

        Vehicle(string licensePlateNumber, string type, int manufactureYear, int capacity, int stress){
            setLicensePlateNumber(licensePlateNumber);
            this->type = type;
            this->manufactureYear = manufactureYear;
            this->capacity = capacity;
            this->stress = stress;

        }


        //Getter, Setter
        string getLicensePlateNumber(){
            return licensePlateNumber;
        }

        void setLicensePlateNumber(string value){
            if(value.length() == 7){
                licensePlateNumber = value;
            } else throw "Nem megfelelő rendszám hosszúság!";

        }

        string getType(){
            return type;
        }

        int getManufactureYear(){
            return manufactureYear;
        }

        int getCapacity(){
            return capacity;
        }

        int getStress(){
            return stress;
        }

        virtual string getTypeOfStress(){
            return "None";
        }



        // Metódusok
        virtual void printInformation(){
            cout << "\nJármű adatai:" << endl;
            cout << "\n  Rendszám:\t " << licensePlateNumber << endl;
            cout << "  Típus:\t " << type << endl;
            cout << "  Gyártás éve:\t " << manufactureYear << endl;
            cout << "  Kapacitás:\t " << capacity << endl;
            cout << "  Igénybevétel:\t " << stress << endl;
        }

        virtual Vehicle generate(){
            cout << "  Kérem a jármű rendszámát (NNN-NNN): ";
            string licensePlateNumber;
            cin >> licensePlateNumber;

            cout << "  Kérem a jármű típusát: ";
            string type;
            cin >> type;

            cout << "  Kérem a jármű gyártási évét: ";
            int manufactureYear;
            cin >> manufactureYear;

            cout << "  Kérem a jármű kapacitását: ";
            int capacity;
            cin >> capacity;

            cout << "  Kérem a jármű igénybevételét: ";
            int stress;
            cin >> stress;
            Vehicle vh(licensePlateNumber, type, manufactureYear, capacity, stress);
            return vh;
        }
};

class WorkMachine : public Vehicle {
    using Vehicle::Vehicle;
    public:

        void printInformation(){
            cout << "\nMunkagép adatai:" << endl;
            cout << "\n  Rendszám:\t " << licensePlateNumber << endl;
            cout << "  Típus:\t " << type << endl;
            cout << "  Gyártás éve:\t " << manufactureYear << endl;
            cout << "  Teljesítmény:\t " << capacity << " kW"<< endl;
            cout << "  Igénybevétel:\t " << stress << " munkaóra"<< endl;
        }

        Vehicle generate(){
            cout << "  Kérem a munkagép rendszámát (NNN-NNN): ";
            string licensePlateNumber;
            cin >> licensePlateNumber;

            cout << "  Kérem a munkagép típusát: ";
            string type;
            cin >> type;

            cout << "  Kérem a munkagép gyártási évét: ";
            int manufactureYear;
            cin >> manufactureYear;

            cout << "  Kérem a munkagép teljesítményét (kW): ";
            int capacity;
            cin >> capacity;

            cout << "  Kérem a munkagép igénybevételét (munkaóra): ";
            int stress;
            cin >> stress;
            WorkMachine wm(licensePlateNumber, type, manufactureYear, capacity, stress);
            return wm;
        }

        string getTypeOfStress(){
            return "munkaóra";
        }
};

class Truck : public Vehicle {
    using Vehicle::Vehicle;
    public:

        void printInformation(){
            cout << "\nTeheautó adatai:" << endl;
            cout << "\n  Rendszám:\t " << licensePlateNumber << endl;
            cout << "  Típus:\t " << type << endl;
            cout << "  Gyártás éve:\t " << manufactureYear << endl;
            cout << "  Teherbírás:\t " << capacity << " tonna"<< endl;
            cout << "  Igénybevétel:\t " << stress << " km"<< endl;
        }

        Vehicle generate(){
            cout << "  Kérem a teherautó rendszámát (NNN-NNN): ";
            string licensePlateNumber;
            cin >> licensePlateNumber;

            cout << "  Kérem a teherautó típusát: ";
            string type;
            cin >> type;

            cout << "  Kérem a teherautó gyártási évét: ";
            int manufactureYear;
            cin >> manufactureYear;

            cout << "  Kérem a teherautó teherbírását (tonna): ";
            int capacity;
            cin >> capacity;

            cout << "  Kérem a teherautó igénybevételét (km): ";
            int stress;
            cin >> stress;
            Truck t(licensePlateNumber, type, manufactureYear, capacity, stress);
            return t;
        }

        string getTypeOfStress(){
            return "km";
        }
};

class Bus : public Vehicle {
    using Vehicle::Vehicle;
    public:

        void printInformation(){
            cout << "\nAutóbusz adatai:" << endl;
            cout << "\n  Rendszám:\t " << licensePlateNumber << endl;
            cout << "  Típus:\t " << type << endl;
            cout << "  Gyártás éve:\t " << manufactureYear << endl;
            cout << "  Férőhely:\t " << capacity << " db"<< endl;
            cout << "  Igénybevétel:\t " << stress << " km"<< endl;
        }

        Vehicle generate(){
            cout << "  Kérem a autóbusz rendszámát (NNN-NNN): ";
            string licensePlateNumber;
            cin >> licensePlateNumber;

            cout << "  Kérem a autóbusz típusát: ";
            string type;
            cin >> type;

            cout << "  Kérem a autóbusz gyártási évét: ";
            int manufactureYear;
            cin >> manufactureYear;

            cout << "  Kérem a autóbusz férőhelyét (db): ";
            int capacity;
            cin >> capacity;

            cout << "  Kérem a autóbusz igénybevételét (km): ";
            int stress;
            cin >> stress;
            Bus b(licensePlateNumber, type, manufactureYear, capacity, stress);
            return b;
        }

        string getTypeOfStress(){
            return "km";
        }
};




// Menü kirajzolásához segéd függvények
void clear(){
    cout << "\x1B[2J\x1B[H";
}

int drawMenu(string array[], int size){
    int answer = 0;

    int i;
    for (i = 0; i < size; ++i){
      cout << " [" << i << "] " << array[i] << endl;
    }

    //cout << " [" << i << "] " << "Kilépés" << endl;


    cout << "\n  >> ";
    cin >> answer;


    if(array[answer] == "Kilépés"){
        return -2;
    }
    else if(answer >= 0 && answer < size){
        return answer;
    }
    else{
        return -1;
    }
}


// Menüpontok
void first(Vehicle array[], int index, int maxSize){

    if(index < maxSize){
        array[index] = array[index].generate();
    }else{
        cout << "  >> Elérte a maximálisan tárolható járművek számát, ebben a kategóriában! <<" << endl;
        cout << "  >> Kérem szerkessze a beállítások file tartalmát, a maximális méret növeléséért. <<" << endl;
    }

    //cout << index;
}


void second(Vehicle array[], int index){
    for(int i = 0; i < index; i++){
        array[i].printInformation();
    }
}

void third(Vehicle array[], int index){
    cout << " Adja meg a keresendő rendszámot: ";
    string licensePlateNumber;
    cin >> licensePlateNumber;

    bool found = false;

    for(int i = 0; i < index; i++){
        if(array[i].getLicensePlateNumber() == licensePlateNumber){
            cout << "  Megtalált jármű:" << endl;
            array[i].printInformation();
            found = true;
        }
    }

    if(found == false){
        cout << "  >> Nincs ilyen rendszámmal jármű az adatbázisban! <<";
    }
}

void fourth(Vehicle array[], int index){
    int sum = 0;
    string stress = array[0].getTypeOfStress();
    for(int i = 0; i < index; i++){
        sum += array[i].getStress();
    }

    cout << "  Az összesített Igénybevétel ebben a kategóriában: " << sum << " " << stress  << endl;
}

int fifth(Vehicle array[], int index){
    cout << "  Kérem adja meg az új szervízhatár értékét (" << array[0].getTypeOfStress() << "): ";


    int serviceBoundry;

    cin >> serviceBoundry;

    cout << "  >> Az új szervízhatár értéke felfrissítve! <<" << endl;
    return serviceBoundry;
}

void sixth(Vehicle array[], int index, int serviceBoundry){
    for(int i = 0; i < index; i++){
        if(array[i].getStress() >= serviceBoundry){
            array[i].printInformation();
        }
    }
}

// Főprogram
int main()
{
    char quit = 'n'; // 'y' || 'n'

    //Maximum jármű darabszám betöltése a settings fájlból
    ifstream readFile("settings");
    string data;
    int number = 0;
    while(getline(readFile, data)){
        number = stoi(data);
    }
    readFile.close();


    // Gondoskodni kéne arról, hogy ne lehessenek ugyan olyan rendszámok
    WorkMachine wmList[number];
    int wmIndex = 0;
    Truck truckList[number];
    int truckIndex = 0;
    Bus busList[number];
    int busIndex = 0;

    int serviceBoundary[3] = {999,999,999};

    string vehicleTypes[] = {"Munkagép", "Teherautó", "Autóbusz"};


    // Menu ciklusa
    while(quit != 'y' && quit != 'Y'){
        clear();
        cout << "Gépnyilvántartó program\n" << endl;

        string mainMenu[7] = {"Jármű hozzáadása", "Járművek adatainak megtekintése", "Rendszám alapján azonosítás", "Igénybevétel összesítése", "Szervízhatár beállítása" , "Szervíz köteles járművek","Kilépés"};
        int answer = drawMenu(mainMenu, 7);

        if(answer == 0){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik járműtípushoz akarsz hozzáadni?\n\n";
            int result = drawMenu(vehicleTypes,3);
            if(result == 0){
                first(wmList, wmIndex, number);
                if(wmIndex < number){
                    wmIndex += 1;
                }

            }
            else if(result == 1){
                first(truckList, truckIndex, number);
                if(truckIndex < number){
                    truckIndex += 1;
                }

            }
            else if(result == 2){
                first(busList, busIndex, number);
                if(busIndex < number){
                    busIndex += 1;
                }

            }
        }
        else if(answer == 1){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;

            cout << "  Melyik járműtípus csoportosítását kívánja megtekinteni?\n\n";
            int result = drawMenu(vehicleTypes,3);

            if(result == 0){
                second(wmList, wmIndex);
            }
            else if(result == 1){
                second(truckList, truckIndex);
            }
            else if(result == 2){
                second(busList, busIndex);
            }

        }
        else if(answer == 2){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;

            cout << "  Melyik járműtípusban kíván keresni rendszám alapján?\n\n";
            int result = drawMenu(vehicleTypes,3);
            if(result == 0){
                third(wmList, wmIndex);
            }
            else if(result == 1){
                third(truckList, truckIndex);
            }
            else if(result == 2){
                third(busList, busIndex);
            }
        }
        else if(answer == 3){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja összesíteni az adatokat?\n\n";
            int result = drawMenu(vehicleTypes,3);
            if(result == 0){
                fourth(wmList, wmIndex);
            }
            else if(result == 1){
                fourth(truckList, truckIndex);
            }
            else if(result == 2){
                fourth(busList, busIndex);
            }


        }
        else if(answer == 4){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja beállítani a szervízhatárt?\n\n";
            int result = drawMenu(vehicleTypes,3);
            if(result == 0){
                serviceBoundary[result] = fifth(wmList, wmIndex);
            }
            else if(result == 1){
                serviceBoundary[result] = fifth(truckList, truckIndex);
            }
            else if(result == 2){
                serviceBoundary[result] = fifth(busList, busIndex);
            }

        }
        else if(answer == 5){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja megtekinteni a szervízköteles járműveket?\n\n";
            int result = drawMenu(vehicleTypes,3);
            if(result == 0){
                sixth(wmList, wmIndex, serviceBoundary[result]);
            }
            else if(result == 1){
                sixth(truckList, truckIndex, serviceBoundary[result]);
            }
            else if(result == 2){
                sixth(busList, busIndex, serviceBoundary[result]);
            }


        }

        else if(answer == -2){
            cout << "  >> Biztos benne hogy ki akar lépni? [y/n]: ";
            cin >> quit;
            if(quit == 'y' || quit == 'Y'){
                cout << "  >> Kilépés megerősítve! <<" << endl;
            }
            else{
                cout << "  >> Kilépés megszakítva! <<" << endl;
            }
        }
        else{
            cout << "  >> Sajnos nincs ilyen menüpont! <<";
        }

        cout << "\n  >> Kész! << ";

        cin.get();
        getchar();
    }
    return 0;
}
