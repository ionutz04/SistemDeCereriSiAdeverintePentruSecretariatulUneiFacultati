# SISTEM PENTRU SOLICITAREA, GENERAREA ȘI ELIBERAREA CERERILOR ȘI ADEVERINȚELOR PENTRU SECRETARIATUL UNEI FACULTĂȚI

Ionescu Ionut

## Descriere proiect

Modelul conceptual pe care îl propun în aceasta aplicație reflectă o
soluție din lumea reală, concepută pentru digitalizarea proceselor
administrative din cadrul unei facultăți, în special în ceea ce privește
gestionarea cererilor și adeverințelor solicitate de studenți. Acesta
abordează două nevoi principale ale actorilor implicați: facilitarea
accesului studenților la serviciile administrative și eficientizarea
activității secretariatului.

În mediul academic, studenții interacționează frecvent cu secretariatul
pentru diverse solicitări, precum eliberarea unor adeverințe sau
aprobarea unor cereri. În mod tradițional, aceste procese implică
prezența fizică la secretariat, depunerea documentelor în format fizic
și așteptarea unor timpi prelungiți pentru procesare. Această abordare
tradițională generează deseori întârzieri, supraîncărcarea personalului
administrativ și o experiență ineficientă pentru studenți.

Sistemul propus își propune să rezolve aceste probleme prin introducerea
unui model digital de gestionare a documentelor și a cererilor. Acesta
oferă următoarele beneficii din perspectiva utilizatorilor reali:

1\. Pentru studenți:

- Posibilitatea de a depune cereri și documente online, eliminând
  necesitatea deplasării fizice la secretariat.

- Acces la informații actualizate în timp real privind statusul
  cererilor lor.

- Reducerea timpilor de așteptare și a efortului suplimentar pentru
  obținerea documentelor necesare.

2\. Pentru profesori:

- Posibilitatea de a depune cereri și documente online, eliminând
  necesitatea deplasării fizice la secretariat.

- Acces la informații actualizate în timp real privind statusul
  cererilor lor.

- Reducerea timpilor de așteptare și a efortului suplimentar pentru
  obținerea documentelor necesare.

3\. Pentru secretariat:

- Un instrument centralizat pentru gestionarea cererilor și
  documentelor,

- reducând dependența de fluxurile de lucru manuale.

- Automatizarea proceselor și urmărirea precisă a etapelor de aprobare.

- O mai bună alocare a resurselor umane prin optimizarea sarcinilor
  administrative.

Modelul integrează componentele cheie întâlnite în procesele
administrative reale:

•Structura organizațională este reprezentată de entitățile Personal,
Atributie și Organigrama, care reflectă ierarhia și responsabilitățile
din cadrul acesteia.

•Tipuri de documente respectiv entitatea tipDocument detaliază categorii
specifice de documente, inclusiv traseul procedural (circuit) asociat
fiecăruia.

•Interacțiunea utilizatorilor cuprinde entitatea Utilizator reprezintă
studenții și personalul administrativ, evidențiind rolurile și
interacțiunile lor în cadrul sistemului.

•Fluxurile operaționale sunt reprezentate de entitățile document și
status ce oferă o abordare dinamică pentru urmărirea și gestionarea
cererilor, aliniate la etapele reale de procesare.

Sistemul face posibil pentru studenți să nu mai vină fizic la
secretariatul facultății lor pentru acest fel de solicitări și pot
urmări status-ul cererii lor în timp real. Secretariatul poate gestiona
mult mai eficient toate aceste documente și poate grăbi procesul de
aprobare a unei cereri sau de întocmire a unei adeverințe.

Modelul prezentat are la bază nevoile și provocările specifice unui
context academic real. Prin implementarea acestuia, se creează o soluție
digitalizată care nu doar că îmbunătățește experiența utilizatorilor, ci
contribuie și la modernizarea și eficientizarea proceselor
administrative ale facultății. Astfel, modelul servește drept exemplu de
integrare a tehnologiilor informaționale în administrația academică, cu
impact direct asupra performanței organizaționale.

