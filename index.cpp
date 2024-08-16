#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

// Une fonction qui extracter le nom
string extractName(const string &data) {
    size_t startPos = data.find("name=") + 5;
    size_t endPos = data.find('&', startPos);
    return data.substr(startPos, endPos - startPos); 
}

// Une fonction qui extracter le mot de passe
string extractPassword(const string &data) {
    size_t startPos = data.find("password=") + 9; 
    return data.substr(startPos); 
}

// Une fonction qui vérifie si le nom et le mot de passe sont proportionnel avec ce qui est écrit dans data.txt
bool checkInfo(const string &name, const string &password) {
    ifstream fs("./data.txt");
    string line;

    if (fs.fail()) {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return false;
    }

    while (getline(fs, line)) {
        if (line == name + ":" + password) {
            return true;
        }
    }

    return false;
}

int main() {
    string name, password, data;
    long len;
    char *lenstr;
    bool info;

    lenstr = getenv("CONTENT_LENGTH");

    if (lenstr != nullptr) {
        len = strtol(lenstr, nullptr, 10);
        data.resize(len);
        cin.read(&data[0], len); // Lecture des données depuis stdin

        name = extractName(data);
        password = extractPassword(data);
        info = checkInfo(name, password);

        cout << "Content-Type: text/html; charset=utf-8\r\n\r\n";
        cout << "<html>\n";
        cout << "<head><title>Résultats</title></head>\n";
        cout << "<body>\n";


        if(info){
            cout << "Login succesfully" << "<br>\n";
        }
        else{
            cout << "<form id=\"redirectForm\" action=\"index.html\" method=\"post\">" << endl;
            cout << "<input type=\"hidden\" name=\"message\" value=\"Wrong login or password\">" << endl;
            cout << "</form>" << endl;
            cout << "<script>document.getElementById('redirectForm').submit();</script>" << endl;
            cout << "Error! Please check your name or your password" << "<br>\n";
        }
        cout << "</body>\n";
        cout << "</html>\n";
    } else {
        cerr << "Erreur : CONTENT_LENGTH n'est pas défini." << endl;
    }

    return 0;
}
