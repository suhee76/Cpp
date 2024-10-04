#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player {
public:
    string name;
    Player();
    ~Player() { }
};

Player::Player() {
    name = "";
}

class GamblingGame {
public:
    GamblingGame(Player& p1, Player& p2);
};

GamblingGame::GamblingGame(Player& p1, Player& p2) {
    cout << p1.name << ":<Enter>";
    cin.get(); // 사용자 입력 대기

    random_device rd;  // 시드 생성을 위한 랜덤 장치
    mt19937 gen(rd()); // Mersenne Twister 엔진
    uniform_int_distribution<int> dis(0, 2); // 0~2 범위의 정수 분포

    // 첫 번째 플레이어의 턴
    while (true) {
        int num[3];
        for (int i = 0; i < 3; i++) {
            num[i] = dis(gen); // 0~2까지 랜덤 정수 저장
        }

        cout << "\t\t" << num[0] << "\t" << num[1] << "\t" << num[2] << "\t";

        // 승리 조건 체크
        if (num[0] == num[1] && num[0] == num[2]) {
            cout << p1.name << "님 승리!!" << endl;
            break;
        }
        else {
            cout << "아쉽군요!" << endl;

            // 턴을 바꾸기 위해 이름을 업데이트
            swap(p1, p2); // 두 플레이어의 턴을 바꿈
            cout << p1.name << ":<Enter>"; // 다음 플레이어의 턴 안내
            cin.get(); // 사용자 입력 대기
        }
    }
}

int main() {
    Player* player = new Player[2];
    cout << "***** 갬블링 게임을 시작합니다. *****" << endl;

    cout << "첫번째 선수 이름>>";
    getline(cin, player[0].name, '\n');
    cout << "두번째 선수 이름>>";
    getline(cin, player[1].name, '\n');

    GamblingGame game(player[0], player[1]);

    delete[] player; // 객체 배열 소멸
}
