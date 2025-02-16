// // #include <iostream>
// // #include <array>

// // // #include <Helper.h>
// // #include "generated/include/connection.h"
// // #include "generated/include/User.h"
// // #include "generated/include/docType.h"
// // #include "generated/include/Document.h"
// // #include <fstream>
// // #include "generated/include/PDFWriter.hpp"
// // #include "generated/include/Student.h"
// // #include "generated/include/Secretar.h"
// // #include "generated/include/SecretarSef.h"
// // #include "generated/include/Prodecan.h"
// // #include "generated/include/SefDepartament.h"
// // #include "generated/include/Decan.h"
// // #include "generated/include/Document.h"
// // #include "generated/include/docType.h"
// // #include <memory>
// // using ::std::string;
// // void printUserInfo(const User& user) {
// //     std::cout << "User Found!" << std::endl;
// //     std::cout << "ID: " << user.getId() << std::endl;
// //     std::cout << "Name: " << user.getName() << std::endl;
// //     std::cout << "Surname: " << user.getSurname() << std::endl;
// //     std::cout << "Username: " << user.getUsername() << std::endl;
// //     std::cout << "Created On: " << user.getDateCreate() << std::endl;

// //     // Display user type
// //     switch (user.getUserType()) {
// //         case UT::Decan: std::cout << "Role: Decan" << std::endl; break;
// //         case UT::Prodecan: std::cout << "Role: Prodecan" << std::endl; break;
// //         case UT::Secretar_sef: std::cout << "Role: Secretar Sef" << std::endl; break;
// //         case UT::Sef_Departament: std::cout << "Role: Sef Departament" << std::endl; break;
// //         case UT::Secretar: std::cout << "Role: Secretar" << std::endl; break;
// //         case UT::Student: std::cout << "Role: Student" << std::endl; break;
// //         case UT::Profesor: std::cout << "Role: Profesor" << std::endl; break;
// //         default: std::cout << "Role: Unknown" << std::endl; break;
// //     }
// // }
// // #include <map>
// // int main() {
// //     // User user;
// //     // int userId=1;
// //     // if(user.loadUserFromDB(userId)){
// //     //     printUserInfo(user);
// //     // }else{
// //     //     std::cerr<<"User not found." << std::endl;
// //     // }
// //     // std::map<string, string> fields;
// //     // docType d;
// //     // d.loadDocTypeFromDB(1);
// //     // // Correctly call the method and iterate over the map
// //     // fields = d.getFields();
// //     // for (const auto& [key, value] : fields) {
// //     //     std::cout << key << ": " << value << "\n";
// //     // }
// //     // Document doc(new User(3), d);
// //     // std::map<string,string> fields2 = doc.fillDataForDocType();
// //     // for (const auto& [key, value] : fields2) {
// //     //     std::cout << key << ": " << value << "\n";
// //     // }
// //     // std::ifstream model(d.getPath());
// //     // std::string document((std::istreambuf_iterator<char>(model)), std::istreambuf_iterator<char>());
// //     // std::cout<<(doc.insertValues(document,fields2)) << std::endl;

// //     // std::string err;
// //     // pdfwrite::PDFWriter pdf;
// //     // pdf.setWidthHeight(1000, 1000);
// //     // pdf.pdfSetFont(pdfwrite::COURIER, 18);

// //     // std::string s = doc.insertValues(document,fields2);

// //     // pdf.pdfSetContent(s);
// //     // pdf.warpText(700, true);
// //     // pdf.setXY(100, 800);
// //     // pdf.pdfAddToPage();
// //     // if (!pdf.writeToFile("exempleDocumente/CerereEchivalare.pdf", err))
// //     // {
// //     //     std::cout << err;
// //     // }
// //     auto student = std::make_shared<Student>(6);           // Student ID: 6
// //     auto secretar = std::make_shared<Secretar>(5);         // Secretar ID: 5
// //     auto secretar_sef = std::make_shared<SecretarSef>(3);  // Secretar Sef ID: 3
// //     auto prodecan = std::make_shared<Prodecan>(2);         // Prodecan ID: 2
// //     auto sef_departament = std::make_shared<SefDepartament>(4); // Sef Departament ID: 4
// //     auto decan = std::make_shared<Decan>(1);  

// //     // Link the nodes
// //     student->setNext(secretar);
// //     secretar->setNext(secretar_sef);
// //     secretar_sef->setNext(prodecan);
// //     prodecan->setNext(sef_departament);
// //     sef_departament->setNext(decan);

// //     // Create document and start the process
// //     docType dt;
// //     dt.setPath("cereriTip/cerereTip.txt");
// //     Document doc(student.get(), dt);

// //     student->produce(doc);

// //     // Run the consumer threads
// //     student->run();
// //     secretar->run();
// //     secretar_sef->run();
// //     prodecan->run();
// //     sef_departament->run();
// //     decan->run();

