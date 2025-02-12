#include <iostream>
#include <array>

// #include <Helper.h>
#include "generated/include/connection.h"
#include "generated/include/User.h"
using ::std::string;
void printUserInfo(const User& user) {
    std::cout << "User Found!" << std::endl;
    std::cout << "ID: " << user.getId() << std::endl;
    std::cout << "Name: " << user.getName() << std::endl;
    std::cout << "Surname: " << user.getSurname() << std::endl;
    std::cout << "Username: " << user.getUsername() << std::endl;
    std::cout << "Created On: " << user.getDateCreate() << std::endl;

    // Display user type
    switch (user.getUserType()) {
        case UT::Decan: std::cout << "Role: Decan" << std::endl; break;
        case UT::Prodecan: std::cout << "Role: Prodecan" << std::endl; break;
        case UT::Secretar_sef: std::cout << "Role: Secretar Sef" << std::endl; break;
        case UT::Sef_Departament: std::cout << "Role: Sef Departament" << std::endl; break;
        case UT::Secretar: std::cout << "Role: Secretar" << std::endl; break;
        case UT::Student: std::cout << "Role: Student" << std::endl; break;
        case UT::Profesor: std::cout << "Role: Profesor" << std::endl; break;
        default: std::cout << "Role: Unknown" << std::endl; break;
    }
}
int main() {
    User user;
    int userId=1;
    if(user.loadUserFromDB(userId)){
        printUserInfo(user);
    }else{
        std::cerr<<"User not found." << std::endl;
    }
    return 0;
    // std::cout << "Hello, world!\n";
    // std::array<int, 100> v{};
    // int nr;
    // std::cout << "Introduceți nr: ";
    // /////////////////////////////////////////////////////////////////////////
    // /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    // /// dați exemple de date de intrare folosind fișierul tastatura.txt
    // /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    // /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    // /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    // /// pentru cât mai multe ramuri de execuție.
    // /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    // /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    // ///
    // /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    // /// pentru a simula date introduse de la tastatură.
    // /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    // ///
    // /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    // /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    // /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    // /// program care merg (și să le evitați pe cele care nu merg).
    // ///
    // /////////////////////////////////////////////////////////////////////////
    // std::cin >> nr;
    // /////////////////////////////////////////////////////////////////////////
    // for(int i = 0; i < nr; ++i) {
    //     std::cout << "v[" << i << "] = ";
    //     std::cin >> v[i];
    // }
    // std::cout << "\n\n";
    // std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    // for(int i = 0; i < nr; ++i) {
    //     std::cout << "- " << v[i] << "\n";
    // }
    // ///////////////////////////////////////////////////////////////////////////
    // /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    // /// alt fișier propriu cu ce alt nume doriți.
    // /// Exemplu:
    // /// std::ifstream fis("date.txt");
    // /// for(int i = 0; i < nr2; ++i)
    // ///     fis >> v2[i];
    // ///
    // ///////////////////////////////////////////////////////////////////////////
    // ///                Exemplu de utilizare cod generat                     ///
    // ///////////////////////////////////////////////////////////////////////////
    // Helper helper;
    // helper.help();
    // ///////////////////////////////////////////////////////////////////////////
    // return 0;
}
