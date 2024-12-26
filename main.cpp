#include "graph.h"

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah Kota" << endl;
    cout << "2. Tambah Jalan Antar Kota" << endl;
    cout << "3. Tampilkan Graf Kota" << endl;
    cout << "4. Cari Jalur Terpendek" << endl;
    cout << "5. Cari Jalur Alternatif" << endl;
    cout << "6. Tampilkan Kota yang sering dilewati" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukkan pilihan: ";
}

int main() {
    graph G;
    initGraph(G);
    
    addVertex(G, "Mondstat");
    addVertex(G, "Liyue");
    addVertex(G, "Inazuma");
    addVertex(G, "Sumeru");
    addVertex(G, "Fontaine");
    addVertex(G, "Natlan");
    addVertex(G, "Dragonspine");
    addVertex(G, "Qiaoying Village");
    addVertex(G, "Chasm");
    addVertex(G, "Enkanomiya");
    addVertex(G, "Snezhnaya");

    addEdge(G, "Mondstat", "Dragonspine", 800);
    addEdge(G, "Mondstat", "Snezhnaya", 4000);
    addEdge(G, "Dragonspine", "Liyue", 1000);
    addEdge(G, "Liyue", "Chasm", 1400);
    addEdge(G, "Liyue", "Inazuma", 3000);
    addEdge(G, "Liyue", "Qiaoying Village", 2500);
    addEdge(G, "Chasm", "Sumeru", 800);
    addEdge(G, "Sumeru", "Natlan", 1000);
    addEdge(G, "Sumeru", "Fontaine", 2700);
    addEdge(G, "Natlan", "Snezhnaya", 6000);
    addEdge(G, "Fontaine", "Qiaoying Village", 800);
    addEdge(G, "Fontaine", "Snezhnaya", 1500);
    addEdge(G, "Snezhnaya", "Fontaine", 1500);
    addEdge(G, "Snezhnaya", "Qiaoying Village", 2500);
    addEdge(G, "Enkanomiya", "Inazuma", 400);

    int choice;
    string startVertexID, endVertexID, blockedVertex;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string newVertexID;
                cout << "Masukkan nama kota: ";
                getline(cin, newVertexID);
                addVertex(G, newVertexID);
                cout << "Kota " << newVertexID << " telah ditambahkan." << endl;
                break;
            }
            case 2: {
                string startVertexID, endVertexID;
                int weight;
                cout << "Masukkan nama kota asal: ";
                getline(cin, startVertexID);
                cout << "Masukkan nama kota tujuan: ";
                getline(cin, endVertexID);
                cout << "Masukkan jarak antar kota (km): ";
                cin >> weight;
                addEdge(G, startVertexID, endVertexID, weight);
                cout << "Jalan antar " << startVertexID << " dan " << endVertexID << " telah ditambahkan." << endl;
                break;
            }
            case 3: {
                printGraph(G);
                break;
            }
            case 4: {
                cout << "Masukkan kota asal: ";
                getline(cin, startVertexID);
                cout << "Masukkan kota tujuan: ";
                getline(cin, endVertexID);
                findShortestPath(G, startVertexID, endVertexID);
                break;
            }
            case 5: {
                cout << "Masukkan kota asal: ";
                getline(cin, startVertexID);
                cout << "Masukkan kota tujuan: ";
                getline(cin, endVertexID);
                cout << "Masukkan nama kota yang akan diblokir: ";
                getline(cin, blockedVertex);
                findAlternativePath(G, startVertexID, endVertexID, blockedVertex);
                break;
            }
            case 6: {
                mostVisitedCity(G);
                break;
            }
            case 7: {
                cout << "Terima kasih! Sampai jumpa!" << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }
    return 0;
}