## Prezentarea pipe-line-ului:

Această aplicație, simulează precis parcursul unei solicitări, plecând
de la sursă, student, spre destinație, reprezentată de comisiile
competente pentru fiecare tematică pe care o vizează solicitarea.

Pașii din acest scenariu sunt următorii:

1.  Utilizatorii ce ocupă funcțiile de studenți , aleg, în linia de
    comanda, folosindu-se de id-ul fiecărui tip de document, tipul de
    cerere și tematica pe care o vizează;

2.  Secretarul, care în mod implicit vizualizează și înregistrează
    actul, semnează primirea acestuia și transmite mai departe
    solicitarea către secretarul-șef;

3.  Secretarul-șef vizează actul și îl trimite mai departe către
    prodecanul responsabil, care, de asemenea, semnează și trimite mai
    departe solicitarea către comisia competenta;

4.  Comisia, după discuțiile aferente din ședința dedicată, transmite
    rezultatul decanului;

5.  Decanul vizează decizia Comisiei și trimite răspunsul pe cale
    inversă celei descrise anterior;

6.  La final, răspunsul este afișat, tot prin linia de comanda a
    modelului informatic.

## Prezentarea pe scurt a fiecărei entități

#### Înainte de prezentarea fiecare succinta a fiecarei entitati, vreau sa precizez ca în centrul acestei aplicații se afla 3 mari entitati ce formeaza un arbore binar:

\- Documentul: ce reprezintă pachetul ce este transmis de fiecare
entitate folosindu-se de pipe-line

\- Utilizatorul: ce creaza documentul și are drepturi de a modifica
statusul acestuia

\- Tipul de Document: ce reprezintă sablonul cu ajutorul caruia
utilizatorul a reușit sa construiască documentul.

Și acum, descrierea succinta a fiecarei entitati:

1\. Entitatea Utilizator (clasa User):

\- este o clasa abstracta ce obtine toate atributele folosindu-se de o
baza de date normalizata.

\- Subentitatile Userului sunt :

i\. Student (clasa Student), ce prin natura atrubutiilor sale asupra
documentelor, poate creea adauga elemte în pipeline, dar nu sa și
extraga.

ii\. Secretar(clasa Secretar), ce prin natura atributiilor sale asupra
documentelor, poate sa modifice elementele intruduse în pipeline de
către utilizator, și după să semneze faptul ca a exercitat modificari pe
acest element (Obs: exercitarea actiunilor asupra unui document se poate
efectua și doar prin trimiterea sa către un nod predecesor).

Iii. Secretarul șef (clasa SecretarSef), ce prin natura atributiiilor
sale asupra documentelor, verifica integritatea actiunilor exercitate de
secretar, și semnează verificarea.

Iv. Prodecanul(clasa Prodecan), are atributia de semnare/vizare a
primire documentelor, trimiterea lor către comisiile competente, cu
ajutorul pipeline-ului.

v\. Comisia(casa SefDepartament), are atributia de semnare a primiri
documentului, dar și decizia de aprobare sau neaprobare a documentului.

vi\. Nu în ultimul rând, Decanul(clasa Decan), are rolul de vizare a
procesului exercitat de document dar, dar și rol de decident, cel care
aproba decizia comisiei.(Exista cazul în care Decanul nu este de acord
cu decizia Comisie, insa acest caz trebuie, din câte am văzut în
proceduri, rezolvat printr-o instituire de comisie în care se va
reanaliza decizia precedata de comitetul competent).  
2. Entitatea PipeLineNode(clasa PipelineNode) are scopul de a simula cu
o precizie cat mai aproape de realitate de parcursul/scenariul explicat
mai sus.

