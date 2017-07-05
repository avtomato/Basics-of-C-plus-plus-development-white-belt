#include <exception>
#include <string>

using namespace std;

class TimeServer {
public:
    string GetCurrentTime() {
        // поместим вызов функции AskTimeServer в try-catch блок
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error&) {  // ловим только system_error
        }
        // возвращаем значение поля — либо обновлённое, либо нет
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};
