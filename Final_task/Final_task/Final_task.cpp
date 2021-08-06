#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//独自のクラスの定義
class Uma {
public:
    Uma(){}
    void setName(std::string name){ _name = name;  }
    void setWin(int win){ _win = win; }
    void setG1win(int g1win) { _g1win = g1win; }
    void show() { std::cout << "馬名：" << _name << "\t通算勝利数：" << _win << "\tG1勝利数：" << _g1win << std::endl; }
private:
    std::string _name;
    int _win;
    int _g1win;
};

//独自の関数の定義
void g1winNum(int a) {
    if (a == 0) std::cout << "ハルウララ" << std::endl;
    if (a == 1) std::cout << "マルゼンスキー" << std::endl;
    if (a == 2) std::cout << "エアグルーヴ、サクラバクシンオー" << std::endl;
    if (a == 3) std::cout << "ライスシャワー" << std::endl;
    if (a == 4) std::cout << "ダイワスカーレット" << std::endl;
    if (a == 5) std::cout << "ナリタブライアン、タイキシャトル" << std::endl;
    if (a == 6) std::cout << "ゴールドシップ" << std::endl;
    if (a == 7) std::cout << "ウオッカ" << std::endl;
}

using namespace std;

int main() {
    cout << "リスト内の馬のデータは以下の通り" << endl;

    vector<Uma> seiseki;

    ifstream infile("hozon_uma.txt");
    int win, g1win;
    string name;
    while (infile >> name >> win >> g1win) {
        seiseki.emplace_back();
        seiseki[seiseki.size() - 1].setName(name);
        seiseki[seiseki.size() - 1].setWin(win);
        seiseki[seiseki.size() - 1].setG1win(g1win);
    }
    infile.close();

    for (int i = 0; i < seiseki.size(); i++) seiseki[i].show();

    vector<int> v{ 6,2,1,5,0,2,4,7,3,5 };
    auto minmaxIter = minmax_element(v.cbegin(), v.cend()); //イテレータの使用
    cout << "\nリスト内の馬でG1最多勝利数は" << *minmaxIter.second << endl;

    cout << "\nその勝利数をあげたリスト内の馬名は" << endl;
    g1winNum(7);

    cout << "\nリスト内の馬でG1最低勝利数は" << *minmaxIter.first << endl;

    cout << "\nその勝利数をあげたリスト内の馬名は" << endl;
    g1winNum(0);
}