3\. LinkedNodeList (clasa LinkedNode) are rolul de a structura acțiunile
nodurilor din pipeline sub forma unei liste simplu inlantuite. Aceasta
este o clasa template care ma ajuta la comtrolarea oricarei entitati
care poate fi introdusa în pipeline.

4.Tip de document(clasa docType) are scopul de a exercita o acțiune de
generalizare a procesului de „Completarea a unei cereri", folosindu-se
de baza de date normalizata.

Înainte de prezentarea succintă a fiecărei entități, vreau să precizez
că în centrul acestei aplicații se află trei mari entități ce formează
un arbore binar:

- **Documentul** -- reprezintă pachetul transmis de fiecare entitate
  folosindu-se de pipeline.

- **Utilizatorul** -- creează documentul și are dreptul de a modifica
  statutul acestuia.

- **Tipul de document** -- reprezintă șablonul cu ajutorul căruia
  utilizatorul a reușit să construiască documentul.

**Descrierea succintă a fiecărei entități:**

**1. Entitatea Utilizator (clasa User):**

- Este o clasă abstractă ce obține toate atributele folosindu-se de o
  bază de date normalizată.

- Subentitățile utilizatorului sunt:

i\. **Student** (clasa Student) -- prin natura atribuțiilor sale asupra
documentelor, poate adăuga elemente în pipeline, dar nu le poate
extrage.

ii\. **Secretar** (clasa Secretar) -- prin natura atribuțiilor sale
asupra documentelor, poate modifica elementele introduse în pipeline de
către utilizator și, ulterior, poate semna pentru a certifica faptul că
a efectuat modificări asupra acestora.

*Observație:* Exercitarea acțiunilor asupra unui document se poate
realiza și prin trimiterea acestuia către un nod predecesor.

iii\. **Secretarul-șef** (clasa SecretarSef) -- verifică integritatea
acțiunilor exercitate de secretar și semnează verificarea acestora.

iv\. **Prodecanul** (clasa Prodecan) -- are atribuția de a semna și de a
viza primirea documentelor, precum și de a le trimite către comisiile
competente, folosindu-se de pipeline.

v\. **Comisia** (clasa SefDepartament) -- are atribuția de a semna
primirea documentului și de a lua o decizie privind aprobarea sau
respingerea acestuia.

vi\. **Decanul** (clasa Decan) -- are rolul de a viza procesul exercitat
asupra documentului, dar și de a lua decizia finală privind aprobarea
documentului.

*Observație:* În cazul în care decanul nu este de acord cu decizia
comisiei, procedura prevede instituirea unei comisii suplimentare care
va reanaliza decizia luată anterior de comitetul competent.

**2. Entitatea PipelineNode (clasa PipelineNode):**

Are scopul de a simula, cu o precizie cât mai apropiată de realitate,
scenariul explicat mai sus.

**3. Entitatea LinkedNodeList (clasa LinkedNode):**

Are rolul de a structura acțiunile nodurilor din pipeline sub forma unei
liste simplu înlănțuite. Aceasta este o clasă template care ajută la
controlarea oricărei entități ce poate fi introdusă în pipeline.

**4. Entitatea Tip de document (clasa docType):**

Are scopul de a generaliza procesul de „completare a unei cereri",
folosindu-se de baza de date normalizată.

**5. Documentul (clasa Document)** reunește toate entitățile de mai sus,
reprezentând pachetul ce este "plimbat" de Producer la Consumer, pentru
că acest scenariu pune în evidență această problemă fundamentală a
paradigmei MultiThreading.

## Explicarea scenariilor informatice:

1\. Scenariul de conectare la baza de date:

Acest scenariu include partea de conectare folosindu-se de biblioteca
«mysql.h» instalata pe sistemul de operare Ubuntu 24LTS cu ajutorul
pachetului „libmysqlclient-dev" instalat prin managerul de packete
„apt"(Advanced Packaging Tool).

