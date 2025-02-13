#include "../include/User.h"
#include "../include/connection.h"

bool User::loadUserFromDB(int userId) {
    Connection db;
    try {
        // Replace with your MySQL credentials
        std::string host = "192.168.0.116";
        std::string user = "root";
        std::string password = "proiectqwerty";
        std::string database = "proiectdb";
        int port = 3399;

        if (!db.connect(host, user, password, database, port)) {
            throw std::runtime_error("Database connection failed.");
        }

        std::string query = "SELECT cod_utilizator, nume, prenume, nume_autentificare, parola, data_creare, cod_functie FROM Utilizator WHERE cod_utilizator = " + std::to_string(userId);
        std::cout << "aici imi da eroarea"<<std::endl;
        db.executeQuery(query);

        // ✅ Check if `res` is valid
        MYSQL_RES* res = db.getResult();
        if (!res) {
            std::cerr << "Error: No results returned from the query." << std::endl;
            return false;
        }

        // ✅ Fetch row safely
        MYSQL_ROW row = mysql_fetch_row(res);
        if (!row) {
            std::cerr << "User not found in the database." << std::endl;
            mysql_free_result(res);
            return false;
        }

        // ✅ Assign values safely
        id = row[0] ? std::stoi(row[0]) : -1;
        name = row[1] ? row[1] : "";
        surname = row[2] ? row[2] : "";
        username = row[3] ? row[3] : "";
        passwd = row[4] ? row[4] : "";

        // ✅ Handle DATETIME conversion safely
        std::string dateString = row[5] ? row[5] : "";
        if (!dateString.empty()) {
            std::tm tm = {};
            std::istringstream ss(dateString);
            ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
            date_create = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        }

        // ✅ Handle user type conversion safely
        int userTypeInt = row[6] ? std::stoi(row[6]) : -1;
        switch (userTypeInt) {
            case 1: userType = UT::Decan; break;
            case 2: userType = UT::Prodecan; break;
            case 3: userType = UT::Secretar_sef; break;
            case 4: userType = UT::Sef_Departament; break;
            case 5: userType = UT::Secretar; break;
            case 6: userType = UT::Student; break;
            case 7: userType = UT::Profesor; break;
            default: userType = UT::UNKNOWN; break;
        }

        mysql_free_result(res);
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}


// ✅ Convert `std::chrono::system_clock::time_point` back to a readable string
std::string User::getDateCreate() const {
    std::time_t tt = std::chrono::system_clock::to_time_t(date_create);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&tt), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
