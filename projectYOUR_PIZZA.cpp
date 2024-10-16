#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Pizza {
private:
    vector<string> pizzas = { "пепперони", "маргарита", "моцарелла", "гавайская", "4 сыра", "сырная", "ветчина и сыр", "чоризо фреш", "песто", "аррива", "пицца из морепродуктов", "диабло", "колбаски барбекю", "мясной микс", "неаполитанская" };
    vector<double> ve = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

public:
    string question_1_1_1() { // вопрос
        map<string, string> products{ {"a", "100000000001000"}, {"b", "000000010100100"}, {"c", "000000000000100"} }; // 100000000001000 - в случае 1 - (+ 1/8) иначе пропустить
        cout << "Какая ваша любимая колбаса?\n";
        cout << "a пепперони\n";
        cout << "b чоризо\n";
        cout << "c нравятся все\n";
        return answer(products); // вызов принятия ответа
    }

    string question_1_1() {
        map<string, string> products{ {"a", "000100100000010"}, {"b", "000000000100000"} };
        cout << "Какая ваша любимая мясная начинка?\n";
        cout << "a мясо\n";
        cout << "b морепродукты\n";
        cout << "c колбаса\n";
        cout << "Ответ: ";
        string n;
        cin >> n;
        cout << "\n";
        auto it = products.find(n);
        if (n == "c") {
            return question_1_1_1(); // вызов выбора колбасок
        }
        else if (it != products.end()) {
            cout << it->second;
            return it->second;
        }
        else {
            return "000000000000000"; // Возвращаем пустой ответ в случае некорректного ввода
        }
    }

    string question_1() {
        map<string, string> products{ {"a", "011011001000001"} };
        cout << "К кому вы себя относите?\n";
        cout << "a Веган\n";
        cout << "b Мясоед\n";
        cout << "Ответ: ";
        string n;
        cin >> n;
        cout << "\n";
        auto it = products.find(n);
        if (it != products.end()) {
            cout << it->second;
            return it->second;
        }
        else if (n == "b") {
            return question_1_1(); 
        }
        else {
            return "000000000000000";
        }
    }
    string question_2() {
        map<string, string> products{ {"a", "000010001000000"}, {"b", "000000000001100"}, {"c", "000000000100000"}, {"e", "111101110000011"} };
        cout << "Какой соус вы предпочитаете на пицце?\n";
        cout << "a сливочный\n";
        cout << "b BBQ\n";
        cout << "c ранчо\n";
        cout << "d песто\n";
        cout << "e -\n";
        return answer(products);
    }
    string question_3() {
        map<string, string> products{ {"a", "000000000001000"}, {"b", "100000010100100"}, {"c", "011111101000011"} };
        cout << "Какой уровень остроты вы любите пиццы?\n";
        cout << "a высокий\n";
        cout << "b средний\n";
        cout << "c вообще острое не люблю острое\n";
        return answer(products);
    }
    string question_4() {
        map<string, string> products{ {"a", "000000100000000"}, {"b", "00000000001000"}, {"c", "000100000000000"}, {"d", "111011011100111"} };
        cout << "Какие добавки вы предпочитаете на пицце?\n";
        cout << "a грибы\n";
        cout << "b оливки\n";
        cout << "с ананасы\n";
        cout << "d -\n";
        return answer(products);
    }
    string question_5() {
        map<string, string> products{ {"a", "11110111111111"}, {"b", "00001000000000"} };
        cout << "Предпочитаете сколько видов сыра в пицце?\n";
        cout << "a классика - 2\n";
        cout << "b побольше - 4\n";
        return answer(products);
    }
    string question_6() {
        map<string, string> products{ {"a", "011100101000001"}, {"b", "110010011001101"}, {"c", "000000000100000"}, {"d", "000001000010000"} };
        cout << "Какие травы вы предпочитаете на своей пицце?\n";
        cout << "a базилик\n";
        cout << "b орегано\n";
        cout << "c руккола\n";
        cout << "d -\n";
        return answer(products);
    }

    string question_7() {
        map<string, string> products{ {"a", "111001001000001"}, {"b", "000110110111110"} };
        cout << "Вам нравится простая пицца?\n";
        cout << "a да\n";
        cout << "b нет\n";
        return answer(products);
    }
    string question_8() {
        map<string, string> products{ {"a", "010000000100001"}, {"b", "100000010001000"}, {"c", "00000000000010"}, {"d", "000000001000000"}, {"e", "001111100000110"} };
        cout << " Какой ваш самый любимый овощ?\n";
        cout << "a помидоры\n";
        cout << "b перец\n";
        cout << "c лук блю\n";
        cout << "d шпинат\n";
        cout << "e -\n";
        return answer(products);
    }

    string answer(map<string, string>  products) { // записывание ответов
        cout << "Ответ: ";
        string n;
        cin >> n;
        cout << "\n";
        auto it = products.find(n);
        if (it != products.end()) {
            return it->second;
        }
        else
        {
            return "000000000000000";
        }
    }

    void calculatePreferences() {
        vector<string> result(8);
        result[0] = question_1();
        result[1] = question_2();
        result[2] = question_3();
        result[3] = question_4();
        result[4] = question_5();
        result[5] = question_6();
        result[6] = question_7();
        result[7] = question_8();

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 15; k++) {
                int value = result[i][k] - '0';
                if (value == 1) {
                    ve[k] += (1.0 / 8);
                }
            }
        }
        double max_value = *max_element(ve.begin(), ve.end());
        for (int i = 0; i < ve.size(); i++) {
            {
                cout << pizzas[i] << " - " << ve[i] << "\n";
            }
        }
        cout << "Вам подходят пиццы: ";
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i] == max_value) {
                cout << pizzas[i] << " ";
            }
        }
    }
};


int main()
{
    setlocale(LC_ALL, "RU");
    Pizza myPizza;
    myPizza.calculatePreferences(); // вызов опроса
}