După instalare, nu a fost nevoie de compilarea externa a acestuia, însă
a fost nevoie să fie introdus în directorul «include» din path-ul
„/usr/lib/x86_64-linux-gnu/libmysqlclient.so".

Pentru implementare, am ales o abordare structurată, pentru a evita
deschiderea multiplă a conexiunilor.

Definiție :
```
#include "../include/connection.h"
#include <iostream>
#include <string>
#include <stdexcept>
using ::std::cin;
using ::std::cout;
using ::std::string;
Connection::Connection(){
    conn = mysql_init(nullptr);
    if(!conn){
        throw std::runtime_error("Mysql Initialization Failed!");
    }
}

bool Connection::connect(const string &host, const string &user, const string &passwd, const string &database, const int port){
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), port, NULL, 0);
    if(!conn){
        throw std::runtime_error(std::string("Connection Faild: ") + mysql_error(conn));
    }
    cout << "Connected to MySQL successfuly!" << std::endl;
    return true;
}
MYSQL_RES* Connection::getResult(){
    if(!res){
        throw std::runtime_error("No result available. Did you execute the querry?");
    }
    return res;
}
void Connection::executeQuery(const std::string &query) {
    if (!conn) {
        throw std::runtime_error("executeQuery() failed: MySQL connection is not initialized.");
    }

    std::cout << "Executing query: " << query << std::endl;

    if (mysql_query(conn, query.c_str())) {
        throw std::runtime_error(std::string("Query execution failed: ") + mysql_error(conn));
    }

    res = mysql_store_result(conn);
    if (!res && mysql_errno(conn)) {
        throw std::runtime_error(std::string("mysql_store_result() failed: ") + mysql_error(conn));
    }
}


void Connection::close(){
    if(conn){
        mysql_close(conn);
        conn = nullptr;
        cout << "MySQL connection closed!" << std::endl;
    }
}

```
Pentru conectare, am avut nevoie de 3 variabile de tip MYSQL: **conn**
în care se afla adresa de memorie la care a fost salvata conexiunea**,
res**, ce retine rezultatul dat de un anumit interogare(query), și row,
ce retine liniile afisate de res.  
Implementarea fiecăreia se poate găsi în fișierul
„/generated/src/connection.cpp"

2\. Scenariul de extragere a datelor importante din baza de date:

Extragerea datelor din baza de date a fost facila pentru entitățile User
și docType, ce nu puteau lipsi în crearea mecanismului de generare a
documentelor.

Definiții:  
1. User:
```
#ifndef OOP_USER_H
#define OOP_USER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

using ::std::string;

// Enum for user roles
enum class UT {
    Decan,
    Prodecan,
    Secretar_sef,
    Sef_Departament,
    Secretar,
    Student,
    Profesor,
    UNKNOWN
};

class User {
protected:
    int id;
    string name, surname, username, passwd;
    std::chrono::system_clock::time_point date_create;  //  Store DATETIME as `time_point`
    UT userType;

public:
    User(int userId) : id(userId), userType(UT::UNKNOWN){}
    virtual ~User() = default;

    virtual bool loadUserFromDB(int id) = 0;

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getUsername() const { return username; }
    string getDateCreate() const;
    UT getUserType() const { return userType; }
};

#endif // OOP_USER_H

```
height="6.562599518810149in"}- este o clasa abstracta ce obtine toate
atributele folosindu-se de o baza de date normalizata.

\- Subentitățile Userului sunt:

i\. Student (clasa Student), ce prin natura atribuțiilor sale asupra
documentelor, poate crea, adăuga elemente în pipeline, dar nu să și
extragă.

ii\. Secretar(clasa Secretar), ce prin natura atribuțiilor sale asupra
documentelor, poate sa modifice elementele intruduse în pipeline de
către utilizator, și după să semneze faptul ca a exercitat modificări pe
acest element (Obs: exercitarea acțiunilor asupra unui document se poate
efectua și doar prin trimiterea sa către un nod predecesor).

