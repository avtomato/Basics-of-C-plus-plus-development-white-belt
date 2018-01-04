#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int q;
    cin >> q;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus;
            cin >> stop_count;
            vector<string> v(stop_count);
            for (string& s : v) {
                cin >> s;
                vector<string> v2;
                v2.push_back(bus);
                if (stops.count(s)) {
                    stops[s].insert(end(stops[s]), begin(v2), end(v2));
                } else {
                    stops[s] = v2;
                }
            }
            buses[bus] = v;
        } else if (operation_code == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops[stop].size() == 0) {
                cout << "No stop" << endl;
                stops.erase(stop);
            } else {
                for (const auto& item : stops) {
                    if (item.first == stop) {
                        for (string w : item.second) {
                            cout << w << " ";
                        }
                        cout << endl;
                    }
                }
            }
        } else if (operation_code == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) > 0) {
                for (const auto& item : buses) {
                    if (item.first == bus) {
                        for (string w : item.second) {
                            cout << "Stop " << w << ": ";
                            for (const auto& item2 : stops) {
                                if (item2.first == w) {
                                    if (item2.second.size() == 1) {
                                        cout << "no interchange" << endl;
                                    } else {
                                        for (string w2 : item2.second) {
                                            if (w2 != bus) {
                                                cout << w2 << " ";
                                            }
                                        }
                                        cout << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (operation_code == "ALL_BUSES") {
            if (buses.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for (const auto& item : buses) {
                    cout << "Bus " << item.first << ": ";
                    for (string w : item.second) {
                        cout << w << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