// //     std::this_thread::sleep_for(std::chrono::seconds(5));
// //     return 0;
// //     // std::cout << "Hello, world!\n";
// //     // std::array<int, 100> v{};
// //     // int nr;
// //     // std::cout << "Introduceți nr: ";
// //     // /////////////////////////////////////////////////////////////////////////
// //     // /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
// //     // /// dați exemple de date de intrare folosind fișierul tastatura.txt
// //     // /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
// //     // /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
// //     // /// De asemenea, trebuie să adăugați în acest fișier date de intrare
// //     // /// pentru cât mai multe ramuri de execuție.
// //     // /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
// //     // /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
// //     // ///
// //     // /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
// //     // /// pentru a simula date introduse de la tastatură.
// //     // /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
// //     // ///
// //     // /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
// //     // /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
// //     // /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
// //     // /// program care merg (și să le evitați pe cele care nu merg).
// //     // ///
// //     // /////////////////////////////////////////////////////////////////////////
// //     // std::cin >> nr;
// //     // /////////////////////////////////////////////////////////////////////////
// //     // for(int i = 0; i < nr; ++i) {
// //     //     std::cout << "v[" << i << "] = ";
// //     //     std::cin >> v[i];
// //     // }
// //     // std::cout << "\n\n";
// //     // std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
// //     // for(int i = 0; i < nr; ++i) {
// //     //     std::cout << "- " << v[i] << "\n";
// //     // }
// //     // ///////////////////////////////////////////////////////////////////////////
// //     // /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
// //     // /// alt fișier propriu cu ce alt nume doriți.
// //     // /// Exemplu:
// //     // /// std::ifstream fis("date.txt");
// //     // /// for(int i = 0; i < nr2; ++i)
// //     // ///     fis >> v2[i];
// //     // ///
// //     // ///////////////////////////////////////////////////////////////////////////
// //     // ///                Exemplu de utilizare cod generat                     ///
// //     // ///////////////////////////////////////////////////////////////////////////
// //     // Helper helper;
// //     // helper.help();
// //     // ///////////////////////////////////////////////////////////////////////////
// //     // return 0;
// // }

#include "generated/include/connection.h"
#include "generated/include/User.h"
#include "generated/include/docType.h"
#include "generated/include/Document.h"
#include <fstream>
#include "generated/include/PDFWriter.hpp"
#include "generated/include/Student.h"
#include "generated/include/Secretar.h"
#include "generated/include/SecretarSef.h"
#include "generated/include/Prodecan.h"
#include "generated/include/SefDepartament.h"
#include "generated/include/Decan.h"
#include "generated/include/Document.h"
#include "generated/include/docType.h"
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
int main() {
    std::vector<std::pair<std::string, std::string>> fields;
    docType d;
    d.loadDocTypeFromDB(1);
    // Correctly call the method and iterate over the map
    fields = d.getFields();
    for (const auto& [key, value] : fields) {
        std::cout << key << ": " << value << "\n";
    }
    Document doc(new Student(18), d);
    std::vector<std::pair<std::string, std::string>> fields2 = doc.fillDataForDocType();
    for (const auto& [key, value] : fields2) {
        std::cout << key << ": " << value << "\n";
    }
    std::ifstream model(d.getPath());
    std::string document((std::istreambuf_iterator<char>(model)), std::istreambuf_iterator<char>());
    std::cout<<(doc.insertValues(document,fields2)) << std::endl;

    std::string err;
    pdfwrite::PDFWriter pdf;
    pdf.pdfAddNewPage();
    pdf.setWidthHeight(1000, 1000);
    pdf.pdfSetFont(pdfwrite::TIMES, 18);

    std::string s = doc.insertValues(document,fields2);
    pdf.pdfSetContent(s);
    pdf.warpText(700, true);
    pdf.setXY(100, 800);
    pdf.pdfAddToPage();
    // Create users with correct IDs
    auto student = std::make_shared<Student>(18);
    auto secretar = std::make_shared<Secretar>(13);
    auto secretar_sef = std::make_shared<SecretarSef>(7);
    auto prodecan = std::make_shared<Prodecan>(2);
    auto sef_departament = std::make_shared<SefDepartament>(8);
    auto decan = std::make_shared<Decan>(1);
    // Link pipeline
    student->setNext(secretar);
    secretar->setNext(secretar_sef);
    secretar_sef->setNext(prodecan);
    prodecan->setNext(sef_departament);
    sef_departament->setNext(decan);

    // Create and start document
    std::cout << "Document created: " << doc.getName() << "\n";

    student->produce(doc);
    // student->run();
    // secretar->run();
    // secretar_sef->run();
    // prodecan->run();
    // sef_departament->run();
    // decan->run();
    //Run processing
    std::string status;
    std::thread studentThread([&]() {
        student->run();
        doc.setStatus(getCurrentTimestamp() + ": Document created by Student");
        status+=doc.getStatus()+"\n";
    });
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread secretarThread([&]() {
        secretar->run();
        doc.setStatus(getCurrentTimestamp() + ": Document processed by Secretar");
        status+=doc.getStatus()+"\n";
    });
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread secretarSefThread([&]() {
        secretar_sef->run();
        doc.setStatus(getCurrentTimestamp() + ": Document processed by Secretar Sef");
        status+=doc.getStatus()+"\n";
    });
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread prodecanThread([&]() {
        prodecan->run();
        doc.setStatus(getCurrentTimestamp() + ": Document processed by Prodecan");
        status+=doc.getStatus()+"\n";
    });
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread sefDepartamentThread([&]() {
        sef_departament->run();
        doc.setStatus(getCurrentTimestamp() + ": Document processed by Sef Departament");
        status+=doc.getStatus()+"\n";
    });
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread decanThread([&]() {
        decan->run();
        doc.setStatus(getCurrentTimestamp() + ": Document processed by Decan");
        status+=doc.getStatus()+"\n";
    });
    studentThread.join();
    secretarThread.join();
    secretarSefThread.join();
    prodecanThread.join();
    sefDepartamentThread.join();
    decanThread.join();
    // Allow threads to work
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Pipeline completed.\n";
    std::cout << status+"\n";
    pdf.pdfAddNewPage();
    pdf.setWidthHeight(1000, 1000);
    pdf.pdfSetFont(pdfwrite::COURIER, 18);
    pdf.pdfSetContent(status);
    pdf.warpText(700, false);
    pdf.setXY(100, 800);
    pdf.pdfAddToPage();
    if (!pdf.writeToFile("example.pdf", err))
    {
        std::cout << err;
    }
    exit(0);
}