iii\. Secretarul șef (clasa SecretarSef), ce prin natura atribuțiilor
sale asupra documentelor, verifica integritatea acțiunilor exercitate de
secretar, și semnează verificarea.

iv\. Prodecanul(clasa Prodecan), are atribuția de semnare/vizare a
primire documentelor, trimiterea lor către comisiile competente, cu
ajutorul pipeline-ului.

v\. Comisia(casa SefDepartament), are atribuția de semnare a primiri
documentului, dar și decizia de aprobare sau neaprobare a documentului.

vi\. Nu în ultimul rând, Decanul(clasa Decan), are rolul de vizare a
procesului exercitat de document dar, dar și rol de decident, cel care
aproba decizia comisiei.(Exista cazul în care Decanul nu este de acord
cu decizia Comisie, insa acest caz trebuie, din câte am văzut în
proceduri, rezolvat printr-o instituire de comisie în care se va
reanaliza decizia precedata de comitetul competent).

2\. docType:

![](media/image3.png){width="6.051999125109361in"
height="5.979099956255468in"}  
-aceasta clasa are scopul de a exercita o acțiune de generalizare a
procesului de „Completarea a unei cereri", folosindu-se de baza de date
normalizata.

În plus de asta, după generarea documentelor folosindu-se de aceste doua
componente importante, am integrat o creare de PDF-uri folosind doar
string-urile transmise ca parametru pentru fiecare document.
(PDFWriter.cpp)

3\. Scenariul de analiza și prelucrare a datelor:  
  
Pentru acest scenariu, voi explica întâi în ce consta problema
Producer-Consumer.

Aceasta problema are în centrul atenției doua entități mari și late:
Producer, cel ce generează „task-uri" sa zicem, și Consumer, cel ce
îndeplinește „task-urile" generate de Producer. Aceste taskuri sunt
bagate într-o coada ce suporta blocaje, sau mai bine spus, semafoare,
pentru a nu supraîncărca Consumerii cu taskurile provenite de la
Produceri. După aceasta acțiune, se stabilesc: numărul de consumeri și
produceri, și se rulează programul. Acțiunea poate fi infinita doar daca
coada nu se golește.

În acest proiect, problema Producer-Consumer este pusa de natura
înlănțuită. Adică, acțiunile unui nod, influențează natura nodului
următor din schema pipeline.  
În acest subcapitol o să arat doar un exemplu de implementare a unui nod
ce poate fi și producer și consumer, dar și un nod ce poate fi doar
producer sau doar consumer.  
1. Student:  
Studentul, prin natura sa din modelul informatic propus mai sus, accepta
doar producerea de documente, consumarea ei fiind doar o chestiune de
afisare status:  
```
\#ifndef STUDENT_H

\#define STUDENT_H

\#include \"User.h\"

\#include \"Document.h\"

\#include \"docType.h\"

\#include \<thread\>

\#include \<mutex\>

\#include \<queue\>

\#include \<condition_variable\>

\#include \<memory\>

\#include \"PipelineNode.h\"

class Student : public User, public PipelineNode{

public:

Student(int userId) : User(userId) {

userType = UT::Student;

}

bool loadUserFromDB(int userId) override {

if (!User::loadUserFromDB(userId)) return false;

if (userType != UT::Student) {

std::cerr \<\< \"Error: User is not a Student!\" \<\< std::endl;

return false;

}

return true;

}

void produce(Document& doc) override {

std::unique_lock\<std::mutex\> lock(mtx);

doc.setStatus(\"Created by Student\");

buffer.push(doc);

cv.notify_one();

}

void consume() override {

std::unique_lock\<std::mutex\> lock(mtx);

cv.wait(lock, \[this\] { return !buffer.empty(); });

Document doc = buffer.front();

buffer.pop();

std::cout \<\< \"Student processed document: \" \<\< doc.getName() \<\<
\" with status: \" \<\< doc.getStatus() \<\< std::endl;

if (nextNode) {

nextNode-\>produce(doc);

}

}

void run() override {

std::thread(\[this\] {

while (true) {

consume();

}

}).detach();

}

void setNext(std::shared_ptr\<PipelineNode\> next) override {

nextNode = next;

}

private:

std::queue\<Document\> buffer;

std::mutex mtx;

std::condition_variable cv;

std::shared_ptr\<PipelineNode\> nextNode;

};

\#endif // STUDENT_H
```
2\. Secretarul: secretarul, tot prin natura sa specificata in modelul
anterior, permite si producerea de actiuni asupra unui document, dar si
citirea/vizarea/semnarea unui document:  
```
\#ifndef STUDENT_H

\#define STUDENT_H

\#include \"User.h\"

\#include \"Document.h\"

\#include \"docType.h\"

\#include \<thread\>

\#include \<mutex\>

\#include \<queue\>

\#include \<condition_variable\>

\#include \<memory\>

\#include \"PipelineNode.h\"

class Student : public User, public PipelineNode{

public:

Student(int userId) : User(userId) {

userType = UT::Student;

}

bool loadUserFromDB(int userId) override {

if (!User::loadUserFromDB(userId)) return false;

if (userType != UT::Student) {

std::cerr \<\< \"Error: User is not a Student!\" \<\< std::endl;

return false;

}

return true;

}

void produce(Document& doc) override {

std::unique_lock\<std::mutex\> lock(mtx);

doc.setStatus(\"Created by Student\");

buffer.push(doc);

cv.notify_one();

}

void consume() override {

std::unique_lock\<std::mutex\> lock(mtx);

cv.wait(lock, \[this\] { return !buffer.empty(); });

Document doc = buffer.front();

buffer.pop();

std::cout \<\< \"Student processed document: \" \<\< doc.getName() \<\<
\" with status: \" \<\< doc.getStatus() \<\< std::endl;

if (nextNode) {

nextNode-\>produce(doc);

}

}

void run() override {

std::thread(\[this\] {

while (true) {

consume();

}

}).detach();

}

void setNext(std::shared_ptr\<PipelineNode\> next) override {

nextNode = next;

}

private:

std::queue\<Document\> buffer;

std::mutex mtx;

std::condition_variable cv;

std::shared_ptr\<PipelineNode\> nextNode;

};

\#endif // STUDENT_H  
```
3. Decanul- decanul este entitatea ce suporta, la nivel teoretic, doar
consumarea informațiilor date de către șeful de departament, însă, dar
si produce răspuns, care in cazul unei cereri de echivalare, este accept
sau deny:
```
\#ifndef DECAN_H

\#define DECAN_H

\#include \"User.h\"

\#include \"Document.h\"

\#include \"PipelineNode.h\"

\#include \<thread\>

\#include \<mutex\>

\#include \<queue\>

\#include \<condition_variable\>

\#include \<memory\>

\#include \<random\>

\#include \<iostream\>

class Decan : public User, public PipelineNode {

public:

Decan(int userId) : User(userId) {

userType = UT::Decan;

}

// Load user from DB

bool loadUserFromDB(int userId) override {

if (!User::loadUserFromDB(userId)) return false;

if (userType != UT::Decan) {

std::cerr \<\< \"Error: User is not a Decan!\" \<\< std::endl;

return false;

}

return true;

}

// Produce: Receives a document from the previous node

void produce(Document& doc) override {

std::unique_lock\<std::mutex\> lock(mtx);

buffer.push(doc);

cv.notify_one();

}

// Consume: Process the document and decide its fate

void consume() override {

std::unique_lock\<std::mutex\> lock(mtx);

cv.wait(lock, \[this\] { return !buffer.empty(); });

Document doc = buffer.front();

buffer.pop();

bool decision = makeDecision();

if (decision) {

doc.setStatus(\"Approved by Decan\");

notifyUser(doc, true);

if (nextNode) nextNode-\>produce(doc);

} else {

doc.setStatus(\"Denied by Decan\");

notifyUser(doc, false);

}

}

// Run the consumer thread

void run() override {

std::thread(\[this\] {

while (true) {

consume();

}

}).detach();

}

// Set the next node in the pipeline

void setNext(std::shared_ptr\<PipelineNode\> next) override {

nextNode = next;

}

private:

std::queue\<Document\> buffer;

std::mutex mtx;

std::condition_variable cv;

std::shared_ptr\<PipelineNode\> nextNode;

// Simulates a decision (approve/deny)

bool makeDecision() {

std::random_device rd;

std::mt19937 gen(rd());

std::uniform_int_distribution\<\> dist(0, 1);

return dist(gen) == 1;

}

// Notifies the user of the document\'s fate

void notifyUser(const Document& doc, bool approved) {

std::string status = approved ? \"approved\" : \"denied\";

std::cout \<\< \"Notification: Document \'\" \<\< doc.getName()

\<\< \"\' was \" \<\< status \<\< \" by Decan.\n\";

}

};

\#endif // DECAN_H
```
## Rularea și folosirea acestei aplicații

Aceasta aplicație necesita o atenție sporta din punct de vedere de
securitate (fiind vorba de o conexiune la nivelul unei baze de date). În
plus, pot fi aduse upgrade-uri la nivel logic asupra ciclului (denumit
în repetate rânduri „pipeline"), cat și asupra funcționalității fiecărui
nod din acesta.

Având în vedere argumentele de mai sus, este necesara implementarea unui
server ce susține o asemenea arhitectura. Pentru acest lucru propun
soluția Docker, care este o soluție open-source și foarte bine
documentata, cu ajutorul căreia se poate îmbunătăți performanta,
fiabilitatea și scalabilitatea proceselor birocratice.

De asemenea, daca tot vorbim de o soluție eficienta, optima și ieftină
din punct de vedere al prețului și consumului de resurse, se recomanda o
implementare pe sistemul AlpineLinux, a carei imagini este una foarta
mica din punct de vedere stocare, și foarte bine structurata, având la
baza libc și BusyBox. Singura precizare pe care o am pentru aceasta
metoda de compilare a aplicației ar fi aceea ca este necesar Dockerfile
pentru instalarea corecta a dependentelor.

## Bibliografie:

GeeksforGeeks. *\"Producer-Consumer Problem in C.\"* Accesat la
[URL](https://www.geeksforgeeks.org/producer-consumer-problem-in-c/).

CppReference. *\"std::shared_ptr - Smart Pointer.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/memory/shared_ptr).

Alpine Linux. *\"Index.\"* Accesat la [URL](https://alpinelinux.org/).

Docker Documentation. *\"Dockerfile Reference.\"* Accesat la
[URL](https://docs.docker.com/reference/dockerfile/).

MySQL Developers. *\"MySQL C API Downloads.\"* Accesat la
[URL](https://dev.mysql.com/downloads/c-api/).

Stack Overflow. *\"How to Use External Libraries and Headers in C
Makefile.\"* Accesat la
[URL](https://stackoverflow.com/questions/15045748/how-to-use-external-libraries-and-headers-in-c-makefile).

CppReference. *\"Enumerations in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/language/enum).

CppReference. *\"Bernoulli Distribution in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/numeric/random/bernoulli_distribution).

CppReference. *\"Mutex in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/thread/mutex).

CppReference. *\"Memory Header in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/header/memory).

CppReference. *\"Random Number Generation in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/numeric/random).

CppReference. *\"Threads in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/thread/thread).

CppReference. *\"Condition Variable in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/thread/condition_variable).

CppReference. *\"Multithreading in C++.\"* Accesat la
[URL](https://en.cppreference.com/w/cpp/language/multithread).
